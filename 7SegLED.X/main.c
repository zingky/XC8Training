#include "mcc_generated_files/mcc.h"

const uint8_t segment_code[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};

bool BT1_Is_Pressed()
{
    static bool lat=1;
    bool bt_state=BT1_GetValue();
    if(lat!=bt_state)
    {
        lat=bt_state;
        if(lat) return 1;
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
    
    uint8_t count=0;
    LATC=~segment_code[0];
    while(1)
    {
        if(BT1_Is_Pressed())
        {
            count++;
            if(count>9) count=0;
            LATC=~segment_code[count];
        }
    }
}