#include "mcp7941x.h"
#include "mcc_generated_files/mcc.h"

uint8_t dat[2];
I2C_MESSAGE_STATUS WStt, RStt;

void RTC_Write(uint8_t address, uint8_t data)
{
    //    I2C_Start();
    //    I2C_Write(0xDE);
    //    I2C_Write(address);
    //    I2C_Write(data);
    //    I2C_Stop();
    dat[0]=address;
    dat[1]=data;
    do
    {
        CLRWDT();
        I2C_MasterWrite(dat, 2, 0xDE, &WStt);
        __delay_ms(1);
    }
    while(WStt!=I2C_MESSAGE_COMPLETE);
}

uint8_t RTC_Read(uint8_t address)
{
    uint8_t data;
    //    I2C_Start();
    //    I2C_Write(0xDE);
    //    I2C_Write(address);
    //    I2C_Start();
    //    I2C_Write(0xDF);
    //    data=I2C_Read(false);
    //    I2C_Stop();

    dat[0]=address;
    do
    {
        CLRWDT();
        I2C_MasterWrite(dat, 1, 0xDE, &WStt);
        while(WStt == I2C_MESSAGE_PENDING);
    }
    while(WStt!=I2C_MESSAGE_COMPLETE);

    do
    {
        CLRWDT();
        I2C_MasterRead(data, 1, 0xDF, &RStt);
        while(RStt == I2C_MESSAGE_PENDING);
    }
    while(RStt!=I2C_MESSAGE_COMPLETE);

    return data;
}

uint8_t int2bcd(uint8_t data)
{
    uint8_t nibh=data/10;
    uint8_t nibl=data-(nibh*10);
    return ((nibh<<4)|nibl);
}

uint8_t bcd2int(uint8_t data)
{
    uint8_t i=data;
    data=(i>>4)*10;
    data=data+(i&0x0F);
    return data;
}

void RTC_Set_DateTime(uint8_t day, uint8_t mth, uint8_t year, uint8_t dow,
                      uint8_t hour, uint8_t min, uint8_t sec, bool leap)
{
    RTC_Write(RTC_YEAR, int2bcd(year));
    RTC_Write(RTC_MTH, int2bcd(mth)|(leap<<5));
    RTC_Write(RTC_DATE, int2bcd(day));
    RTC_Write(RTC_WKDAY, int2bcd(dow)|8);
    RTC_Write(RTC_HOUR, int2bcd(hour));
    RTC_Write(RTC_MIN, int2bcd(min));
    RTC_Write(RTC_SEC, int2bcd(sec)|0x80);
}

void RTC_Get_Date()
{
    date_time[RTC_YEAR]=bcd2int(RTC_Read(RTC_YEAR));
    date_time[RTC_MTH]=bcd2int(RTC_Read(RTC_MTH)&0x1f);
    date_time[RTC_DATE]=bcd2int(RTC_Read(RTC_DATE));
    date_time[RTC_WKDAY]=bcd2int(RTC_Read(RTC_WKDAY)&7);
}

void RTC_Get_Time()
{
    date_time[RTC_HOUR]=bcd2int(RTC_Read(RTC_HOUR));
    date_time[RTC_MIN]=bcd2int(RTC_Read(RTC_MIN));
    date_time[RTC_SEC]=bcd2int(RTC_Read(RTC_SEC)&0x7F);
}

void RTC_Init(int8_t trim)
{
    rtc_flag=0;
    RTC_Write(RTC_CONTROL, 0x40);
    RTC_Write(RTC_OSC, trim);
    date_time[RTC_WKDAY]=0x20&RTC_Read(RTC_WKDAY);
    if(date_time[RTC_WKDAY]!=0x20) RTC_Set_DateTime(1, 1, 16, 6, 0, 0, 0, 1);
}