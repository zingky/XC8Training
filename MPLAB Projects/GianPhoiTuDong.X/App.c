#include "App.h"
#include "Interrupts.h"
#include "Tick_Timer.h"

tick_timer_t t;

void App_Init()
{
    TRISBbits.TRISB6=0;
    STT_State_Set(0);
    Delay_Init();
    Tick_Reset(t);
    Enable_Peripheral_Interrupt();
    Enable_Global_Interrupt();
}

void App_Task()
{
    __delay_ms(100);
    STT_Toggle();
}