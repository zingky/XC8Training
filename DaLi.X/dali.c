#include "dali.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"

uint16_t Dali_Manchester_Code(uint8_t data)
{
    uint8_t i;
    uint16_t res=0;
    for(i=0; i<7; i++)
    {
        res<<=2;
        if(data&0x80) res|=0x10;
        else res|=0x01;
        data>>=1;
    }
    return res;
}

uint8_t Dali_Manchester_Decode(uint16_t data)
{
    uint8_t i;
    uint8_t res=0;
    for(i=0; i<16; i++)
    {
        res<<=1;
        if((data&0x1000)==0x1000) res|=1;
        else res|=0;
        data<<=2;
    }
    return res;
}

void Dali_Make_Frame(uint8_t addr, uint8_t cmd, uint8_t *frameout)
{
    uint8_t temp1=0x80|(addr&0x7F);
    uint16_t temp2=Dali_Manchester_Code(temp1);//[1 Start Bit][7 Address bits]
    frameout[0]=(uint8_t)(temp2>>8);
    frameout[1]=(uint8_t)temp2;
    temp1=0x80|(data>>1);//[1 Start Bit][7 CMD MSB bits]
    temp2=Dali_Manchester_Code(temp1);
    frameout[2]=(uint8_t)(temp2>>8);
    frameout[3]=(uint8_t)temp2;
    temp1=data<<7;
    temp2=Dali_Manchester_Code(temp1);
    temp2&=0xFFFF;
    frameout[4]=(uint8_t)(temp2>>8);
}

void Dali_Putc(uint8_t c)
{
    DALI.TXD=c;
    TMR0_Start();
    while(DALI.busy);
    TMR0_Stop();
}

uint8_t Dali_Getc()
{
    if(DALI.RXR) return DALI.RXD;
    else return 0;
}

void Dali_Physic_Xfer()
{
    if(DALI.bitCount<8)
    {
        DALI.RXD<<=1;
        DALI.RXD|=DLRX_GetValue();
        DLTX_LAT=(DALI.TXD&0x80)?0x80:1,0;
        DALI.TXD>>=1;
        DALI.bitCount++;
    }
    if(DALI.bitCount==8)
    {
        DLTX_LAT=1;
        DALI.busy=0;
        DALI.bitCount=9;
    }
}

void Dali_Init()
{
    TMR0_Stop();
    DLTX_LAT=1;
    DALI.RXD=0x00;
    DALI.TXD=0xFF;
    DALI.busy=0;
    DALI.bitCount=0;
}