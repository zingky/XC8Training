#include "mcc_generated_files/mcc.h"
#include "TextLCD.h"

void TextLCD_4Bits_Write(uint8_t nib)
{
    D4_LAT=(bool)nib;
    nib>>=1;
    D5_LAT=(bool)nib;
    nib>>=1;
    D6_LAT=(bool)nib;
    nib>>=1;
    D7_LAT=(bool)nib;
}

void TextLCD_Enable()
{
    EN_LAT=1;
    __delay_us(3);
    EN_LAT=0;
    __delay_us(50);
}

void TextLCD_CMD(uint8_t cmd)
{
    TextLCD_4Bits_Write(cmd>>4);
    TextLCD_Enable();
    TextLCD_4Bits_Write(cmd);
    TextLCD_Enable();
}

void TextLCD_PutChar(uint8_t data)
{
    RS_LAT=1;
    TextLCD_CMD(data);
    RS_LAT=0;
}

void TextLCD_Puts(uint8_t line, uint8_t idx, uint8_t *data, uint8_t length_or_type)
{
    const uint8_t DDRAM_Start_Address[4]={0x80, 0xC0, 0x90, 0xD0};
    line&=0b11;                                                                 // Max line index=3
    idx&=0b1111;                                                                // Max idx index=15
    uint8_t address=DDRAM_Start_Address[line]+idx;
    TextLCD_CMD(address);
    __delay_us(50);

    if(length_or_type==0) while(*data!=0) TextLCD_PutChar(*data++);
    else for(address=0; address<length_or_type; address++) TextLCD_PutChar(*data++);
}

void TextLCD_Clear()
{
    TextLCD_CMD(0x01);
    __delay_ms(2);
}
void TextLCD_Init()
{
    __delay_ms(40);
    TextLCD_4Bits_Write(0x03);
    TextLCD_Enable();
    __delay_ms(5);
    TextLCD_Enable();
    __delay_us(100);
    TextLCD_Enable();
    TextLCD_4Bits_Write(0x02);
    TextLCD_Enable();
    TextLCD_CMD(0x28);                                                              
    TextLCD_CMD(0x0c);                                                              
    TextLCD_CMD(0x06);                                                               
    TextLCD_CMD(0x01);
    __delay_ms(100);
}