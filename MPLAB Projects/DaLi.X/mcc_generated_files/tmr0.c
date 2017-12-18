#include <xc.h>
#include "tmr0.h"
#include "../dali.h"

void TMR0_Initialize(void)
{
    TMR0_Stop();
    // PSA assigned; PS 1:256; TMRSE Increment_hi_lo; mask the nWPUEN and INTEDG bits
    OPTION_REG=(uint8_t) ((OPTION_REG&0xC0)|0xD7&0x3F);
    // TMR0 230; 
    TMR0=0xE6;
    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF=0;
    // Enabling TMR0 interrupt
    INTCONbits.TMR0IE=1;
}

void TMR0_Start(void)
{
    DALI.busy=1;
    DALI.bitCount=0;
    TMR0=0xE6;
    INTCONbits.TMR0IF=0;
}

void TMR0_Stop(void)
{
    INTCONbits.TMR0IE=0;
}

void TMR0_ISR(void)
{
    TMR0=0xE6;
    INTCONbits.TMR0IF=0;
    Dali_Physic_Xfer();
}