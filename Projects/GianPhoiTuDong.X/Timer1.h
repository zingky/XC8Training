#ifndef TIMER1_H
#define	TIMER1_H
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define Enable_TMR1_Interrupt()     PIE1bits.TMR1IE=1
#define Disable_TMR1_Interrupt()    PIE1bits.TMR1IE=0
#define Clear_TMR1_IntFlag()        PIR1bits.TMR1IF=0

void Timer1_Init();
uint24_t Timer1_Read24bit();
void Timer1_ISR();

#endif