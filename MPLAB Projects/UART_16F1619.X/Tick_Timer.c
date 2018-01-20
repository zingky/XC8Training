#include "Tick_Timer.h"
#include "mcc_generated_files/tmr1.h"

bool Tick_Is_Over(tick_timer_t *tick, uint32_t t)
{
    uint32_t pre=TMR1_ReadTimer();
    if(tick->timeout)
    {
        tick->start=pre;
        tick->stop=tick->start+t*TICK_PER_MS;
    }
    if(tick->stop>tick->start) tick->timeout=(tick->stop<pre);
    else tick->timeout=((tick->stop<pre)&&(pre<tick->start));

    return tick->timeout;
}

void Delay_Ms(uint32_t t)
{
    tick_timer_t tdl;
    Tick_Reset(tdl);
    while(!Tick_Is_Over(&tdl, t)) CLRWDT();
}
