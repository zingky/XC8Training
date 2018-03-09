#include "MSSP_I2C_Master.h"
#include "mcc_generated_files/mcc.h"

bool restart;

void I2C_Wait()
{
    while((SSPSTAT&0x04)||(SSPCON2&0x1F)); //Transmit is in progress
}

void I2C_Start()
{
    if(restart)// Repeat start bit
    {
        SSPCON2bits.RSEN=1; //Initiate repeated start condition
        I2C_Wait(); // Wait until START condition is over
    }
    else// 1st start bit
    {
        restart=1;
        SSPCON2bits.SEN=1; //Initiate start condition
        I2C_Wait(); // Wait until START condition is over
    }
}

void I2C_Stop()
{
    SSPCON2bits.PEN=1; //Initiate stop condition
    restart=0;
    I2C_Wait(); // Wait until START condition is over
}

uint8_t I2C_Read(bool ack)
{
    unsigned short temp;
    SSPCON2bits.RCEN=1;
    I2C_Wait();
    temp=SSPBUF; //Read data from SSPBUF
    I2C_Wait();
    SSPCON2bits.ACKDT=(ack)?0:1; //Acknowledge bit
    SSPCON2bits.ACKEN=1; //Acknowledge sequence
    I2C_Wait(); // Wait until START condition is over
    return temp;
}

void I2C_Write(uint8_t data_out)
{
    SSPBUF=data_out; //Write data to SSPBUF
    I2C_Wait();
}

void I2C_Init()
{
    restart=0;
    SCL_SetDigitalInput();
    SDA_SetDigitalInput();
    SSPSTAT=0;
    SSPCON2=0x00;
    SSPCON3=0x00;
    // SCL pin clock frequency = FOSC/(4*SSPAD)-1
    SSPADD=19; //400KHz
    SSPCON1=0b00101000; //SSP Module as Master
}