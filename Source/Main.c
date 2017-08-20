#include <xc.h>
#include "Common.h"

void main()
{
    System_Config();
    AppInit();
    while(1)
    {
        CLRWDT();
        AppTask();
    }
}