#include "Tick_Timer.h"
#include "../BLD.X/mcc_generated_files/tmr0.h"

bool Tick_Is_Over(tick_timer_t *tick, uint24_t ms)
{
    uint24_t pre=TMR0_Read16bitTimer();
    pre<<=3;
    
    if(tick->timeout)
    {
        tick->start=pre;
        tick->stop=tick->start+ms*TICK_PER_MS;
        if(tick->stop>0x07FFFF) tick->stop-=0x080000;
    }
    if(tick->stop>tick->start) tick->timeout=(bool)(tick->stop<pre);
    else tick->timeout=(bool)((tick->stop<pre)&&(pre<tick->start));
    
    return tick->timeout;
}

tick_timer_t t;

void Delay_ms(uint24_t ms)
{
    while(!Tick_Is_Over(&t, ms)) CLRWDT();
}

void Delay_Init()
{
    t.timeout=1;
}