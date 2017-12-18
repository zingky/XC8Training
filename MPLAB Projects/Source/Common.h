#ifndef COMMON_H
#define	COMMON_H

#include <xc.h>
#include "MCUConfig.h"
#include "ADC.h"
#include "DAC.h"
#include "DataConvert.h"
#include "DataCrypto.h"
#include "I2C.h"
#include "IO.h"
#include "IntManager.h"
#include "SPI.h"
#include "System.h"
#include "TMR.h"
#include "UART.h"
#include "UserDef.h"
#include "SegLCD.h"

void AppInit();
void AppTask();

#endif