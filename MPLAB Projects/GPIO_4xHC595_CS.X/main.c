#include "mcc_generated_files/mcc.h"
// Toc do ghi cua cach nay la nhanh nhat, nhanh hon phuong phap Serial data
void HC595_Write_Idx(uint8_t idx, uint8_t data)
{
    uint8_t i;
    for(i=0; i<8; i++)
    {
        SHCP_SetLow();
        DS_LAT=((data&0x80)==0x80);
        SHCP_SetHigh();
        data<<=1;
    }
    switch(idx)
    {
        case 0:
            TSCP1_SetLow();
            TSCP1_SetHigh();
            break;
            
        case 1:
            TSCP2_SetLow();
            TSCP2_SetHigh();
            break;
            
        case 2:
            TSCP3_SetLow();
            TSCP3_SetHigh();
            break;
            
        case 3:
            TSCP4_SetLow();
            TSCP4_SetHigh();
            break;
            
        default: return;
    }
}

void main(void)
{
    SYSTEM_Initialize();
    while (1)
    {
        HC595_Write_Idx(0, 0xFF);
        HC595_Write_Idx(1, 0xF0);
        HC595_Write_Idx(2, 0x0F);
        HC595_Write_Idx(3, 0xAA);
        __delay_ms(1000);
        HC595_Write_Idx(0, 0);
        HC595_Write_Idx(1, 0);
        HC595_Write_Idx(2, 0);
        HC595_Write_Idx(3, 0);
        __delay_ms(1000);
    }
}