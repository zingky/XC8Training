#include "AT25F.h"
#include "mcc_generated_files/spi.h"
#include "mcc_generated_files/pin_manager.h"
#include "Tick_Timer.h"

uint8_t sstCMD[6];

/* [Chip select On/Off=1/0][data buffer][write length][read length][Chip select On/Off=1/0] */
void SPI_Xfer(bool enCS, uint8_t *data, uint8_t lenIn, uint8_t lenOut, bool dnCS)
{
    uint8_t i;
    if(enCS) AT_nCS_SetLow();
    for(i=0; i<lenIn; i++) SPI_Exchange8bit(data[i]);
    for(i=0; i<lenOut; i++) data[i]=SPI_Exchange8bit(0xFF);
    if(dnCS) AT_nCS_SetHigh();
}

void AT_Enable_Write()// Private function
{
    sstCMD[0]=AT_WRITE_EN;
    SPI_Xfer(1, sstCMD, 1, 0, 1);
}

void AT_Disable_Write()// Private function
{
    sstCMD[0]=AT_WRITE_DIS;
    SPI_Xfer(1, sstCMD, 1, 0, 1);
}

uint8_t AT_Read_Status()// Private function
{
    sstCMD[0]=AT_READ_STATUS;
    SPI_Xfer(1, sstCMD, 1, 1, 1);
    return sstCMD[0];
}

void AT_Write_Status(uint8_t stt)// Private function
{
    sstCMD[0]=AT_WRITE_STATUS;
    sstCMD[1]=stt;
    SPI_Xfer(1, sstCMD, 2, 0, 1);
}

void AT_Check_Busy()// Private function
{
    while(AT_Read_Status()&0x01);
}

void AT_Make_Address(uint32_t address)// Private function
{
    sstCMD[1]=(uint8_t) (address>>16);
    sstCMD[2]=(uint8_t) (address>>8);
    sstCMD[3]=(uint8_t) address;
}

void AT_Chip_Erase()// Public function
{
    AT_Enable_Write();
    sstCMD[0]=AT_BULK_ERASE;
    SPI_Xfer(1, sstCMD, 1, 0, 1);
    AT_Check_Busy();
}

void AT_Sector_Erase(uint32_t BAddr)// Public function
{
    AT_Enable_Write();
    sstCMD[0]=AT_SECTOR_ERASE;
    AT_Make_Address(BAddr);
    SPI_Xfer(1, sstCMD, 4, 0, 1);
    AT_Check_Busy();
}

void AT_Read_nByte(uint32_t BAddr, uint32_t len, uint8_t *buffer)// Public function
{
    AT_Check_Busy();
    sstCMD[0]=AT_READ_DATA;
    AT_Make_Address(BAddr);
    sstCMD[4]=0x00;
    SPI_Xfer(1, sstCMD, 5, 0, 0);
    SPI_Xfer(0, buffer, 0, len, 1);
}

void AT_Write_Byte(uint32_t Addr, uint8_t data)// Public function
{
    AT_Check_Busy();
    AT_Enable_Write();
    sstCMD[0]=AT_BYTE_PROG;
    AT_Make_Address(Addr);
    sstCMD[4]=data;
    SPI_Xfer(1, sstCMD, 5, 0, 1);
    AT_Disable_Write();
}

void AT_Write_nByte(uint32_t BAddr, uint16_t len, uint8_t *data)
{
    uint8_t temp;
    uint8_t idx;
    uint8_t state=0;
    uint32_t EAddr; // End address where is the last data byte will be written
    uint32_t ESec; // End address of a sector
    uint32_t BWAddr; // Begin writing address of current sector
    uint32_t i, j;

    while(1)
    {
        CLRWDT();
        switch(state)
        {
            case 0:// Calculate end address 
                EAddr=BAddr+len;
                BWAddr=BAddr;
                state=1;
                break;

            case 1:// Check blank
                state=4;
                ESec=SECTOR_LENGTH*((BWAddr/SECTOR_LENGTH)+1); // Calculate start address of the next sector
                for(i=BWAddr; (i<ESec)&&(i<EAddr); i++)
                {
                    AT_Read_nByte(i, 1, &temp[0]);
                    if(temp[0]==0xFF)
                    {
                        AT_Write_Byte(i, *data++);
                        BAddr++;
                        BWAddr=BAddr;
                    }
                    else
                    {
                        state=2;
                        break;
                    }
                }
                break;

            case 2:
                AT_Sector_Erase(TEMP_BGN_ADDR); // Erase backup sector
                i=BWAddr&0xFFFF000;
                for(j=TEMP_BGN_ADDR; j<SECTOR_LENGTH; j+=BUF_LEN)// Copy all data in present sector to backup sector
                {
                    AT_Read_nByte(i, BUF_LEN, &temp[0]);
                    AT_Write_AAI(j, BUF_LEN, &temp[0]);
                    i+=BUF_LEN;
                }
                AT_Sector_Erase(BWAddr); // Erase current sector
                state=3;
                break;

            case 3:
                i=BWAddr&0xFFFF000;
                for(j=TEMP_BGN_ADDR; j<SECTOR_LENGTH;)// Copy all data in backup sector to current sector
                {
                    for(idx=0; idx<BUF_LEN; idx++)
                    {
                        if(((i+idx)>=BAddr)&&((i+idx)<EAddr)) temp[idx]=*data++;//AT_Write_Byte(i, *data++);
                        else AT_Read_nByte(j, 1, &temp[idx]);
                        j++;
                    }
                    AT_Write_AAI(i, BUF_LEN, &temp[0]);
                    i+=BUF_LEN;
                }
                state=4;
                break;

            case 4:
                BWAddr=i;
                if(BWAddr<EAddr) state=1;
                else return;
                break;

            default:
                return;
        }
    }
}

void AT_Protect(sst_protect_range_t range)// Private function
{
    AT_Enable_Write();
    sstCMD[0]=AT_WRITE_STATUS;
    sstCMD[1]=FLASH_PROTECT_UNLOCK;
    SPI_Xfer(1, sstCMD, 2, 0, 1);
    AT_Enable_Write();
    sstCMD[0]=range|FLASH_PROTECT_LOCK;
    SPI_Xfer(1, sstCMD, 1, 0, 1);
}

bool AT_Init()// Public function
{
    uint8_t tryTimes=0;
LOOP:
    sstCMD[0]=AT_READ_JDECID;
    SPI_Xfer(1, sstCMD, 1, 1, 1);
    if(sstCMD[0]!=0x1F)// ATMEL JDEC ID is always 0xBF25xx
    {
        if(++tryTimes==0) return 1; // Try 256 times after return error
        goto LOOP;
    }
    AT_Write_Status(0);
    return 0;
}