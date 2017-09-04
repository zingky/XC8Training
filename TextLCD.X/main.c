#include "mcc_generated_files/mcc.h"
#include "TextLCD.h"

bool BT1_Is_Pressed()
{
    static bool lat=1;
    bool state=BT1_GetValue();
    if(lat!=state)
    {
        lat=state;
        if(lat) return 1;
    }
    return 0;
}

void main(void)
{
    SYSTEM_Initialize();
    TextLCD_Init();
    TextLCD_Puts(0, 0, (uint8_t *)"LCD1602", 0);
    while(1)
    {
        static uint8_t i;
        if(BT1_Is_Pressed())
        {
            uint8_t buffer[16];
            sprintf(buffer, "Count=%03d", i++);
            TextLCD_Puts(1, 5, buffer, 0);
            if(i>10)
            {
                TextLCD_ClearLine(1);
                i=0;
            }
        }
    }
}