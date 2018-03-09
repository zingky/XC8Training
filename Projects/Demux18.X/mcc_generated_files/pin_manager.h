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

// get/set A aliases
#define A_TRIS               TRISBbits.TRISB0
#define A_LAT                LATBbits.LATB0
#define A_PORT               PORTBbits.RB0
#define A_WPU                WPUBbits.WPUB0
#define A_ANS                ANSELBbits.ANSB0
#define A_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define A_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define A_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define A_GetValue()           PORTBbits.RB0
#define A_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define A_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define A_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define A_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define A_SetAnalogMode()  do { ANSELBbits.ANSB0 = 1; } while(0)
#define A_SetDigitalMode() do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set B aliases
#define B_TRIS               TRISBbits.TRISB1
#define B_LAT                LATBbits.LATB1
#define B_PORT               PORTBbits.RB1
#define B_WPU                WPUBbits.WPUB1
#define B_ANS                ANSELBbits.ANSB1
#define B_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define B_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define B_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define B_GetValue()           PORTBbits.RB1
#define B_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define B_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define B_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define B_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define B_SetAnalogMode()  do { ANSELBbits.ANSB1 = 1; } while(0)
#define B_SetDigitalMode() do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set C aliases
#define C_TRIS               TRISBbits.TRISB2
#define C_LAT                LATBbits.LATB2
#define C_PORT               PORTBbits.RB2
#define C_WPU                WPUBbits.WPUB2
#define C_ANS                ANSELBbits.ANSB2
#define C_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define C_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define C_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define C_GetValue()           PORTBbits.RB2
#define C_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define C_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define C_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define C_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)
#define C_SetAnalogMode()  do { ANSELBbits.ANSB2 = 1; } while(0)
#define C_SetDigitalMode() do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set DATA aliases
#define DATA_TRIS               TRISBbits.TRISB3
#define DATA_LAT                LATBbits.LATB3
#define DATA_PORT               PORTBbits.RB3
#define DATA_WPU                WPUBbits.WPUB3
#define DATA_ANS                ANSELBbits.ANSB3
#define DATA_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define DATA_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define DATA_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define DATA_GetValue()           PORTBbits.RB3
#define DATA_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define DATA_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define DATA_SetPullup()      do { WPUBbits.WPUB3 = 1; } while(0)
#define DATA_ResetPullup()    do { WPUBbits.WPUB3 = 0; } while(0)
#define DATA_SetAnalogMode()  do { ANSELBbits.ANSB3 = 1; } while(0)
#define DATA_SetDigitalMode() do { ANSELBbits.ANSB3 = 0; } while(0)

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