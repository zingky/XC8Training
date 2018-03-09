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

// get/set DIR1 aliases
#define DIR1_TRIS               TRISAbits.TRISA5
#define DIR1_LAT                LATAbits.LATA5
#define DIR1_PORT               PORTAbits.RA5
#define DIR1_ANS                ANSELAbits.ANSA5
#define DIR1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define DIR1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define DIR1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define DIR1_GetValue()           PORTAbits.RA5
#define DIR1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define DIR1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define DIR1_SetAnalogMode()  do { ANSELAbits.ANSA5 = 1; } while(0)
#define DIR1_SetDigitalMode() do { ANSELAbits.ANSA5 = 0; } while(0)

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

// get/set DIR2 aliases
#define DIR2_TRIS               TRISBbits.TRISB1
#define DIR2_LAT                LATBbits.LATB1
#define DIR2_PORT               PORTBbits.RB1
#define DIR2_WPU                WPUBbits.WPUB1
#define DIR2_ANS                ANSELBbits.ANSB1
#define DIR2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define DIR2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define DIR2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define DIR2_GetValue()           PORTBbits.RB1
#define DIR2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define DIR2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define DIR2_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define DIR2_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define DIR2_SetAnalogMode()  do { ANSELBbits.ANSB1 = 1; } while(0)
#define DIR2_SetDigitalMode() do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set BT_SPEED1 aliases
#define BT_SPEED1_TRIS               TRISBbits.TRISB2
#define BT_SPEED1_LAT                LATBbits.LATB2
#define BT_SPEED1_PORT               PORTBbits.RB2
#define BT_SPEED1_WPU                WPUBbits.WPUB2
#define BT_SPEED1_ANS                ANSELBbits.ANSB2
#define BT_SPEED1_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BT_SPEED1_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BT_SPEED1_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BT_SPEED1_GetValue()           PORTBbits.RB2
#define BT_SPEED1_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BT_SPEED1_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BT_SPEED1_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define BT_SPEED1_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)
#define BT_SPEED1_SetAnalogMode()  do { ANSELBbits.ANSB2 = 1; } while(0)
#define BT_SPEED1_SetDigitalMode() do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set BT_DIRECT1 aliases
#define BT_DIRECT1_TRIS               TRISBbits.TRISB3
#define BT_DIRECT1_LAT                LATBbits.LATB3
#define BT_DIRECT1_PORT               PORTBbits.RB3
#define BT_DIRECT1_WPU                WPUBbits.WPUB3
#define BT_DIRECT1_ANS                ANSELBbits.ANSB3
#define BT_DIRECT1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define BT_DIRECT1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define BT_DIRECT1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define BT_DIRECT1_GetValue()           PORTBbits.RB3
#define BT_DIRECT1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define BT_DIRECT1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define BT_DIRECT1_SetPullup()      do { WPUBbits.WPUB3 = 1; } while(0)
#define BT_DIRECT1_ResetPullup()    do { WPUBbits.WPUB3 = 0; } while(0)
#define BT_DIRECT1_SetAnalogMode()  do { ANSELBbits.ANSB3 = 1; } while(0)
#define BT_DIRECT1_SetDigitalMode() do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set BT_SPEED2 aliases
#define BT_SPEED2_TRIS               TRISBbits.TRISB4
#define BT_SPEED2_LAT                LATBbits.LATB4
#define BT_SPEED2_PORT               PORTBbits.RB4
#define BT_SPEED2_WPU                WPUBbits.WPUB4
#define BT_SPEED2_ANS                ANSELBbits.ANSB4
#define BT_SPEED2_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define BT_SPEED2_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define BT_SPEED2_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define BT_SPEED2_GetValue()           PORTBbits.RB4
#define BT_SPEED2_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define BT_SPEED2_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define BT_SPEED2_SetPullup()      do { WPUBbits.WPUB4 = 1; } while(0)
#define BT_SPEED2_ResetPullup()    do { WPUBbits.WPUB4 = 0; } while(0)
#define BT_SPEED2_SetAnalogMode()  do { ANSELBbits.ANSB4 = 1; } while(0)
#define BT_SPEED2_SetDigitalMode() do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set BT_DIRECT2 aliases
#define BT_DIRECT2_TRIS               TRISBbits.TRISB5
#define BT_DIRECT2_LAT                LATBbits.LATB5
#define BT_DIRECT2_PORT               PORTBbits.RB5
#define BT_DIRECT2_WPU                WPUBbits.WPUB5
#define BT_DIRECT2_ANS                ANSELBbits.ANSB5
#define BT_DIRECT2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define BT_DIRECT2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define BT_DIRECT2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define BT_DIRECT2_GetValue()           PORTBbits.RB5
#define BT_DIRECT2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define BT_DIRECT2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define BT_DIRECT2_SetPullup()      do { WPUBbits.WPUB5 = 1; } while(0)
#define BT_DIRECT2_ResetPullup()    do { WPUBbits.WPUB5 = 0; } while(0)
#define BT_DIRECT2_SetAnalogMode()  do { ANSELBbits.ANSB5 = 1; } while(0)
#define BT_DIRECT2_SetDigitalMode() do { ANSELBbits.ANSB5 = 0; } while(0)

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