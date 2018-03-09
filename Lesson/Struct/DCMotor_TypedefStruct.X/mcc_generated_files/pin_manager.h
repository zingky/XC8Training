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
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
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

// get/set RA4 procedures
#define RA4_SetHigh()    do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()   do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()   do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()         PORTAbits.RA4
#define RA4_SetDigitalInput()   do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()  do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetAnalogMode() do { ANSELAbits.ANSA4 = 1; } while(0)
#define RA4_SetDigitalMode()do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set DIR2 aliases
#define DIR2_TRIS               TRISAbits.TRISA5
#define DIR2_LAT                LATAbits.LATA5
#define DIR2_PORT               PORTAbits.RA5
#define DIR2_ANS                ANSELAbits.ANSA5
#define DIR2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define DIR2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define DIR2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define DIR2_GetValue()           PORTAbits.RA5
#define DIR2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define DIR2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define DIR2_SetAnalogMode()  do { ANSELAbits.ANSA5 = 1; } while(0)
#define DIR2_SetDigitalMode() do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()    do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()   do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()   do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()         PORTBbits.RB0
#define RB0_SetDigitalInput()   do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()  do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()     do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()   do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode() do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set DIR1 aliases
#define DIR1_TRIS               TRISBbits.TRISB1
#define DIR1_LAT                LATBbits.LATB1
#define DIR1_PORT               PORTBbits.RB1
#define DIR1_WPU                WPUBbits.WPUB1
#define DIR1_ANS                ANSELBbits.ANSB1
#define DIR1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define DIR1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define DIR1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define DIR1_GetValue()           PORTBbits.RB1
#define DIR1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define DIR1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define DIR1_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define DIR1_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define DIR1_SetAnalogMode()  do { ANSELBbits.ANSB1 = 1; } while(0)
#define DIR1_SetDigitalMode() do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set BT_SPEED1 aliases
#define BT_SPEED1_TRIS               TRISCbits.TRISC0
#define BT_SPEED1_LAT                LATCbits.LATC0
#define BT_SPEED1_PORT               PORTCbits.RC0
#define BT_SPEED1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define BT_SPEED1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define BT_SPEED1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define BT_SPEED1_GetValue()           PORTCbits.RC0
#define BT_SPEED1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define BT_SPEED1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set BT_DIRECT1 aliases
#define BT_DIRECT1_TRIS               TRISCbits.TRISC1
#define BT_DIRECT1_LAT                LATCbits.LATC1
#define BT_DIRECT1_PORT               PORTCbits.RC1
#define BT_DIRECT1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define BT_DIRECT1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define BT_DIRECT1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define BT_DIRECT1_GetValue()           PORTCbits.RC1
#define BT_DIRECT1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define BT_DIRECT1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set BT_SPEED2 aliases
#define BT_SPEED2_TRIS               TRISCbits.TRISC2
#define BT_SPEED2_LAT                LATCbits.LATC2
#define BT_SPEED2_PORT               PORTCbits.RC2
#define BT_SPEED2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define BT_SPEED2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define BT_SPEED2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define BT_SPEED2_GetValue()           PORTCbits.RC2
#define BT_SPEED2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define BT_SPEED2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set BT_DIRECT2 aliases
#define BT_DIRECT2_TRIS               TRISCbits.TRISC3
#define BT_DIRECT2_LAT                LATCbits.LATC3
#define BT_DIRECT2_PORT               PORTCbits.RC3
#define BT_DIRECT2_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define BT_DIRECT2_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define BT_DIRECT2_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define BT_DIRECT2_GetValue()           PORTCbits.RC3
#define BT_DIRECT2_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define BT_DIRECT2_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

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