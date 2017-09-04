#ifndef TICK_TIMER_H
#define	TICK_TIMER_H
#include <stdbool.h>
#include <stdint.h>

#define TICK_PER_MS     16000 // SYSCLK/2/1000
#define Tick_Reset(x)   x.timeout=1

typedef struct
{
    bool timeout;
    uint32_t start;
    uint32_t stop;
} tick_timer_t;

bool Tick_Is_Over(tick_timer_t *tick, uint32_t t);

#endif

