#include "Tick_Timer.h"

#if defined(__PIC32MX)
tick_timer_t tdl;

bool Tick_Is_Over(tick_timer_t *tick, uint32_t t, delay_unit_t unit)
{
    uint32_t pre;
    asm volatile("mfc0 %0, $9":"=r"(pre));
    if(tick->timeout)
    {
        tick->start=pre;
        if(unit==US) tick->stop=tick->start+t*TICK_PER_US;
        else if(unit==MS) tick->stop=tick->start+t*TICK_PER_MS;
        else tick->stop=tick->start+t*TICK_PER_SEC;
        
    }
    if(tick->stop>tick->start) tick->timeout=(tick->stop<pre);
    else tick->timeout=((tick->stop<pre)&&(pre<tick->start));
    
    return tick->timeout;
}

void Delay_Init()
{
    Tick_Reset(tdl);
}

void Delay(uint32_t t, delay_unit_t unit)
{
    while(!Tick_Is_Over(&tdl, t, unit)) WDTCONbits.WDTCLR=1;
}

#else
#include "mcc_generated_files/tmr1.h"

bool Tick_Is_Over(tick_timer_t *tick, uint24_t ms)
{
    uint24_t pre=TMR1_ReadTimer();
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
    while(!Tick_Is_Over(&t, ms));
}

void Delay_Init()
{
    t.timeout=1;
}
#endif