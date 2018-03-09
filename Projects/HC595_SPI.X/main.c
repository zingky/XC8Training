#include "mcc_generated_files/mcc.h"

void main(void)
{
    SYSTEM_Initialize();

    while(1)
    {
        //        nCS1_SetLow();
        //        SPI_Exchange8bit(0xAA);
        //        nCS1_SetHigh();
        //
        //        nCS2_SetLow();
        //        SPI_Exchange8bit(0x00);
        //        nCS2_SetHigh();
        //
        //        __delay_ms(1000);
        //
        //        nCS1_SetLow();
        //        SPI_Exchange8bit(0x00);
        //        nCS1_SetHigh();
        //
        //        nCS2_SetLow();
        //        SPI_Exchange8bit(0xAA);
        //        nCS2_SetHigh();
        //
        //        __delay_ms(1000);

        nCS1_SetLow();
        SPI_Exchange8bit(0x00);
        SPI_Exchange8bit(0xAA);
        nCS1_SetHigh();

        __delay_ms(1000);

        nCS1_SetLow();
        SPI_Exchange8bit(0xAA);
        SPI_Exchange8bit(0x00);
        nCS1_SetHigh();

        __delay_ms(1000);
    }
}