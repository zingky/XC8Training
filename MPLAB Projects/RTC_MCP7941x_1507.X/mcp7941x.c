#include "mcp7941x.h"
#include "SW_I2C_Master.h"
#include "mcc_generated_files/pin_manager.h"

uint8_t Byte2BCD(uint8_t data)
{
    uint8_t nibh=data/10;
    uint8_t nibl=data-(nibh*10);
    return ((nibh<<4)|nibl);
}

uint8_t BCD2Byte(uint8_t data)
{
    uint8_t i=data;
    data=(i>>4)*10;
    data=data+(i&0x0F);
    return data;
}

bool Leap_Year_Calc(uint16_t Year)// Year=0:65535
{
    bool leap=0;

    if((Year%4)==0)
    {
        if((Year%100)==0)
        {
            if((Year%400)==0) leap=1;
        }
        else leap=1;
    }
    return leap;
}

void MCP7941x_Write(uint8_t address, uint8_t data)
{
    I2C_Start();
    I2C_Write(0xDE);
    I2C_Write(address);
    I2C_Write(data);
    I2C_Stop();
}

uint8_t MCP7941x_Read(uint8_t address)
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

void MCP7941x_Set_Date(mcp7941x_date_t *pData)
{
    MCP7941x_Write(MCP7941x_YEAR, Byte2BCD((uint8_t) (pData->Year%100)));
    MCP7941x_Write(MCP7941x_MTH, Byte2BCD(pData->Month)
            |((uint8_t) Leap_Year_Calc(pData->Year)<<5));
    MCP7941x_Write(MCP7941x_DATE, Byte2BCD(pData->Date));
    MCP7941x_Write(MCP7941x_WKDAY, Byte2BCD(pData->DoWeek)|8);
}

void MCP7941x_Set_Time(mcp7941x_time_t *pData)
{
    MCP7941x_Write(MCP7941x_HOUR, Byte2BCD(pData->Hour));
    MCP7941x_Write(MCP7941x_MIN, Byte2BCD(pData->Minute));
    MCP7941x_Write(MCP7941x_SEC, Byte2BCD(pData->Second)|0x80);
}

void MCP7941x_Set_DateTime(mcp7941x_rtcc_t *pData)
{
    MCP7941x_Set_Date(&pData->Date);
    MCP7941x_Set_Time(&pData->Time);
}

void MCP7941x_Get_Date(mcp7941x_date_t *pData)
{
    pData->Year=2000+BCD2Byte(MCP7941x_Read(MCP7941x_YEAR));
    pData->Month=BCD2Byte(MCP7941x_Read(MCP7941x_MTH)&0x1F);
    pData->Date=BCD2Byte(MCP7941x_Read(MCP7941x_DATE));
    pData->DoWeek=BCD2Byte(MCP7941x_Read(MCP7941x_WKDAY)&7);
}

void MCP7941x_Get_Time(mcp7941x_time_t *pData)
{
    pData->Hour=BCD2Byte(MCP7941x_Read(MCP7941x_HOUR));
    pData->Minute=BCD2Byte(MCP7941x_Read(MCP7941x_MIN));
    pData->Second=BCD2Byte(MCP7941x_Read(MCP7941x_SEC)&0x7F);
}

void MCP7941x_Get_DateTime(mcp7941x_rtcc_t *pData)
{
    MCP7941x_Get_Date(&pData->Date);
    MCP7941x_Get_Time(&pData->Time);
}

volatile bool MFP;

volatile bool *MCP7941x_MFP(bool RW)
{
    if(RW)//Read
    {
        if(MFP)
        {
            MFP=0;
            return 1;
        }
    }
    else
    {
        MFP=1;
#if defined(MFP_STT_Toggle)
        MFP_STT_Toggle();
#endif
    }
    return 0;
}

void MCP7941x_Init(uint8_t trim, mcp7941x_sqwfs_t mfp_clk)
{
    uint8_t temp;
    MFP=0;
    I2C_Init();
    MCP7941x_Write(MCP7941x_CONTROL, mfp_clk);
    MCP7941x_Write(MCP7941x_OSC, trim);
    temp=MCP7941x_Read(MCP7941x_WKDAY);
    if((temp&0x20)!=0x20)
    {
        mcp7941x_rtcc_t Preset;
        Preset.Date.DoWeek=2;
        Preset.Date.Date=27;
        Preset.Date.Month=11;
        Preset.Date.Year=2017;

        Preset.Time.Hour=23;
        Preset.Time.Minute=59;
        Preset.Time.Second=50;

        MCP7941x_Set_DateTime(&Preset);
    }
}