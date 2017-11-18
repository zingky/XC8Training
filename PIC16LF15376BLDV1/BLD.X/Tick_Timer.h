#ifndef TICK_TIMER_H
#define	TICK_TIMER_H
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#define Tick_Reset(x)   x.timeout=1
#define TICK_PER_MS     30

typedef struct
{
    bool timeout;
    uint24_t start;
    uint24_t stop;
} tick_timer_t;

bool Tick_Is_Over(tick_timer_t *tick, uint24_t ms);
void Delay_ms(uint24_t ms);
void Delay_Init();

#endif