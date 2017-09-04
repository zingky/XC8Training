#ifndef TEXTLCD_H
#define	TEXTLCD_H
#include <stdio.h>
#define TextLCD_ClearLine(line) TextLCD_Puts(line, 0, (uint8_t *)"                ", 0)

void TextLCD_Init();
void TextLCD_Clear();
void TextLCD_Puts(uint8_t line, uint8_t idx, uint8_t *data, uint8_t length_or_type);

#endif