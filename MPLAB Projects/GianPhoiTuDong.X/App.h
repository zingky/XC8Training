#ifndef APP_H
#define	APP_H
#include <stdbool.h>
#include <stdint.h>
#define _XTAL_FREQ  8000000

#define INPUT   1
#define OUTPUT  0

#define STT_State_Set(x)    LATBbits.LATB6=x
#define STT_Toggle()        LATBbits.LATB6=~LATBbits.LATB6

void App_Init();
void App_Task();

#endif
