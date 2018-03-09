#include "mcc_generated_files/mcc.h"
#include "TextLCD.h"
#define NUM_OF_BUTTON 5
uint8_t str[16];

uint8_t BT_Is_Pressed(uint8_t idx)
{
    static bool prv_state[NUM_OF_BUTTON]={1, 1, 1, 1, 1};
    bool pre_state;
    switch(idx)
    {
        case 0:
            pre_state=BT1_GetValue();
            break;
        case 1:
            pre_state=BT2_GetValue();
            break;
        case 2:
            pre_state=BT3_GetValue();
            break;
        case 3:
            pre_state=BT4_GetValue();
            break;
        case 4:
            pre_state=BT5_GetValue();
            break;

        default:
            break;
    }
    if(prv_state[idx]!=pre_state)
    {
        prv_state[idx]=pre_state;
        if(pre_state) return 1;
    }
    return 0;
}

void main(void)
{
    SYSTEM_Initialize();
    TextLCD_Init();
    TextLCD_Puts(0, 0, (uint8_t *)"0000 0000 0000", 0);
    TextLCD_Puts(1, 0, (uint8_t *)"0000 0000", 0);
    while(1)
    {
        uint8_t i;
        static uint16_t duty[NUM_OF_BUTTON]={0, 0, 0, 0, 0};

        for(i=0; i<NUM_OF_BUTTON; i++)
        {
            if(BT_Is_Pressed(i))
            {
                duty[i]+=64;
                if(duty[i]>=1024) duty[i]=0;
                sprintf(str, "%04d", duty[i]);
                switch(i)
                {
                    case 0:
                        EPWM1_LoadDutyValue(duty[i]);
                        TextLCD_Puts(0, 0, str, 0);
                        break;

                    case 1:
                        EPWM2_LoadDutyValue(duty[i]);
                        TextLCD_Puts(0, 5, str, 0);
                        break;

                    case 2:
                        EPWM3_LoadDutyValue(duty[i]);
                        TextLCD_Puts(0, 10, str, 0);
                        break;

                    case 3:
                        PWM4_LoadDutyValue(duty[i]);
                        TextLCD_Puts(1, 0, str, 0);
                        break;

                    case 4:
                        PWM5_LoadDutyValue(duty[i]);
                        TextLCD_Puts(1, 5, str, 0);
                        break;

                    default:
                        break;
                }
            }
        }
    }
}