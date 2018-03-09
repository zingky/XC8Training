#include <pic.h>

#include "mcc_generated_files/mcc.h"

void main(void)
{
    SYSTEM_Initialize();

    while(1)
    {
        CS2_SetLow();
        SPI_Exchange8bit(0xAA);
        CS2_SetHigh();
        
        CS1_SetLow();
        SPI_Exchange8bit(0x00);
        CS1_SetHigh();
        
        __delay_ms(1000);
        
        CS2_SetLow();
        SPI_Exchange8bit(0x00);
        CS2_SetHigh();
        
        CS1_SetLow();
        SPI_Exchange8bit(0xAA);
        CS1_SetHigh();
        
        __delay_ms(1000);
    }
}