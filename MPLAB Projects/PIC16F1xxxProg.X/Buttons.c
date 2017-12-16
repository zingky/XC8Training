#include "Buttons.h"

bool BT_Is_Pressed(button_t *BT, bool signal, bool edge, uint32_t detect_time)// Power button
{
    switch(BT->BtTask)
    {
        case BT_CHECK_NOISE:
            if(Tick_Is_Over(&BT->Tick, detect_time, MS))
            {
                BT->BtTask=BT_PRESSED;
                if(edge==H2L) return 1;
            }
            else BT->BtTask=BT_CHECK_AGAIN;
            break;

        case BT_CHECK_AGAIN:
            if(signal==0) BT->BtTask=BT_CHECK_NOISE;
            else
            {
                Tick_Reset(BT->Tick);
                BT->BtTask=BT_UNPRESSED;
            }
            break;

        case BT_PRESSED:
            if(signal==1) 
            {
                BT->BtTask=BT_UNPRESSED;
                if(edge==L2H) return 1;
            }
            break;

        default:
            if(signal==0)
            {
                Tick_Reset(BT->Tick);
                BT->BtTask=BT_CHECK_NOISE;
            }
            break;
    }
    return 0;
}

void Button_Init(button_t *BT)
{
    BT->BtTask=BT_UNPRESSED;
    Tick_Reset(BT->Tick);
}