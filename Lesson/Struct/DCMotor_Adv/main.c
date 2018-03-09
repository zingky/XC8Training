#include "mcc_generated_files/mcc.h"

typedef struct
{
    uint16_t Speed;
    bool Direction;
} dcmotor_t;

dcmotor_t DC1, DC2;

struct
{
    bool Speed1;
    bool Speed2;
    bool Direction1;
    bool Direction2;
} Prv;

void Button_Init() // <editor-fold defaultstate="collapsed" desc="Preset state for button variables">
{
    Prv.Speed1=BT_SPEED1_GetValue();
    Prv.Direction1=BT_DIRECT1_GetValue();
    Prv.Speed2=BT_SPEED2_GetValue();
    Prv.Direction2=BT_DIRECT2_GetValue();
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
    DIR2_LAT=DC2.Direction; // Set direction of motor 1
    PWM5_LoadDutyValue(0); // Set speed of motor 1
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

        if(BT_Is_Pressed(BT_SPEED1_GetValue(), &Prv.Speed1))
        {
            DC1.Speed+=0x00FF;
            if(DC1.Speed>0x03FF) DC1.Speed=0;
            PWM4_LoadDutyValue(DC1.Speed); // Set speed of motor 1
        }

        if(BT_Is_Pressed(BT_DIRECT1_GetValue(), &Prv.Direction1))
        {
            PWM4_LoadDutyValue(0); // Stop motor
            DC1.Direction=~DC1.Direction;
            DIR1_LAT=DC1.Direction;
            PWM4_LoadDutyValue(DC1.Speed); // Set speed of motor 1
        }

        if(BT_Is_Pressed(BT_SPEED2_GetValue(), &Prv.Speed2))
        {
            DC2.Speed+=0x00FF;
            if(DC2.Speed>0x03FF) DC2.Speed=0;
            PWM5_LoadDutyValue(DC2.Speed); // Set speed of motor 2
        }

        if(BT_Is_Pressed(BT_DIRECT2_GetValue(), &Prv.Direction2))
        {
            PWM5_LoadDutyValue(0); // Stop motor
            DC2.Direction=~DC2.Direction;
            DIR2_LAT=DC2.Direction;
            PWM5_LoadDutyValue(DC2.Speed); // Set speed of motor 2
        }
    }
} // </editor-fold>