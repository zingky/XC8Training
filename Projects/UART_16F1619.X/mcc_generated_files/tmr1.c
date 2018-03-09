#include <xc.h>
#include "tmr1.h"

static volatile uint16_t count;

void TMR1_Initialize(void)
{
    //T1GSS T1G_pin; TMR1GE disabled; T1GTM disabled; T1GPOL low; T1GGO_nDONE done; T1GSPM disabled; 
    T1GCON = 0x00;
    //TMR1H 0; 
    TMR1H = 0x00;
    //TMR1L 0; 
    TMR1L = 0x00;
    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR1IF = 0;
    // Enabling TMR1 interrupt.
    PIE1bits.TMR1IE = 1;
    // T1CKPS 1:8; nT1SYNC synchronize; TMR1CS LFINTOSC; TMR1ON enabled; 
    T1CON = 0xF1;
}

uint32_t TMR1_ReadTimer(void)
{
    uint32_t res=count;
    res<<=8;
    res|=TMR1H;
    res<<=8;
    res|=TMR1L;
    res<<=3;
    return res;
}

void TMR1_ISR(void)
{
    // Clear the TMR1 interrupt flag
    PIR1bits.TMR1IF=0;
    // callback function - called every 8192th pass
    if(++count>=TMR1_INTERRUPT_TICKER_FACTOR) count=0;
}
