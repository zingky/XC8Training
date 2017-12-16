#ifndef _TMR0_H
#define _TMR0_H

#include <stdint.h>
#include <stdbool.h>

void TMR0_Initialize(void);
void TMR0_Start(void);
void TMR0_Stop(void);
void TMR0_ISR(void);

#endif