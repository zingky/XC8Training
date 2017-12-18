#include <xc.h>
#include "ext_int.h"
#include "tmr0.h"

void INT_ISR(void)
{
    EXT_INT_InterruptFlagClear();
    TMR0_Start();
}

void EXT_INT_Initialize(void)
{
    EXT_INT_InterruptFlagClear();   
    EXT_INT_fallingEdgeSet();    
    EXT_INT_InterruptEnable();
}

