#ifndef TICK_TIMER_H
#define	TICK_TIMER_H
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#define Tick_Reset(x)   x.timeout=1
#define TICK_PER_MS     30// 31KHz

typedef struct {
    uint32_t start;
    uint32_t stop;
    bool timeout;
} tick_timer_t;

bool Tick_Is_Over(tick_timer_t *tick, uint32_t t);
void Delay_Ms(uint32_t t);

#endif