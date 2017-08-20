#include <xc.h>
#include <pic16f1936.h>
#include "System.h"

void System_Config()
{
    OSCCONbits.IRCF=0b1110;
    while(!OSCSTATbits.PLLR);
}