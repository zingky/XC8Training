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
        Product Revision  :  MPLAB(c) Code Configurator - 4.26.1
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

// get/set BT_UP aliases
#define BT_UP_TRIS               TRISAbits.TRISA0
#define BT_UP_LAT                LATAbits.LATA0
#define BT_UP_PORT               PORTAbits.RA0
#define BT_UP_ANS                ANSELAbits.ANSA0
#define BT_UP_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define BT_UP_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define BT_UP_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define BT_UP_GetValue()           PORTAbits.RA0
#define BT_UP_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define BT_UP_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define BT_UP_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define BT_UP_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set BT_DOWN aliases
#define BT_DOWN_TRIS               TRISAbits.TRISA1
#define BT_DOWN_LAT                LATAbits.LATA1
#define BT_DOWN_PORT               PORTAbits.RA1
#define BT_DOWN_ANS                ANSELAbits.ANSA1
#define BT_DOWN_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BT_DOWN_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BT_DOWN_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BT_DOWN_GetValue()           PORTAbits.RA1
#define BT_DOWN_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BT_DOWN_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BT_DOWN_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define BT_DOWN_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set BT_AUTO aliases
#define BT_AUTO_TRIS               TRISAbits.TRISA2
#define BT_AUTO_LAT                LATAbits.LATA2
#define BT_AUTO_PORT               PORTAbits.RA2
#define BT_AUTO_ANS                ANSELAbits.ANSA2
#define BT_AUTO_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define BT_AUTO_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define BT_AUTO_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define BT_AUTO_GetValue()           PORTAbits.RA2
#define BT_AUTO_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define BT_AUTO_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define BT_AUTO_SetAnalogMode()  do { ANSELAbits.ANSA2 = 1; } while(0)
#define BT_AUTO_SetDigitalMode() do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set BT_DOT aliases
#define BT_DOT_TRIS               TRISAbits.TRISA3
#define BT_DOT_LAT                LATAbits.LATA3
#define BT_DOT_PORT               PORTAbits.RA3
#define BT_DOT_ANS                ANSELAbits.ANSA3
#define BT_DOT_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define BT_DOT_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define BT_DOT_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define BT_DOT_GetValue()           PORTAbits.RA3
#define BT_DOT_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define BT_DOT_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define BT_DOT_SetAnalogMode()  do { ANSELAbits.ANSA3 = 1; } while(0)
#define BT_DOT_SetDigitalMode() do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set DIG1 aliases
#define DIG1_TRIS               TRISBbits.TRISB0
#define DIG1_LAT                LATBbits.LATB0
#define DIG1_PORT               PORTBbits.RB0
#define DIG1_WPU                WPUBbits.WPUB0
#define DIG1_ANS                ANSELBbits.ANSB0
#define DIG1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define DIG1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define DIG1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define DIG1_GetValue()           PORTBbits.RB0
#define DIG1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define DIG1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define DIG1_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define DIG1_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define DIG1_SetAnalogMode()  do { ANSELBbits.ANSB0 = 1; } while(0)
#define DIG1_SetDigitalMode() do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set DIG2 aliases
#define DIG2_TRIS               TRISBbits.TRISB1
#define DIG2_LAT                LATBbits.LATB1
#define DIG2_PORT               PORTBbits.RB1
#define DIG2_WPU                WPUBbits.WPUB1
#define DIG2_ANS                ANSELBbits.ANSB1
#define DIG2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define DIG2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define DIG2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define DIG2_GetValue()           PORTBbits.RB1
#define DIG2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define DIG2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define DIG2_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define DIG2_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define DIG2_SetAnalogMode()  do { ANSELBbits.ANSB1 = 1; } while(0)
#define DIG2_SetDigitalMode() do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set DIG3 aliases
#define DIG3_TRIS               TRISBbits.TRISB2
#define DIG3_LAT                LATBbits.LATB2
#define DIG3_PORT               PORTBbits.RB2
#define DIG3_WPU                WPUBbits.WPUB2
#define DIG3_ANS                ANSELBbits.ANSB2
#define DIG3_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define DIG3_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define DIG3_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define DIG3_GetValue()           PORTBbits.RB2
#define DIG3_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define DIG3_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define DIG3_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define DIG3_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)
#define DIG3_SetAnalogMode()  do { ANSELBbits.ANSB2 = 1; } while(0)
#define DIG3_SetDigitalMode() do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set DIG4 aliases
#define DIG4_TRIS               TRISBbits.TRISB3
#define DIG4_LAT                LATBbits.LATB3
#define DIG4_PORT               PORTBbits.RB3
#define DIG4_WPU                WPUBbits.WPUB3
#define DIG4_ANS                ANSELBbits.ANSB3
#define DIG4_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define DIG4_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define DIG4_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define DIG4_GetValue()           PORTBbits.RB3
#define DIG4_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define DIG4_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define DIG4_SetPullup()      do { WPUBbits.WPUB3 = 1; } while(0)
#define DIG4_ResetPullup()    do { WPUBbits.WPUB3 = 0; } while(0)
#define DIG4_SetAnalogMode()  do { ANSELBbits.ANSB3 = 1; } while(0)
#define DIG4_SetDigitalMode() do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set SEGA aliases
#define SEGA_TRIS               TRISCbits.TRISC0
#define SEGA_LAT                LATCbits.LATC0
#define SEGA_PORT               PORTCbits.RC0
#define SEGA_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SEGA_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SEGA_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SEGA_GetValue()           PORTCbits.RC0
#define SEGA_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SEGA_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set SEGB aliases
#define SEGB_TRIS               TRISCbits.TRISC1
#define SEGB_LAT                LATCbits.LATC1
#define SEGB_PORT               PORTCbits.RC1
#define SEGB_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SEGB_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SEGB_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SEGB_GetValue()           PORTCbits.RC1
#define SEGB_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SEGB_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set SEGC aliases
#define SEGC_TRIS               TRISCbits.TRISC2
#define SEGC_LAT                LATCbits.LATC2
#define SEGC_PORT               PORTCbits.RC2
#define SEGC_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SEGC_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SEGC_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SEGC_GetValue()           PORTCbits.RC2
#define SEGC_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SEGC_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set SEGD aliases
#define SEGD_TRIS               TRISCbits.TRISC3
#define SEGD_LAT                LATCbits.LATC3
#define SEGD_PORT               PORTCbits.RC3
#define SEGD_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SEGD_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SEGD_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SEGD_GetValue()           PORTCbits.RC3
#define SEGD_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SEGD_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set SEGE aliases
#define SEGE_TRIS               TRISCbits.TRISC4
#define SEGE_LAT                LATCbits.LATC4
#define SEGE_PORT               PORTCbits.RC4
#define SEGE_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SEGE_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SEGE_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SEGE_GetValue()           PORTCbits.RC4
#define SEGE_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SEGE_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set SEGF aliases
#define SEGF_TRIS               TRISCbits.TRISC5
#define SEGF_LAT                LATCbits.LATC5
#define SEGF_PORT               PORTCbits.RC5
#define SEGF_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SEGF_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SEGF_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SEGF_GetValue()           PORTCbits.RC5
#define SEGF_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SEGF_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set SEGG aliases
#define SEGG_TRIS               TRISCbits.TRISC6
#define SEGG_LAT                LATCbits.LATC6
#define SEGG_PORT               PORTCbits.RC6
#define SEGG_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SEGG_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SEGG_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SEGG_GetValue()           PORTCbits.RC6
#define SEGG_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SEGG_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set SEGH aliases
#define SEGH_TRIS               TRISCbits.TRISC7
#define SEGH_LAT                LATCbits.LATC7
#define SEGH_PORT               PORTCbits.RC7
#define SEGH_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SEGH_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SEGH_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SEGH_GetValue()           PORTCbits.RC7
#define SEGH_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SEGH_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

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