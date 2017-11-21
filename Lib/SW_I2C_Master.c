#include "SW_I2C_Master.h"
#include "mcc_generated_files/mcc.h"
/*Common definations***********************************************************/
#define I2C_Delay() __delay_us(2)                                               //f=1/(2*2e-6)=250KHz
uint8_t i;

void I2C_Init()
{
    SW_SCL_SetHigh();
    SW_SDA_SetHigh();
    SW_SDA_SetDigitalOutput();
    SW_SCL_SetDigitalOutput();
}

void I2C_Start()
{
    SW_SDA_SetDigitalOutput();
    SW_SDA_SetHigh();
    SW_SCL_SetHigh();
    I2C_Delay();
    SW_SDA_SetLow();
    SW_SCL_SetLow();
}

void I2C_Stop()
{
    SW_SDA_SetDigitalOutput();
    SW_SCL_SetLow();
    SW_SDA_SetLow();
    SW_SCL_SetHigh();
    I2C_Delay();
    SW_SDA_SetHigh();
}

uint8_t I2C_Read(bool ack)
{
    uint8_t data_in=0x00;
    SW_SDA_SetDigitalInput();
    for(i=0; i<8; i++)
    {
        data_in<<=1;
        SW_SCL_SetHigh();
        I2C_Delay();
        data_in|=SW_SDA_GetValue();
        SW_SCL_SetLow();
        I2C_Delay();
    }
    SW_SDA_SetDigitalOutput();
    if(ack) SW_SDA_SetLow();
    else SW_SDA_SetHigh();
    I2C_Delay();
    SW_SCL_SetHigh();
    I2C_Delay();
    SW_SCL_SetLow();
    SW_SDA_SetLow();
    return data_in;
}

void I2C_Write(uint8_t data_out)
{
    SW_SDA_SetDigitalOutput();
    for(i=0; i<8; i++)
    {
        if(data_out&0x80) SW_SDA_SetHigh();
        else SW_SDA_SetLow();
        data_out<<=1;
        SW_SCL_SetHigh();
        I2C_Delay();
        SW_SCL_SetLow();
        I2C_Delay();
    }
    SW_SCL_SetHigh();
    I2C_Delay();
    SW_SCL_SetLow();
}