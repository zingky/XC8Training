#include "Timer1.h"

volatile uint16_t tickcount;

void Timer1_Init()
{
    tickcount=0;
    TMR1H=0x00;
    TMR1L=0x00;
    T1CON=0b00110000;
    RCONbits.IPEN=0;
    IPR1bits.TMR1IP=1;
    PIR1bits.TMR1IF=0;// Clear timer 1 interrupt flag
    PIE1bits.TMR1IE=1;// Enable timer1 interrupt
    T1CONbits.TMR1ON=1;// Start timer 1
}

uint24_t Timer1_Read24bit()
{
    uint24_t res=tickcount;
    res<<8;
    res|=TMR1H;
    res<<=1;
    res|=TMR1L;
    return res;
}

void Timer1_ISR()
{
    tickcount++;
    if(tickcount>=8192) tickcount=0;
}
