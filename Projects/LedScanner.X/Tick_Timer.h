#ifndef TICK_TIMER_H
#define	TICK_TIMER_H
#include <stdbool.h>
#include <stdint.h>
#define Tick_Reset(x)   x.timeout=1
#define TICK_PER_MS     8000// FOSC/4/1000=32E6/4/1000

typedef struct
{
    bool timeout;
    uint32_t start;
    uint32_t stop;
} tick_timer_t;

bool Tick_Is_Over(tick_timer_t *tick, uint32_t ms);

#endif

