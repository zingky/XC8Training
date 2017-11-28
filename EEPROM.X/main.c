#include "mcc_generated_files/mcc.h"
#include "Buttons.h"
#include "TextLCD.h"
#include "EE24AA.h"
#include "MSSP_I2C_Master.h"

button_t COUNT;
uint8_t str[17];

void main(void)
{
    uint8_t count;
    SYSTEM_Initialize();
    I2C_Init();
    Button_Init(&COUNT);
    TextLCD_Init();
    count=EXT_EEPROM_ReadByte(0x00);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    while(1)
    {
        if(BT_Is_Pressed(&COUNT, BT_GetValue(), L2H, 100))
        {
            count++;
            EXT_EEPROM_WriteByte(0x00, count);
            sprintf(str, "count=%03d", count);
            TextLCD_Puts(0, 0, str, 0);
        }
    }
}