#include "mcc_generated_files/mcc.h"
#define Tick_Reset(x) x.timeout=1
#define TICK_PER_MS 8000

typedef struct
{
    bool timeout;
    uint32_t start;
    uint32_t stop;
} tick_timer_t;

bool Tick_Is_Over(tick_timer_t *tick, uint32_t ms)
{
    uint32_t pre=TMR1_ReadTimer();
    if(tick->timeout)
    {
        tick->start=pre;
        tick->stop=tick->start+TICK_PER_MS*ms;
    }
    if(tick->stop>tick->start) tick->timeout=(tick->stop<pre);
    else tick->timeout=((tick->stop<pre)&&(pre<tick->start));
    return tick->timeout;
}

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

    while(1)
    {
        if(Tick_Is_Over(&Tick.led1, 100)) LED1_Toggle();
        if(Tick_Is_Over(&Tick.led2, 500)) LED2_Toggle();
        if(Tick_Is_Over(&Tick.led3, 1000)) LED3_Toggle();
        if(Tick_Is_Over(&Tick.led4, 5000)) LED4_Toggle();
    }
}