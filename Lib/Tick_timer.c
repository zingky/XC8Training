#include "Tick_timer.h"
#include "TMR.h"

bool Tick_Is_Over(tick_timer_t *tick, uint32_t t)
{
    uint32_t real_tick=TMR1_Counter16BitGet();
    if(tick->timeout)
    {
        tick->start=real_tick;
        tick->stop=real_tick+t*TICK_PER_MS;
    }
    if(tick->stop>tick->start) tick->timeout=(tick->stop<real_tick);
    else tick->timeout=((tick->stop<real_tick)&&(real_tick<tick->start));
    return tick->timeout;
}