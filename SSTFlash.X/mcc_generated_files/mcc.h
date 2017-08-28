#ifndef MCC_H
#define	MCC_H
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "pin_manager.h"
#include "eusart.h"
#include "spi.h"
#include "tmr1.h"
#include "TickTMR.h"
#include "interrupt_manager.h"

#define _XTAL_FREQ  32000000

void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);
void WDT_Initialize(void);

#endif