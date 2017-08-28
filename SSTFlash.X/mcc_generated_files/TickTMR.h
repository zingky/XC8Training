#ifndef SYSTMR_H
#define	SYSTMR_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define TICK_PER_US     8 // SYSCLK/4/1000000
#define TICK_PER_MS     8000 // SYSCLK/4/1000
#define TICK_PER_SEC    8000000 // SYSCLK/4
#define Tick_Reset(x)   Tick_Is_Over(&x, 0, RESET)
#define Tick_Init(x)    x.timeout=1
typedef enum
{
    US,
    MS,
    SEC,
    RESET
} delay_type_t;

typedef struct
{
    bool timeout;
    uint32_t start;
    uint32_t stop;
} tick_timer_t;

bool Tick_Is_Over(tick_timer_t *tick, uint32_t t, delay_type_t unit);
void delay_ms(uint16_t ms);
void delay_us(uint16_t ms);

#endif