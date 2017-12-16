#ifndef _TMR1_H
#define _TMR1_H

#include <stdbool.h>
#include <stdint.h>
#define TMR1_INTERRUPT_TICKER_FACTOR    8192

void TMR1_Initialize(void);
uint32_t TMR1_ReadTimer(void);
void TMR1_ISR(void);

#endif