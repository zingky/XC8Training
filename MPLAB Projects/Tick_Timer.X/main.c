#include "mcc_generated_files/mcc.h"
#include "Tick_Timer.h"

struct
{
    tick_timer_t led1;
    tick_timer_t led2;
    tick_timer_t led3;
    tick_timer_t led4;
} Tick;

void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    Tick_Reset(Tick.led1);
    Tick_Reset(Tick.led2);
    Tick_Reset(Tick.led3);
    Tick_Reset(Tick.led4);
    while (1)
    {
        if(Tick_Is_Over(&Tick.led1, 100)) LED1_Toggle();
        if(Tick_Is_Over(&Tick.led2, 500)) LED2_Toggle();
        if(Tick_Is_Over(&Tick.led3, 1000)) LED3_Toggle();
        if(Tick_Is_Over(&Tick.led4, 5000)) LED4_Toggle();
    }
}