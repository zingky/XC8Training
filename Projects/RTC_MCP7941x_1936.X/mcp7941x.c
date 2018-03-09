#include "mcp7941x.h"
#include "MSSP_I2C_Master.h"

void RTC_Write(uint8_t address, uint8_t data)
{
    I2C_Start();
    I2C_Write(0xDE);
    I2C_Write(address);
    I2C_Write(data);
    I2C_Stop();
}

uint8_t RTC_Read(uint8_t address)
{
    I2C_Start();
    I2C_Write(0xDE);
    I2C_Write(address);
    I2C_Start();
    I2C_Write(0xDF);
    uint8_t data=I2C_Read(false);
    I2C_Stop();
    return (data);
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
    I2C_Init();
    
    RTC_Write(RTC_CONTROL, 0x40);
    RTC_Write(RTC_OSC, trim);
    date_time[RTC_WKDAY]=0x20&RTC_Read(RTC_WKDAY);
    if(date_time[RTC_WKDAY]!=0x20) RTC_Set_DateTime(1, 1, 16, 6, 0, 0, 0, 1);
}