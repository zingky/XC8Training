#include "Tick_Timer.h"
#include "mcc_generated_files/tmr1.h"

bool Tick_Is_Over(tick_timer_t *tick, uint32_t ms)
{
    uint32_t pre=TMR1_ReadTimer();
    if(tick->timeout)
    {
        tick->start=pre;
        tick->stop=tick->start+ms*TICK_PER_MS;
    }
    if(tick->stop>tick->start) tick->timeout=(tick->stop<pre);
    else tick->timeout=((tick->stop<pre)&&(pre<tick->start));
    
    return tick->timeout;
}
