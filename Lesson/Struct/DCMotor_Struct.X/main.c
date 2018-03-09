#include "mcc_generated_files/mcc.h"
// <editor-fold defaultstate="collapsed" desc="Variables of DC Motor 1">
struct
{
    uint16_t Speed;
    bool Direction;
} DC1;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Variables for DC Motor 2">
struct
{
    uint16_t Speed;
    bool Direction;
} DC2;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Variables of Buttons">
bool Prv_Speed1, Prv_Direction1, Prv_Speed2, Prv_Direction2;
// </editor-fold>

void Button_Init() // <editor-fold defaultstate="collapsed" desc="Preset state for button variables">
{
    Prv_Speed1=BT_SPEED1_GetValue();
    Prv_Direction1=BT_DIRECT1_GetValue();
    Prv_Speed2=BT_SPEED2_GetValue();
    Prv_Direction2=BT_DIRECT2_GetValue();
} // </editor-fold>

bool BT_Is_Pressed(bool Button, bool *Previous_State) // <editor-fold defaultstate="collapsed" desc="Check Button">
{
    bool pre=Button;
    if(*Previous_State!=pre)
    {
        *Previous_State=pre;
        if(pre==0) return 1;
    }
    return 0;
} // </editor-fold>

void DCMotor1_Init() // <editor-fold defaultstate="collapsed" desc="DC Motor 1 Initialize">
{
    DC1.Speed=0;
    DC1.Direction=0;
    DIR1_LAT=DC1.Direction; // Set direction of motor 1
    PWM4_LoadDutyValue(0); // Set speed of motor 1
} // </editor-fold>

void DCMotor2_Init() // <editor-fold defaultstate="collapsed" desc="DC Motor 2 Initialize">
{
    DC2.Speed=0;
    DC2.Direction=0;
    DIR2_LAT=DC2.Direction; // Set direction of motor 2
    PWM5_LoadDutyValue(0); // Set speed of motor 2
} // </editor-fold>

void main(void) // <editor-fold defaultstate="collapsed" desc="Main Function">
{
    SYSTEM_Initialize();
    DCMotor1_Init();
    DCMotor2_Init();
    Button_Init();
    while(1)
    {
        CLRWDT();

        if(BT_Is_Pressed(BT_SPEED1_GetValue(), &Prv_Speed1))
        {
            DC1.Speed+=0x00FF;
            if(DC1.Speed>0x03FF) DC1.Speed=0;
            PWM4_LoadDutyValue(DC1.Speed); // Set speed of motor 1
        }

        if(BT_Is_Pressed(BT_DIRECT1_GetValue(), &Prv_Direction1))
        {
            PWM4_LoadDutyValue(0); // Stop motor
            DC1.Direction=~DC1.Direction;
            DIR1_LAT=DC1.Direction;
            PWM4_LoadDutyValue(DC1.Speed); // Set speed of motor 1
        }

        if(BT_Is_Pressed(BT_SPEED2_GetValue(), &Prv_Speed2))
        {
            DC2.Speed+=0x00FF;
            if(DC2.Speed>0x03FF) DC2.Speed=0;
            PWM5_LoadDutyValue(DC2.Speed); // Set speed of motor 2
        }

        if(BT_Is_Pressed(BT_DIRECT2_GetValue(), &Prv_Direction2))
        {
            PWM5_LoadDutyValue(0); // Stop motor
            DC2.Direction=~DC2.Direction;
            DIR2_LAT=DC2.Direction;
            PWM5_LoadDutyValue(DC2.Speed); // Set speed of motor 2
        }
    }
} // </editor-fold>