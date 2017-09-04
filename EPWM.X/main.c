#include "mcc_generated_files/mcc.h"

bool BT_Is_Pressed()
{
    static bool prv_state=1;
    bool pre_state=BT_GetValue();
    if(prv_state!=pre_state)
    {
        prv_state=pre_state;
        if(prv_state) return 1;
    }
    return 0;
}

void main(void)
{
    SYSTEM_Initialize();

    while(1)
    {
        static uint16_t duty=0;
        if(BT_Is_Pressed())
        {
            duty+=64;
            if(duty>1023) duty=0;
            EPWM1_LoadDutyValue(duty);
        }
    }
}