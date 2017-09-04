#include "mcc_generated_files/mcc.h"
#include "TextLCD.h"

void main(void)
{
    SYSTEM_Initialize();
    TextLCD_Init();
    TextLCD_Puts(0, 1, (uint8_t *)"16-Bit Counter", 0);
    while (1)
    {
        static uint16_t prv_count=1;
        uint16_t pre_count=TMR1_ReadTimer();
        if(prv_count!=pre_count)
        {
            uint8_t str[16];
            prv_count=pre_count;
            sprintf(str, "count=%05d", pre_count);
            TextLCD_Puts(1, 0, str, 0);
        }
    }
}