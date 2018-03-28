#include "mcc_generated_files/mcc.h"
#include "Tick_Timer.h"
#include "Buttons.h"

const uint8_t segment_code[12]=// <editor-fold defaultstate="collapsed" desc="7-Segment common anode code">
{
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8, 0x80, 0x90, // 0-9
    0x7F, // Dot '.'
    0xFF// Off Led
}; // </editor-fold>

#define NUM_OF_DIGIT    4
bool AutoCount;
uint8_t DotIdx;
uint16_t Count;
tick_timer_t LedTick, CountTick;
button_t BtUp, BtDown, BtAuto, BtDotIdx;

void Display(uint16_t Val, uint8_t Dot_Idx) // <editor-fold defaultstate="collapsed" desc="Led Scanner">
{
    static uint8_t next=0;
    static uint8_t pre_dot_idx=0xFF;
    static uint16_t pre_val=0xFFFF;
    static uint8_t Lat_Val[NUM_OF_DIGIT];

    if((pre_val!=Val)||(pre_dot_idx!=Dot_Idx)) // <editor-fold defaultstate="collapsed" desc="Check for Val or Dot_Idx changed">
    {
        uint8_t i=0;
        pre_val=Val;
        pre_dot_idx=Dot_Idx;
LOOP:
        Lat_Val[i]=segment_code[Val%10];
        if((i==Dot_Idx)&&(i>0)&&(i<NUM_OF_DIGIT))
            Lat_Val[i]&=segment_code[10];
        i++;
        Val/=10;
        if((Val>0)||(i<=Dot_Idx)) goto LOOP;
        else
        {
            while(i<NUM_OF_DIGIT)
                Lat_Val[i++]=segment_code[11];
        }
    } // </editor-fold>

    switch(next) // <editor-fold defaultstate="collapsed" desc="Set digit active">
    {
        case 0:
            DIG4_SetHigh();
            LATC=Lat_Val[3];
            DIG1_SetLow();
            next=1;
            break;

        case 2:
            DIG1_SetHigh();
            LATC=Lat_Val[2];
            DIG2_SetLow();
            next=3;
            break;

        case 4:
            DIG2_SetHigh();
            LATC=Lat_Val[1];
            DIG3_SetLow();
            next=5;
            break;

        case 6:
            DIG3_SetHigh();
            LATC=Lat_Val[0];
            DIG4_SetLow();
            next=7;
            break;

        default:
            if(Tick_Is_Over(&LedTick, 1)) next++;
            if(next>7) next=0;
            break;
    } // </editor-fold>
    
} // </editor-fold>

void main(void) // <editor-fold defaultstate="collapsed" desc="Main Function">
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    DotIdx=0;
    Count=9995;
    AutoCount=0;

    Tick_Reset(LedTick);
    Tick_Reset(CountTick);
    Button_Init(&BtUp);
    Button_Init(&BtDown);
    Button_Init(&BtAuto);
    Button_Init(&BtDotIdx);

    while(1)
    {
        CLRWDT();
        if((!AutoCount)&&Button_Is_Pressed(&BtUp, BT_UP_GetValue(), H2L, 100)) // <editor-fold defaultstate="collapsed" desc="Count up">
        {
            if(Count++>=9999)
                Count=0;
        } // </editor-fold>

        if((!AutoCount)&&Button_Is_Pressed(&BtDown, BT_DOWN_GetValue(), H2L, 100)) // <editor-fold defaultstate="collapsed" desc="Count down">
        {
            if(Count--==0)
                Count=9999;
        } // </editor-fold>

        if(Button_Is_Pressed(&BtAuto, BT_AUTO_GetValue(), H2L, 100)) // <editor-fold defaultstate="collapsed" desc="Auto count">
            AutoCount=~AutoCount;
        // </editor-fold>
        
        if(Button_Is_Pressed(&BtDotIdx, BT_DOT_GetValue(), H2L, 100)) // <editor-fold defaultstate="collapsed" desc="Dot index">
        {
            if(DotIdx++>=(NUM_OF_DIGIT-1))
                DotIdx=0;
        } // </editor-fold>

        if(AutoCount) // <editor-fold defaultstate="collapsed" desc="Auto count process">
        {
            if(Tick_Is_Over(&CountTick, 100))
            {
                if(Count++>=9999)
                    Count=0;
            }
        } // </editor-fold>

        Display(Count, DotIdx);// Display
    }
} // </editor-fold>