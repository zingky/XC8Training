#include "mcc_generated_files/mcc.h"
#include "Tick_Timer.h"

const uint8_t segment_code[11]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8, 0x80, 0x90, 0x7F};// Ma led 7 doan duong cuc chung
tick_timer_t ledTick;

void Display(uint16_t val)
{
    static uint8_t next=0;
    uint8_t idx;
    
    switch(next)
    {
        case 0:
			DIG4_SetHigh();			// Tat chu so hang don vi
            idx=(val/1000)%10;		// Lay chu so hang nghin
			LATC=segment_code[idx];	// Xuat ma led hang nghin
            DIG1_SetLow();			// Bat chu so hang nghin
            next=1;
            break;
            
        case 2:
			DIG1_SetHigh();			// Tat chu so hang nghin
            idx=(val/100)%10;		// Lay chu so hang tram
			LATC=segment_code[idx];	// Xuat ma led hang tram
            DIG2_SetLow();			// Bat chu so hang tram
            next=3;
            break;
            
        case 4:
			DIG2_SetHigh();			// Tat chu so hang tram
            idx=(val/10)%10;		// Lay chu so hang chuc
			LATC=segment_code[idx]&segment_code[10];	// Xuat ma led hang chuc
            DIG3_SetLow();			// Bat chu so hang chuc
            next=5;
            break;
            
        case 6:
			DIG3_SetHigh();			// Tat chu so hang chuc
            idx=val%10;             // Lay chu so hang don vi
			LATC=segment_code[idx];	// Xuat ma led hang don vi
            DIG4_SetLow();			// Bat chu so hang don vi
            next=7;
            break;
            
        default:
            if(Tick_Is_Over(&ledTick, 1)) next++;
            if(next>7) next=0;
            break;
    }
}

void main(void)
{
    SYSTEM_Initialize();
    Tick_Reset(ledTick);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {
        Display(5678);// Hien thi so 567.8
    }
}