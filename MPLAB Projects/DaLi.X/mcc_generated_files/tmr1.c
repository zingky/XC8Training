#include <xc.h>
#include "tmr1.h"

volatile uint16_t count=0;

void TMR1_Initialize(void)
{
    //T1CKPS 1:8; T1OSCEN disabled; nT1SYNC synchronize; TMR1CS FOSC/4; TMR1ON off; 
    T1CON=0x30;
    //T1GSS T1G_pin; TMR1GE disabled; T1GTM disabled; T1GPOL low; T1GGO done; T1GSPM disabled; 
    T1GCON=0x00;
    //TMR1H 0; 
    TMR1H=0x00;
    //TMR1L 0; 
    TMR1L=0x00;
    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR1IF=0;
    // Enabling TMR1 interrupt.
    PIE1bits.TMR1IE=1;
    T1CONbits.TMR1ON=1;
}

uint32_t TMR1_ReadTimer(void)
{
    uint32_t readVal=count;
    readVal<<=8;
    readVal|=TMR1H;
    readVal<<=8;
    readVal|=TMR1L;
    readVal<<=3;
    return readVal;
}

void TMR1_ISR(void)
{
    // Clear the TMR1 interrupt flag
    PIR1bits.TMR1IF=0;
    TMR1H=0;
    TMR1L=0;
    // callback function - called every 8192th pass
    if(++count>=TMR1_INTERRUPT_TICKER_FACTOR) count=0;
}
