#include "interrupt_manager.h"
#include "mcc.h"

void interrupt INTERRUPT_InterruptManager (void)
{
    if(INTCONbits.INTE&INTCONbits.INTF) INT_ISR();
}