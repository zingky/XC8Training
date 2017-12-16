#include <xc.h>
#include "IO.h"

void IO_Config()
{
    RLED_DigitalSet(OUTPUT);
    RLED_AnalogSet(DISABLE);
    RLED_StateSet(LOW);
    
    GLED_DigitalSet(OUTPUT);
    GLED_AnalogSet(DISABLE);
    GLED_StateSet(LOW);
    
    BLED_DigitalSet(OUTPUT);
    BLED_AnalogSet(DISABLE);
    BLED_StateSet(LOW);
    
    YLED_DigitalSet(OUTPUT);
    YLED_AnalogSet(DISABLE);
    YLED_StateSet(LOW);
    
    BT1_DigitalSet(INPUT);
    BT1_AnalogSet(DISABLE);
    
    BT2_DigitalSet(INPUT);
    BT2_AnalogSet(DISABLE);
    
    BT3_DigitalSet(INPUT);
    BT3_AnalogSet(DISABLE);
    
    BT4_DigitalSet(INPUT);
    BT4_AnalogSet(DISABLE);
}

bool BT1_Is_Pressed()
{
    static bool latch=1;
    if(BT1_StateGet()^latch) 
    {
        latch=~latch;
        if(latch) return 1;
    }
    return 0;
}

bool BT2_Is_Pressed()
{
    static bool latch=1;
    if(BT2_StateGet()^latch) 
    {
        latch=~latch;
        if(latch) return 1;
    }
    return 0;
}

bool BT3_Is_Pressed()
{
    static bool latch=1;
    if(BT3_StateGet()^latch) 
    {
        latch=~latch;
        if(latch) return 1;
    }
    return 0;
}

bool BT4_Is_Pressed()
{
    static bool latch=1;
    if(BT4_StateGet()^latch) 
    {
        latch=~latch;
        if(latch) return 1;
    }
    return 0;
}