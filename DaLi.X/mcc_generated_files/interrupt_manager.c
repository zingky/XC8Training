#include "interrupt_manager.h"
#include "mcc.h"

void interrupt INTERRUPT_InterruptManager(void)
{
    if(INTCONbits.INTE&INTCONbits.INTF) INT_ISR();
    else if(INTCONbits.TMR0IE&INTCONbits.TMR0IF) TMR0_ISR();
    else if(INTCONbits.PEIE&PIE1bits.TMR1IE&PIR1bits.TMR1IF) TMR1_ISR();
}
