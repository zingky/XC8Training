#include "mcc_generated_files/mcc.h"

void decode(uint8_t num)
{
    uint8_t temp=num/10;
    num%=10;
    LATC=(temp<<4)|num;
}

void main(void)
{
    uint8_t count;
    uint8_t next=0;
    SYSTEM_Initialize();
    while(1)
    {
        switch(next)
        {
            case 0:
                GRN_SetHigh();
                YEL_SetLow();
                RED_SetLow();
                count=60;
                next=1;
                break;

            case 1:
                GRN_SetLow();
                YEL_SetHigh();
                RED_SetLow();
                count=6;
                next=2;
                break;

            case 2:
                GRN_SetLow();
                YEL_SetLow();
                RED_SetHigh();
                count=56;
                next=0;
                break;

            default:
                break;
        }
        while(count--)
        {
            decode(count);
            __delay_ms(1000);
        }
    }
}