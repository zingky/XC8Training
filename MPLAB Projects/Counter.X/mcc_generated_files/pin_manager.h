/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC16F1936
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RC0 procedures
#define RC0_SetHigh()    do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()   do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()   do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()         PORTCbits.RC0
#define RC0_SetDigitalInput()   do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()  do { TRISCbits.TRISC0 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS               TRISCbits.TRISC1
#define RS_LAT                LATCbits.LATC1
#define RS_PORT               PORTCbits.RC1
#define RS_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RS_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RS_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RS_GetValue()           PORTCbits.RC1
#define RS_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set EN aliases
#define EN_TRIS               TRISCbits.TRISC2
#define EN_LAT                LATCbits.LATC2
#define EN_PORT               PORTCbits.RC2
#define EN_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define EN_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define EN_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define EN_GetValue()           PORTCbits.RC2
#define EN_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS               TRISCbits.TRISC3
#define D4_LAT                LATCbits.LATC3
#define D4_PORT               PORTCbits.RC3
#define D4_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define D4_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define D4_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define D4_GetValue()           PORTCbits.RC3
#define D4_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS               TRISCbits.TRISC4
#define D5_LAT                LATCbits.LATC4
#define D5_PORT               PORTCbits.RC4
#define D5_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define D5_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define D5_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define D5_GetValue()           PORTCbits.RC4
#define D5_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS               TRISCbits.TRISC5
#define D6_LAT                LATCbits.LATC5
#define D6_PORT               PORTCbits.RC5
#define D6_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define D6_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define D6_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define D6_GetValue()           PORTCbits.RC5
#define D6_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS               TRISCbits.TRISC6
#define D7_LAT                LATCbits.LATC6
#define D7_PORT               PORTCbits.RC6
#define D7_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define D7_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define D7_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define D7_GetValue()           PORTCbits.RC6
#define D7_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/