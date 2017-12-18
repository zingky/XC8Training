#include "SST25VF.h"
#include "SPI.h"
#include "DataConvert.h"
#include "UART.h"

#define SST25VF020B                                                             // 2Mbit Flash  <-------------------- User can redefine this line
//#define SST25PF040B                                                             // 4Mbit Flash  <-------------------- User can redefine this line

/* **********************************************Please to read these documents:
 * http://ww1.microchip.com/downloads/en/DeviceDoc/S71417_03.pdf
 * http://ww1.microchip.com/downloads/en/DeviceDoc/20005051C.pdf
 ******************************************************************************/

// MAX_MEM_ADDR=(Capacity in Mbit *1024^2)/8 - 1 (address start at 0)
#define SECTOR_LENGTH   4096
#define PAGE_LENGTH     256
#define PAGE_IN_SECTOR  16
#if defined(SST25PF040B)
#define MAX_MEM_ADDR    0x7FFFF                                                                                                   
#elif defined(SST25VF020B)
#define MAX_MEM_ADDR    0x3FFFF                                                 
#else
#warning "Please define your flash memory"
#endif

/*********************************************************************COMMANDS*/
#define SST_READ_DATA        0x03
#define SST_FAST_READ_DATA   0x0B
#define SST_SECTOR_ERASE     0x20
#define SST_SECTOR_32_ERASE  0x52
#define SST_SECTOR_64_ERASE  0xD8
#define SST_BULK_ERASE       0xC7
#define SST_BYTE_PROG        0x02
#define SST_WORD_PROG        0xAD
#define SST_READ_STATUS      0x05
#define SST_WRITE_STATUS_EN  0x50
#define SST_WRITE_STATUS     0x01
#define SST_WRITE_EN         0x06
#define SST_WRITE_DIS        0x04
#define SST_READ_JDECID      0x9F
#define SST_HW_WR_STATUS     0x70
#define SST_POLL_WR_STATUS   0x80
#define FLASH_PROTECT_LOCK   0x80
#define FLASH_PROTECT_UNLOCK 0x00

uint8_t __attribute__ ((coherent, aligned(4))) sstBUF[SECTOR_LENGTH];
uint8_t sstCMD[6];

void SST_Enable_Write()// Private function
{
    sstCMD[0]=SST_WRITE_EN;
    SPI2_Xfer(1, sstCMD, 1, 0, 1);
}

void SST_Disable_Write()// Private function
{
    sstCMD[0]=SST_WRITE_DIS;
    SPI2_Xfer(1, sstCMD, 1, 0, 1);
}

void SST_Poll_WR_Status()// Private function
{
    sstCMD[0]=SST_POLL_WR_STATUS;
    SPI2_Xfer(1, sstCMD, 1, 0, 1);
}

uint8_t SST_Read_Status()// Private function
{
    sstCMD[0]=SST_READ_STATUS;
    SPI2_Xfer(1, sstCMD, 1, 1, 1);
    return sstCMD[0];
}

void SST_Write_Status(uint8_t stt)// Private function
{
    sstCMD[0]=SST_WRITE_STATUS_EN;
    SPI2_Xfer(1, sstCMD, 1, 0, 1);
    sstCMD[0]=SST_WRITE_STATUS;
    sstCMD[1]=stt;
    SPI2_Xfer(1, sstCMD, 2, 0, 1);
}

void SST_Check_Busy()// Private function
{
    while(SST_Read_Status()&0x01);
}

void SST_Make_Address(uint32_t address)// Private function
{
    sstCMD[1]=(uint8_t)(address>>16);
    sstCMD[2]=(uint8_t)(address>>8);
    sstCMD[3]=(uint8_t)address;
}

void SST_Chip_Erase()// Public function
{
    SST_Enable_Write();
    sstCMD[0]=SST_BULK_ERASE;
    SPI2_Xfer(1, sstCMD, 1, 0, 1);
    SST_Check_Busy();
}

void SST_Sector_Erase(uint32_t BAddr)// Public function
{
    SST_Enable_Write();
    sstCMD[0]=SST_SECTOR_ERASE;
    SST_Make_Address(BAddr);
    SPI2_Xfer(1, sstCMD, 4, 0, 1);
    SST_Check_Busy();
}

void SST_Read_nByte(uint32_t BAddr, uint32_t len, uint8_t *buffer)// Public function
{
    SST_Check_Busy();
    sstCMD[0]=SST_FAST_READ_DATA;
    SST_Make_Address(BAddr);
    sstCMD[4]=0x00;
    SPI2_Xfer(1, sstCMD, 5, 0, 0);
    SPI2_Xfer(0, buffer, 0, len, 1);
}

void SST_Write_Byte(uint32_t Address, uint8_t data)// Private function
{
    SST_Check_Busy();
    SST_Enable_Write();
    sstCMD[0]=SST_BYTE_PROG;
    SST_Make_Address(Address);
    sstCMD[4]=data;
    SPI2_Xfer(1, sstCMD, 5, 0, 1);
    SST_Disable_Write();
}

void SST_Write_nByte(uint32_t BAddr, uint16_t len, uint8_t *data)// Public function
{
    uint32_t i;
    uint32_t EAddr;// End-data address
    uint32_t BSect;// Begin-sector address
    uint32_t ESect;// End-sector address
    uint16_t byteIdx; // Index of begin data in sector
    uint16_t len1;// Backup data len
    uint16_t offset;
    uint8_t c;
    uint8_t next=0;// Next state to do
    
    while(next<5)
    {
        switch(next)
        {
            // Init
            case 0:
                EAddr=BAddr+len-1;// End-data address=Begin-data address+ data len -1
                BSect=BAddr&0xFFFFF000;// Begin-sector address
                ESect=BAddr|0x00000FFF;// End-sector address
                if(ESect<EAddr)// Data locates in more than 1 sector
                {
                    len1=len;// Backup data len
                    EAddr=ESect;
                    len=EAddr-BAddr+1;// New len=End-sector address-Begin-data address+1
                }
                else len1=0;
                next=1;
                break;
            // Check from start-address to end-address, if any byte is not equal to 0xFF,
            // copy all data in this sector to buffer; if not, skip this step.
            case 1:
                for(i=BAddr; i<(EAddr+1); i++)
                {
                    SST_Read_nByte(i, 1, &c);// Read 1 byte in sector
                    if(c!=0xFF) 
                    {
                        next=2;
                        break;
                    }
                }
                if(next==1) next=3;
                break;
            // Copy all data in sector to buffer then erase sector.
            case 2:
                for(i=BSect; i<(ESect+1); i++)
                {
                    byteIdx=(uint16_t)(i&0xFFF);
                    if((i>=BAddr)&&(i<=EAddr)) sstBUF[byteIdx]=*data++;// Copy new data to buffer of sector
                    else SST_Read_nByte(i, 1, &sstBUF[byteIdx]);// Read 1 byte in sector, save to buffer
                }
                BAddr=BSect;
                len=SECTOR_LENGTH;
                SST_Sector_Erase(BSect);// Erase sector
                next=4;
                break;
            // Write the odd data
            case 3:
                for(i=0; i<len; i++) sstBUF[i]=*data++;
                next=4;
                break;
            // Write data to sector
            case 4:
                offset=0;
                c=(uint8_t)(((BAddr&0x01)<<1)|(len&0x01));
                switch(c)
                {
                    case 0://BAddr:len=even:even
                        break;
                        
                    case 1://BAddr:len=even:odd
                        SST_Write_Byte(EAddr, sstBUF[--len]);
                        break;
                        
                    case 2://BAddr:len=odd:even
                        SST_Write_Byte(BAddr, sstBUF[0]);
                        SST_Write_Byte(EAddr, sstBUF[--len]);
                        BAddr++;
                        len--;
                        offset=1;
                        break;
                        
                    case 3://BAddr:len=odd:odd
                        SST_Write_Byte(BAddr, sstBUF[0]);
                        BAddr++;
                        len--;
                        offset=1;
                        break;
                        
                    default:
                        break;
                }
                // Auto Address Increment (AAI) Word-Program
                SST_Check_Busy();
                SST_Enable_Write();
                sstCMD[0]=SST_WORD_PROG;
                SST_Make_Address(BAddr);
                sstCMD[4]=sstBUF[offset];
                sstCMD[5]=sstBUF[offset+1];
                SPI2_Xfer(1, sstCMD, 6, 0, 1);
                SST_Check_Busy();
                for(i=offset+2; i<len; i+=2)
                {
                    sstCMD[0]=SST_WORD_PROG;
                    sstCMD[1]=sstBUF[i];
                    sstCMD[2]=sstBUF[i+1];
                    SPI2_Xfer(1, sstCMD, 3, 0, 1);
                    SST_Check_Busy();
                }
                SST_Disable_Write();
                
                if(len>0) 
                {
                    len=len1;
                    BAddr=ESect+1;
                    next=0;
                }
                else next=5;
                break;
                
            default:
                break;
        }
    }
}

void SST_Protect(sst_protect_range_t range)// Private function
{
    SST_Enable_Write();
    sstCMD[0]=SST_WRITE_STATUS;
    sstCMD[1]=FLASH_PROTECT_UNLOCK;
    SPI2_Xfer(1, sstCMD, 2, 0, 1);
    SST_Enable_Write();
    sstCMD[0]=range|FLASH_PROTECT_LOCK;
    SPI2_Xfer(1, sstCMD, 1, 0, 1);
}

bool SST_Init()// Public function
{
    uint8_t tryTimes=0;
    LOOP:
    SPI2_Init(10000000, 1);// 10Mbps, SPI mode 1 or 2
    sstCMD[0]=SST_READ_JDECID;
    SPI2_Xfer(1, sstCMD, 1, 3, 1);
    if((sstCMD[0]!=0xBF)||(sstCMD[1]!=0x25))// SST JDEC ID is always 0xBF25xx
    {
        if(++tryTimes==0) return 1;// Try 256 times after return error
        goto LOOP;
    }
    SST_Write_Status(0);
    return 0;
}