#ifndef INTERRUPTS_H
#define	INTERRUPTS_H
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#define Enable_Global_Interrupt()       INTCONbits.GIE=1
#define Disable_Global_Interrupt()      INTCONbits.GIE=0
#define Enable_Peripheral_Interrupt()   INTCONbits.PEIE=1
#define Disable_Peripheral_Interrupt()  INTCONbits.PEIE=0

void interrupt high_priority Interrupt_ManagerH();
void interrupt low_priority Interrupt_ManagerL();

#endif