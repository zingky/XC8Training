#ifndef TICK_TIMER_H
#define	TICK_TIMER_H
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#if defined(__PIC32MX)
#define Tick_Reset(x)   x.timeout=1
#define TICK_PER_SEC    24000000// FOSC/2=48E6/2
#define TICK_PER_MS     24000// FOSC/2/1000=48E6/2/1000
#define TICK_PER_US     24// FOSC/2/1000=48E6/2/1000000

typedef enum
{
    US=0,
    MS=1,
    SEC=2
} delay_unit_t;

typedef struct
{
    bool timeout;
    uint32_t start;
    uint32_t stop;
} tick_timer_t;

bool Tick_Is_Over(tick_timer_t *tick, uint32_t t, delay_unit_t unit);
void Delay(uint32_t t, delay_unit_t unit);
void Delay_Init();

#define Delay_us(t)             Delay(t, US)
#define Delay_ms(t)             Delay(t, MS)
#define Delay_sec(t)            Delay(t, SEC)

#define Tick_Is_Over_Us(tk, t)  Tick_Is_Over(&tk, t, US)
#define Tick_Is_Over_Ms(tk, t)  Tick_Is_Over(&tk, t, MS)
#define Tick_Is_Over_Sec(tk, t) Tick_Is_Over(&tk, t, SEC)

#else

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
#endif