#include "mcc_generated_files/mcc.h"

//void Decode1(uint8_t num)
//{
//    A1_LAT=(bool)num;
//    num>>=1;
//    B1_LAT=(bool)num;
//    num>>=1;
//    C1_LAT=(bool)num;
//    num>>=1;
//    D1_LAT=(bool)num;
//}
//
//void Decode2(uint8_t num)
//{
//    A2_LAT=(bool)num;
//    num>>=1;
//    B2_LAT=(bool)num;
//    num>>=1;
//    C2_LAT=(bool)num;
//    num>>=1;
//    D2_LAT=(bool)num;
//}

void Decode(uint8_t num)
{
    uint8_t Hnibble, Lnibble;
    Hnibble=num/10;
    Lnibble=num%10;
    LATC=(Lnibble<<4)|Hnibble;
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        uint8_t i;
        for(i=0; i<100; i++)
        {
//            Decode1(i/10);//
//            Decode2(i%10);
            Decode(i);
            __delay_ms(100);
        }
    }
}