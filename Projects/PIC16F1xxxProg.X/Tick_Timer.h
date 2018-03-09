#ifndef TICK_TIMER_H
#define	TICK_TIMER_H
#include <stdbool.h>
#include <stdint.h>
#define Tick_Reset(x)           x.timeout=1
#define TICK_PER_SEC            24000000// FOSC/2=48E6/2
#define TICK_PER_MS             24000// FOSC/2/1000=48E6/2/1000
#define TICK_PER_US             24// FOSC/2/1000=48E6/2/1000000
#define Tick_Over_Us(t, us)     Tick_Is_Over(&t, us, US)
#define Tick_Over_Ms(t, ms)     Tick_Is_Over(&t, ms, MS)
#define Tick_Over_Sec(t, sec)   Tick_Is_Over(&t, sec, SEC)
#define Delay_us(us)            Delay(us, US)
#define Delay_ms(ms)            Delay(ms, MS)
#define Delay_sec(sec)          Delay(sec, SEC)

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

#endif