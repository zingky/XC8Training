#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"

void PIN_MANAGER_Initialize(void)
{  
    LATE = 0x00;    
    LATA = 0x00;    
    LATB = 0x00;    
    LATC = 0x04;    
 
    TRISE = 0x08;
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0x91;

    ANSELB = 0x3F;
    ANSELA = 0x3F;

    WPUE = 0x08;
    WPUB = 0xFF;
    OPTION_REGbits.nWPUEN = 0;

    APFCON = 0x00;
}