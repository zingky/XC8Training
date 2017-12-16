#include "mcc_generated_files/mcc.h"
#include "TextLCD.h"

uint16_t GetKey()
{
    static uint8_t rowcode[4]={0x7F, 0xBF, 0xDF, 0xEF};
    static uint16_t prv_state=0xFFFF;
    uint16_t pre_state;
    uint8_t row;

    for(row=0, pre_state=0xFFFF; row<4; row++)
    {
        TRISB=rowcode[row];
        LATB=rowcode[row];
        pre_state<<=4;
        pre_state|=(uint16_t) (PORTB&0x0F);
    }
    if(prv_state!=pre_state)
    {
        prv_state=pre_state;
        return prv_state;
    }
    return 0xFFFF;
}

void main(void)
{
    uint8_t str[17];
    SYSTEM_Initialize();
    TextLCD_Init();
    TextLCD_Puts(0, 0, (uint8_t *) "Get key code", 0);
    while(1)
    {
        uint16_t keyCode=GetKey();
        if(keyCode!=0xFFFF)
        {
            sprintf(str, "%04X", keyCode);
            TextLCD_Puts(1, 0, str, 0);
        }
    }
}