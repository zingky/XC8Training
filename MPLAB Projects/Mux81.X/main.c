#include "mcc_generated_files/mcc.h"

bool MuxReadChannel(uint8_t ch)
{
    A_LAT=(bool)ch;
    ch>>=1;
    B_LAT=(bool)ch;
    ch>>=1;
    C_LAT=(bool)ch;
    
    return Y_GetValue();
}

uint8_t Mux81()
{
    uint8_t res=0;
    int8_t i;
    for(i=7; i>-1; i--)
    {
        res<<=1;
        res|=MuxReadChannel(i);
    }
    return res;
}

void main(void)
{
    SYSTEM_Initialize();
    TRISC=0;// Port C is an output port
    while (1)
    {
        LATC=Mux81();
    }
}