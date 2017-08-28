#include "TickTMR.h"
#include "tmr1.h"

bool Tick_Is_Over(tick_timer_t *tick, uint32_t t, delay_type_t unit)
{
    uint32_t real_tick=TMR1_ReadTimer();
    
    if(unit==RESET) tick->timeout=1;
    else
    {
        if(tick->timeout)
        {
            if(unit==US) t*=TICK_PER_US;
            else if(unit==MS) t*=TICK_PER_MS;
            else t*=TICK_PER_SEC;
            tick->start=real_tick;
            tick->stop=real_tick+t;
        }
        if(tick->stop>tick->start) tick->timeout=(tick->stop<real_tick);
        else tick->timeout=((tick->stop<real_tick)&&(real_tick<tick->start));
    }
    return tick->timeout;
}

void delay_ms(uint16_t ms)
{
    tick_timer_t t;
    Tick_Init(t);
    while(!Tick_Is_Over(&t, ms, MS));
}

void delay_us(uint16_t us)
{
    tick_timer_t t;
    Tick_Init(t);
    while(!Tick_Is_Over(&t, us, MS));
}