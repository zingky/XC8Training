#include "mcc_generated_files/mcc.h"

bool BT1_Is_Pressed()
{
    static bool prv_state=1;
    bool pre_state=BT1_GetValue();
    if(prv_state!=pre_state)
    {
        prv_state=pre_state;
        if(prv_state) return 1;
    }
    return 0;
}

bool BT2_Is_Pressed()
{
    static bool prv_state=1;
    bool pre_state=BT2_GetValue();
    if(prv_state!=pre_state)
    {
        prv_state=pre_state;
        if(prv_state) return 1;
    }
    return 0;
}

void main(void)
{
    uint16_t duty=0;
    bool fwrv=0;
    bool update=0;
    
    SYSTEM_Initialize();
    while (1)
    {
        if(BT1_Is_Pressed())
        {
            duty+=64;
            if(duty>1023) duty=0;
            update=1;
        }
        
        if(BT2_Is_Pressed())
        {
            fwrv=~fwrv;
            update=1;
        }
        
        if(update)
        {
            update=0;
            if(fwrv) CCP1CONbits.P1M=0b01;//Full-Bridge output forward; PxD modulated; PxA active; PxB, PxC inactive
            else CCP1CONbits.P1M=0b11;//Full-Bridge output reverse; PxB modulated; PxC active; PxA, PxD inactive
            EPWM1_LoadDutyValue(duty);
        }
    }
}