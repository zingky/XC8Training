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

// get/set IO_RB0 aliases
#define IO_RB0_TRIS               TRISBbits.TRISB0
#define IO_RB0_LAT                LATBbits.LATB0
#define IO_RB0_PORT               PORTBbits.RB0
#define IO_RB0_WPU                WPUBbits.WPUB0
#define IO_RB0_ANS                ANSELBbits.ANSB0
#define IO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_RB0_GetValue()           PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_RB0_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_RB0_SetAnalogMode()  do { ANSELBbits.ANSB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode() do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set IO_RB1 aliases
#define IO_RB1_TRIS               TRISBbits.TRISB1
#define IO_RB1_LAT                LATBbits.LATB1
#define IO_RB1_PORT               PORTBbits.RB1
#define IO_RB1_WPU                WPUBbits.WPUB1
#define IO_RB1_ANS                ANSELBbits.ANSB1
#define IO_RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_RB1_GetValue()           PORTBbits.RB1
#define IO_RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_RB1_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_RB1_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_RB1_SetAnalogMode()  do { ANSELBbits.ANSB1 = 1; } while(0)
#define IO_RB1_SetDigitalMode() do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set IO_RB2 aliases
#define IO_RB2_TRIS               TRISBbits.TRISB2
#define IO_RB2_LAT                LATBbits.LATB2
#define IO_RB2_PORT               PORTBbits.RB2
#define IO_RB2_WPU                WPUBbits.WPUB2
#define IO_RB2_ANS                ANSELBbits.ANSB2
#define IO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_RB2_GetValue()           PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_RB2_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_RB2_SetAnalogMode()  do { ANSELBbits.ANSB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode() do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set IO_RB3 aliases
#define IO_RB3_TRIS               TRISBbits.TRISB3
#define IO_RB3_LAT                LATBbits.LATB3
#define IO_RB3_PORT               PORTBbits.RB3
#define IO_RB3_WPU                WPUBbits.WPUB3
#define IO_RB3_ANS                ANSELBbits.ANSB3
#define IO_RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_RB3_GetValue()           PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IO_RB3_SetPullup()      do { WPUBbits.WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()    do { WPUBbits.WPUB3 = 0; } while(0)
#define IO_RB3_SetAnalogMode()  do { ANSELBbits.ANSB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode() do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set IO_RB4 aliases
#define IO_RB4_TRIS               TRISBbits.TRISB4
#define IO_RB4_LAT                LATBbits.LATB4
#define IO_RB4_PORT               PORTBbits.RB4
#define IO_RB4_WPU                WPUBbits.WPUB4
#define IO_RB4_ANS                ANSELBbits.ANSB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()      do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()    do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetAnalogMode()  do { ANSELBbits.ANSB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode() do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set IO_RB5 aliases
#define IO_RB5_TRIS               TRISBbits.TRISB5
#define IO_RB5_LAT                LATBbits.LATB5
#define IO_RB5_PORT               PORTBbits.RB5
#define IO_RB5_WPU                WPUBbits.WPUB5
#define IO_RB5_ANS                ANSELBbits.ANSB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()      do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()    do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetAnalogMode()  do { ANSELBbits.ANSB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode() do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS               TRISBbits.TRISB6
#define IO_RB6_LAT                LATBbits.LATB6
#define IO_RB6_PORT               PORTBbits.RB6
#define IO_RB6_WPU                WPUBbits.WPUB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()      do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()    do { WPUBbits.WPUB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS               TRISBbits.TRISB7
#define IO_RB7_LAT                LATBbits.LATB7
#define IO_RB7_PORT               PORTBbits.RB7
#define IO_RB7_WPU                WPUBbits.WPUB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()      do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()    do { WPUBbits.WPUB7 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS               TRISCbits.TRISC0
#define RS_LAT                LATCbits.LATC0
#define RS_PORT               PORTCbits.RC0
#define RS_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RS_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RS_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RS_GetValue()           PORTCbits.RC0
#define RS_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set EN aliases
#define EN_TRIS               TRISCbits.TRISC1
#define EN_LAT                LATCbits.LATC1
#define EN_PORT               PORTCbits.RC1
#define EN_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define EN_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define EN_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define EN_GetValue()           PORTCbits.RC1
#define EN_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS               TRISCbits.TRISC2
#define D4_LAT                LATCbits.LATC2
#define D4_PORT               PORTCbits.RC2
#define D4_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define D4_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define D4_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define D4_GetValue()           PORTCbits.RC2
#define D4_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS               TRISCbits.TRISC3
#define D5_LAT                LATCbits.LATC3
#define D5_PORT               PORTCbits.RC3
#define D5_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define D5_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define D5_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define D5_GetValue()           PORTCbits.RC3
#define D5_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS               TRISCbits.TRISC4
#define D6_LAT                LATCbits.LATC4
#define D6_PORT               PORTCbits.RC4
#define D6_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define D6_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define D6_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define D6_GetValue()           PORTCbits.RC4
#define D6_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS               TRISCbits.TRISC5
#define D7_LAT                LATCbits.LATC5
#define D7_PORT               PORTCbits.RC5
#define D7_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define D7_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define D7_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define D7_GetValue()           PORTCbits.RC5
#define D7_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

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