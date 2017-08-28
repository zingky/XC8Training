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

    while(1)
    {
    }
}