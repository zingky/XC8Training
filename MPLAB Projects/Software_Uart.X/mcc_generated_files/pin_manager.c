#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"

void PIN_MANAGER_Initialize(void)
{
    LATA=0x02;
    TRISA=0x3D;
    ANSELA=0x11;
    WPUA=0x3F;
    OPTION_REGbits.nWPUEN=0;
    APFCON=0x00;
}