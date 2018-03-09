#include "mcc_generated_files/mcc.h"
#include "mcp7941x.h"
#include "TextLCD.h"

typedef enum
{
    DEFAULT,
    APP_INIT,
    RTC_READ,
    PROCESS,
    LCD_WRITE
} task_t;

task_t Task;

uint8_t Str[17];

struct
{
    mcp7941x_rtcc_t Pres;
    mcp7941x_rtcc_t Prev;
} RTC;

void main(void)
{
    Task=APP_INIT;
    SYSTEM_Initialize();
    TextLCD_Init();
    TextLCD_Puts(0, 0, (uint8_t *) "MCP7941x TEST", 0);
    __delay_ms(500);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {
        CLRWDT();
        switch(Task)
        {
            case APP_INIT:
                MCP7941x_Init(0, _1Hz|H2L); // Trim=0, MFP signal=1Hz, active high
                RTC.Prev.Date.DoWeek=0;
                RTC.Prev.Date.Date=0;
                RTC.Prev.Date.Month=0;
                RTC.Prev.Date.Year=0;

                RTC.Prev.Time.Hour=0;
                RTC.Prev.Time.Minute=0;
                RTC.Prev.Time.Second=0;

                Task=RTC_READ;
                break;

            case RTC_READ:
                MCP7941x_Get_DateTime(&RTC.Pres);
                Task=PROCESS;
                break;

            case PROCESS:
                if(
                        (RTC.Prev.Time.Second!=RTC.Pres.Time.Second)||
                        (RTC.Prev.Time.Minute!=RTC.Pres.Time.Minute)||
                        (RTC.Prev.Time.Hour!=RTC.Pres.Time.Hour)||
                        (RTC.Prev.Date.DoWeek!=RTC.Pres.Date.DoWeek)||
                        (RTC.Prev.Date.Date!=RTC.Pres.Date.Date)||
                        (RTC.Prev.Date.Month!=RTC.Pres.Date.Month)||
                        (RTC.Prev.Date.Year!=RTC.Pres.Date.Year))// Checking for something changed and update
                {
                    (RTC.Prev.Time.Second=RTC.Pres.Time.Second);
                    (RTC.Prev.Time.Minute=RTC.Pres.Time.Minute);
                    (RTC.Prev.Time.Hour=RTC.Pres.Time.Hour);
                    (RTC.Prev.Date.DoWeek=RTC.Pres.Date.DoWeek);
                    (RTC.Prev.Date.Date=RTC.Pres.Date.Date);
                    (RTC.Prev.Date.Month=RTC.Pres.Date.Month);
                    (RTC.Prev.Date.Year=RTC.Pres.Date.Year);
                    Task=LCD_WRITE;
                }
                else Task=DEFAULT;
                break;

            case LCD_WRITE:
                switch(RTC.Prev.Date.DoWeek)
                {
                    case 1:
                        sprintf(&Str[0], "Sun");
                        break;

                    case 2:
                        sprintf(&Str[0], "Mon");
                        break;

                    case 3:
                        sprintf(&Str[0], "Tue");
                        break;

                    case 4:
                        sprintf(&Str[0], "Wed");
                        break;

                    case 5:
                        sprintf(&Str[0], "Thu");
                        break;

                    case 6:
                        sprintf(&Str[0], "Fri");
                        break;

                    case 7:
                        sprintf(&Str[0], "Sat");
                        break;

                    default:
                        break;
                }

                sprintf(&Str[3], ", %02d.%02d.%04d",
                        RTC.Pres.Date.Date,
                        RTC.Pres.Date.Month,
                        RTC.Pres.Date.Year);
                TextLCD_Puts(0, 0, Str, 16);
                
                sprintf(&Str[0], "%02d:%02d:%02d",
                        RTC.Pres.Time.Hour,
                        RTC.Pres.Time.Minute,
                        RTC.Pres.Time.Second);
                TextLCD_Puts(1, 0, Str, 8);
                Task=DEFAULT;
                break;

            default:
                if(MCP7941x_MFP(1)) Task=RTC_READ;
                break;
        }
    }
}