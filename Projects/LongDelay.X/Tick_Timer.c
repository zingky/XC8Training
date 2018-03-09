#include "Tick_Timer.h"
#include "mcc_generated_files/tmr1.h"



bool Tick_Is_Over(tick_timer_t *tick, uint32_t ms)
{
    uint24_t pre=TMR1_ReadTimer();
    pre<<=3;
    if(tick->timeout)
    {
        tick->start=pre;
        tick->stop=tick->start+ms*TICK_PER_MS;
    }
    if(tick->stop>tick->start) tick->timeout=(bool)(tick->stop<pre);
    else tick->timeout=(bool)((tick->stop<pre)&&(pre<tick->start));
    
    return tick->timeout;
}

void Delay_ms(uint32_t ms)
{
    tick_timer_t t;
    t.timeout=1;
    while(!Tick_Is_Over(&t, ms)) CLRWDT();
}