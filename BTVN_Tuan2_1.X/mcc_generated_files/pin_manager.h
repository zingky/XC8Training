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

// get/set RED aliases
#define RED_TRIS               TRISBbits.TRISB0
#define RED_LAT                LATBbits.LATB0
#define RED_PORT               PORTBbits.RB0
#define RED_WPU                WPUBbits.WPUB0
#define RED_ANS                ANSELBbits.ANSB0
#define RED_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RED_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RED_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RED_GetValue()           PORTBbits.RB0
#define RED_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RED_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RED_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define RED_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define RED_SetAnalogMode()  do { ANSELBbits.ANSB0 = 1; } while(0)
#define RED_SetDigitalMode() do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set YEL aliases
#define YEL_TRIS               TRISBbits.TRISB1
#define YEL_LAT                LATBbits.LATB1
#define YEL_PORT               PORTBbits.RB1
#define YEL_WPU                WPUBbits.WPUB1
#define YEL_ANS                ANSELBbits.ANSB1
#define YEL_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define YEL_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define YEL_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define YEL_GetValue()           PORTBbits.RB1
#define YEL_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define YEL_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define YEL_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define YEL_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define YEL_SetAnalogMode()  do { ANSELBbits.ANSB1 = 1; } while(0)
#define YEL_SetDigitalMode() do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set GRN aliases
#define GRN_TRIS               TRISBbits.TRISB2
#define GRN_LAT                LATBbits.LATB2
#define GRN_PORT               PORTBbits.RB2
#define GRN_WPU                WPUBbits.WPUB2
#define GRN_ANS                ANSELBbits.ANSB2
#define GRN_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define GRN_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define GRN_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define GRN_GetValue()           PORTBbits.RB2
#define GRN_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define GRN_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define GRN_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define GRN_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)
#define GRN_SetAnalogMode()  do { ANSELBbits.ANSB2 = 1; } while(0)
#define GRN_SetDigitalMode() do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set IO_RC0 aliases
#define IO_RC0_TRIS               TRISCbits.TRISC0
#define IO_RC0_LAT                LATCbits.LATC0
#define IO_RC0_PORT               PORTCbits.RC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS               TRISCbits.TRISC1
#define IO_RC1_LAT                LATCbits.LATC1
#define IO_RC1_PORT               PORTCbits.RC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS               TRISCbits.TRISC2
#define IO_RC2_LAT                LATCbits.LATC2
#define IO_RC2_PORT               PORTCbits.RC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set IO_RC3 aliases
#define IO_RC3_TRIS               TRISCbits.TRISC3
#define IO_RC3_LAT                LATCbits.LATC3
#define IO_RC3_PORT               PORTCbits.RC3
#define IO_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_RC3_GetValue()           PORTCbits.RC3
#define IO_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set IO_RC4 aliases
#define IO_RC4_TRIS               TRISCbits.TRISC4
#define IO_RC4_LAT                LATCbits.LATC4
#define IO_RC4_PORT               PORTCbits.RC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS               TRISCbits.TRISC5
#define IO_RC5_LAT                LATCbits.LATC5
#define IO_RC5_PORT               PORTCbits.RC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set IO_RC6 aliases
#define IO_RC6_TRIS               TRISCbits.TRISC6
#define IO_RC6_LAT                LATCbits.LATC6
#define IO_RC6_PORT               PORTCbits.RC6
#define IO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_RC6_GetValue()           PORTCbits.RC6
#define IO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set IO_RC7 aliases
#define IO_RC7_TRIS               TRISCbits.TRISC7
#define IO_RC7_LAT                LATCbits.LATC7
#define IO_RC7_PORT               PORTCbits.RC7
#define IO_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_RC7_GetValue()           PORTCbits.RC7
#define IO_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

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