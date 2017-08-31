#include "mcc_generated_files/mcc.h"

#define NUM_OF_7219 4

const char dg[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};// Ma led 7 doan (am cuc chung)

void Max7219_Write(uint8_t idx, uint8_t addr, uint8_t data)
{
    bool loop_enable=0;
    uint8_t i;
    LOOP:
    switch(idx)
    {
        case 0:
            LOAD1_Toggle();
            break;

        case 1:
            LOAD2_Toggle();
            break;

        case 2:
            LOAD3_Toggle();
            break;

        case 3:
            LOAD4_Toggle();
            break;

        default:
            break;
    }
    
    if(loop_enable) return;
    
    for(i=0; i<8; i++)
    {
        CLK_SetLow();
        DIN_LAT=((addr&0x80)==0x80);
        CLK_SetHigh();
        addr<<=1;
    }
    
    for(i=0; i<8; i++)
    {
        CLK_SetLow();
        DIN_LAT=((data&0x80)==0x80);
        CLK_SetHigh();
        data<<=1;
    }
    
    loop_enable=1;
    goto LOOP;
}

void Max7219_Init()
{
    uint8_t i;
    LOAD1_SetHigh();
    LOAD2_SetHigh();
    LOAD3_SetHigh();
    LOAD4_SetHigh();
    CLK_SetLow();
    
    for(i=0; i<NUM_OF_7219; i++)
    {
        Max7219_Write(i, 0x0A, 0x03);// Intensity =9/32
        Max7219_Write(i, 0x0B, 0x07);// Scan limit 8 digits
        Max7219_Write(i, 0x0C, 0x01);// No shutdown
    }
}

void Max7129_Display(uint8_t idx, uint32_t num)
{
    uint8_t i;
    for(i=9; i>0; i--)
    {
        uint8_t temp=(uint8_t)(num%10);
        num/=10;
        Max7219_Write(idx, i-1, dg[temp]);
    }
}

void main(void)
{
    SYSTEM_Initialize();
    Max7219_Init();
    while(1)
    {
        Max7129_Display(0, 849);
        Max7129_Display(1, 2603775);
        Max7129_Display(2, 8412);
        Max7129_Display(3, 64065049);
        __delay_ms(5000);
        Max7129_Display(0, 0);
        Max7129_Display(1, 0);
        Max7129_Display(2, 0);
        Max7129_Display(3, 0);
        __delay_ms(1000);
    }
}