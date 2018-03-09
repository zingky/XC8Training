#include "mcc_generated_files/mcc.h"
// <editor-fold defaultstate="collapsed" desc="Variables of DC Motor 1">
uint16_t DC1_Speed;
uint8_t DC1_Direction;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Variables for DC Motor 2">
uint16_t DC2_Speed;
uint8_t DC2_Direction;
// </editor-fold>

bool BT_Speed1_Is_Pressed() // <editor-fold defaultstate="collapsed" desc="Check Speed Button 1">
{
    static bool prv=1;
    bool pre=BT_SPEED1_GetValue();
    if(prv!=pre)
    {
        prv=pre;
        if(pre==0) return 1;
    }
    return 0;
} // </editor-fold>

bool BT_Direct1_Is_Pressed() // <editor-fold defaultstate="collapsed" desc="Check Direction Button 1">
{
    static bool prv=1;
    bool pre=BT_DIRECT1_GetValue();
    if(prv!=pre)
    {
        prv=pre;
        if(pre==0) return 1;
    }
    return 0;
} // </editor-fold>

bool BT_Speed2_Is_Pressed() // <editor-fold defaultstate="collapsed" desc="Check Speed Button 2">
{
    static bool prv=1;
    bool pre=BT_SPEED2_GetValue();
    if(prv!=pre)
    {
        prv=pre;
        if(pre==0) return 1;
    }
    return 0;
} // </editor-fold>

bool BT_Direct2_Is_Pressed() // <editor-fold defaultstate="collapsed" desc="Check Direction Button 2">
{
    static bool prv=1;
    bool pre=BT_DIRECT2_GetValue();
    if(prv!=pre)
    {
        prv=pre;
        if(pre==0) return 1;
    }
    return 0;
} // </editor-fold>

void DCMotor1_Init() // <editor-fold defaultstate="collapsed" desc="DC Motor 1 Initialize">
{
    DC1_Speed=0;
    DC1_Direction=1;
    DIR1_LAT=DC1_Direction; // Set direction of motor 1
    PWM4_LoadDutyValue(0); // Set speed of motor 1
} // </editor-fold>

void DCMotor2_Init() // <editor-fold defaultstate="collapsed" desc="DC Motor 2 Initialize">
{
    DC2_Speed=0;
    DC2_Direction=1;
    DIR2_LAT=DC2_Direction; // Set direction of motor 2
    PWM5_LoadDutyValue(0); // Set speed of motor 2
} // </editor-fold>

void main(void) // <editor-fold defaultstate="collapsed" desc="Main Function">
{
    SYSTEM_Initialize();
    DCMotor1_Init();
    DCMotor2_Init();
    while(1)
    {
        CLRWDT();

        if(BT_Speed1_Is_Pressed()&&(DC1_Direction!=0))
        {
            DC1_Speed+=0x00FF;
            if(DC1_Speed>0x03FF) DC1_Speed=0;
            PWM4_LoadDutyValue(DC1_Speed); // Set speed of motor 1
        }

        if(BT_Direct1_Is_Pressed())
        {
            PWM4_LoadDutyValue(0); // Stop motor
            DC1_Direction++;
            if(DC1_Direction>2) DC1_Direction=0;
            if(DC1_Direction==0) PWM4_LoadDutyValue(0);
            else
            {
                if(DC1_Direction==1) DIR1_LAT=1;
                else DIR1_LAT=0;
                PWM4_LoadDutyValue(DC1_Speed); // Set speed of motor 1
            }
        }

        if(BT_Speed2_Is_Pressed()&&(DC2_Direction!=0))
        {
            DC2_Speed+=0x00FF;
            if(DC2_Speed>0x03FF) DC2_Speed=0;
            PWM5_LoadDutyValue(DC2_Speed); // Set speed of motor 2
        }

        if(BT_Direct2_Is_Pressed())
        {
            PWM5_LoadDutyValue(0); // Stop motor
            DC2_Direction++;
            if(DC2_Direction>2) DC2_Direction=0;
            if(DC2_Direction==0) PWM5_LoadDutyValue(0);
            else
            {
                if(DC2_Direction==1) DIR2_LAT=1;
                else DIR2_LAT=0;
                PWM5_LoadDutyValue(DC2_Speed); // Set speed of motor 2
            }
        }
    }
} // </editor-fold>