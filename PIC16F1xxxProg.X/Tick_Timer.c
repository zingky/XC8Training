#include <proc/p32mx530f128h.h>
#include "Tick_Timer.h"

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