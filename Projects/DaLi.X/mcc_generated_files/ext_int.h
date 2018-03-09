#ifndef _EXT_INT_H
#define _EXT_INT_H

#include <xc.h>

#define EXT_INT_InterruptFlagClear()    (INTCONbits.INTF = 0)
#define EXT_INT_InterruptDisable()      (INTCONbits.INTE = 0)
#define EXT_INT_InterruptEnable()       (INTCONbits.INTE = 1)
#define EXT_INT_risingEdgeSet()         (OPTION_REGbits.INTEDG = 1)
#define EXT_INT_fallingEdgeSet()        (OPTION_REGbits.INTEDG = 0)

void EXT_INT_Initialize(void);
void INT_ISR(void);

#endif
