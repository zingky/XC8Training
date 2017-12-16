#include "mcc_generated_files/mcc.h"

struct
{
    tick_timer_t led;
    tick_timer_t urx;
} tick;

uint8_t task;

void main(void)
{
    SYSTEM_Initialize();
    Tick_Init(tick.led);
    Tick_Init(tick.urx);
    task=0;
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    while(1)
    {
        CLRWDT();
        if(Tick_Is_Over(&led_tick, 100, MS)) LED_Toggle();
        switch(task)
        {
            case 0:
                if()
                break;
        }
    }
}