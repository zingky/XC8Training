#include "mcc_generated_files/mcc.h"

void DemuxSetChannel(uint8_t ch)
{
    A_LAT=(bool)ch;
    ch>>=1;
    B_LAT=(bool)ch;
    ch>>=1;
    C_LAT=(bool)ch;
}

void main(void)
{
    SYSTEM_Initialize();

    while (1)
    {
        uint8_t i;
        for(i=0; i<8; i++)
        {
            DemuxSetChannel(i);
            __delay_ms(500);
        }
    }
}