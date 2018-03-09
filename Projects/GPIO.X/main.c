#include "mcc_generated_files/mcc.h"

bool BT1_Is_Pressed()
{
    static bool lat_bt1=1;
    bool bt1_state=BT1_GetValue();
    if(lat_bt1!=bt1_state)
    {
        lat_bt1=bt1_state;
        if(lat_bt1) return 1;
    }
    return 0;
}

bool BT2_Is_Pressed()
{
    static bool lat_bt1=1;
    bool bt1_state=BT2_GetValue();
    if(lat_bt1!=bt1_state)
    {
        lat_bt1=bt1_state;
        if(lat_bt1) return 1;
    }
    return 0;
}

bool BT3_Is_Pressed()
{
    static bool lat_bt1=1;
    bool bt1_state=BT3_GetValue();
    if(lat_bt1!=bt1_state)
    {
        lat_bt1=bt1_state;
        if(lat_bt1) return 1;
    }
    return 0;
}

bool BT4_Is_Pressed()
{
    static bool lat_bt1=1;
    bool bt1_state=BT4_GetValue();
    if(lat_bt1!=bt1_state)
    {
        lat_bt1=bt1_state;
        if(lat_bt1) return 1;
    }
    return 0;
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        if(BT1_Is_Pressed()) RLED_Toggle();
        if(BT2_Is_Pressed()) GLED_Toggle();
        if(BT3_Is_Pressed()) BLED_Toggle();
        if(BT4_Is_Pressed()) YLED_Toggle();
    }
}