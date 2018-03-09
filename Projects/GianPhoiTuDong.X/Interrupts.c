#include "Interrupts.h"
#include "Timer1.h"

void interrupt high_priority Interrupt_ManagerH()
{
    if(INTCONbits.GIE&INTCONbits.PEIE&PIE1bits.TMR1IE&PIR1bits.TMR1IF)
    {
        PIR1bits.TMR1IF=0;
        Timer1_ISR();
    }
}

void interrupt low_priority Interrupt_ManagerL()
{

}
