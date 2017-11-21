#include "mcc_generated_files/mcc.h"
#include "mcp7941x.h"
#include "TextLCD.h"

void main(void)
{
    SYSTEM_Initialize();
    __delay_ms(100);
    RTC_Init(0);
    TextLCD_Init();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    while(1)
    {
        CLRWDT();
        if(rtc_flag)
        {
            uint8_t string[32];
            RTC_Get_DateTime();
            sprintf(string, "%02d.%02d.20%02d", date_time[RTC_DATE], date_time[RTC_MTH], date_time[RTC_YEAR]);
            TextLCD_Puts(0, 3, string, 0);
            sprintf(string, "%02d:%02d:%02d", date_time[RTC_HOUR], date_time[RTC_MIN], date_time[RTC_SEC]);
            TextLCD_Puts(1, 4, string, 0);
            rtc_flag=false;
        }
    }
}