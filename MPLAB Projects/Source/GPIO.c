#include "Common.h"

void AppInit()
{
    IO_Config();
}

void AppTask()
{
    if(BT1_StateGet()) 
    {
        RLED_Toggle();
        __delay_ms(100);
    }
}