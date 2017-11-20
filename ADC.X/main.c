#include "mcc_generated_files/mcc.h"
#include "TextLCD.h"

uint8_t str[17];
float vol, temp;

void main(void)
{
    SYSTEM_Initialize();
    TextLCD_Init();
    while(1)
    {
        adc_result_t adc_value=ADC_GetConversion(VOLTAGE);
        vol=adc_value;
        vol*=5000;
        vol/=1023;
        
        adc_value=ADC_GetConversion(TEMP);
        temp=adc_value;
        temp*=500;
        temp/=1023;
        
        sprintf(str, "Vol=%.1f", vol);
        TextLCD_Puts(0, 0, str, 0);
        sprintf(str, "Temp=%.1f", temp);
        TextLCD_Puts(1, 0, str, 0);
        
        __delay_ms(100);
    }
}