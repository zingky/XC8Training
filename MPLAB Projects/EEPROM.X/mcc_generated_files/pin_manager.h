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

// get/set RS aliases
#define RS_TRIS               TRISAbits.TRISA0
#define RS_LAT                LATAbits.LATA0
#define RS_PORT               PORTAbits.RA0
#define RS_ANS                ANSELAbits.ANSA0
#define RS_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RS_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RS_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RS_GetValue()           PORTAbits.RA0
#define RS_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RS_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define RS_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set EN aliases
#define EN_TRIS               TRISAbits.TRISA1
#define EN_LAT                LATAbits.LATA1
#define EN_PORT               PORTAbits.RA1
#define EN_ANS                ANSELAbits.ANSA1
#define EN_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define EN_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define EN_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define EN_GetValue()           PORTAbits.RA1
#define EN_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define EN_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define EN_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS               TRISAbits.TRISA2
#define D4_LAT                LATAbits.LATA2
#define D4_PORT               PORTAbits.RA2
#define D4_ANS                ANSELAbits.ANSA2
#define D4_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define D4_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define D4_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define D4_GetValue()           PORTAbits.RA2
#define D4_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define D4_SetAnalogMode()  do { ANSELAbits.ANSA2 = 1; } while(0)
#define D4_SetDigitalMode() do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS               TRISAbits.TRISA3
#define D5_LAT                LATAbits.LATA3
#define D5_PORT               PORTAbits.RA3
#define D5_ANS                ANSELAbits.ANSA3
#define D5_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define D5_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define D5_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define D5_GetValue()           PORTAbits.RA3
#define D5_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define D5_SetAnalogMode()  do { ANSELAbits.ANSA3 = 1; } while(0)
#define D5_SetDigitalMode() do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS               TRISAbits.TRISA4
#define D6_LAT                LATAbits.LATA4
#define D6_PORT               PORTAbits.RA4
#define D6_ANS                ANSELAbits.ANSA4
#define D6_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define D6_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define D6_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define D6_GetValue()           PORTAbits.RA4
#define D6_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define D6_SetAnalogMode()  do { ANSELAbits.ANSA4 = 1; } while(0)
#define D6_SetDigitalMode() do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS               TRISAbits.TRISA5
#define D7_LAT                LATAbits.LATA5
#define D7_PORT               PORTAbits.RA5
#define D7_ANS                ANSELAbits.ANSA5
#define D7_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define D7_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define D7_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define D7_GetValue()           PORTAbits.RA5
#define D7_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define D7_SetAnalogMode()  do { ANSELAbits.ANSA5 = 1; } while(0)
#define D7_SetDigitalMode() do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set BT aliases
#define BT_TRIS               TRISBbits.TRISB0
#define BT_LAT                LATBbits.LATB0
#define BT_PORT               PORTBbits.RB0
#define BT_WPU                WPUBbits.WPUB0
#define BT_ANS                ANSELBbits.ANSB0
#define BT_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define BT_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define BT_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define BT_GetValue()           PORTBbits.RB0
#define BT_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define BT_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define BT_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define BT_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define BT_SetAnalogMode()  do { ANSELBbits.ANSB0 = 1; } while(0)
#define BT_SetDigitalMode() do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set SCL aliases
#define SCL_TRIS               TRISCbits.TRISC3
#define SCL_LAT                LATCbits.LATC3
#define SCL_PORT               PORTCbits.RC3
#define SCL_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCL_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCL_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCL_GetValue()           PORTCbits.RC3
#define SCL_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set SDA aliases
#define SDA_TRIS               TRISCbits.TRISC4
#define SDA_LAT                LATCbits.LATC4
#define SDA_PORT               PORTCbits.RC4
#define SDA_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDA_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDA_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDA_GetValue()           PORTCbits.RC4
#define SDA_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set EE_WP aliases
#define EE_WP_TRIS               TRISCbits.TRISC5
#define EE_WP_LAT                LATCbits.LATC5
#define EE_WP_PORT               PORTCbits.RC5
#define EE_WP_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define EE_WP_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define EE_WP_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define EE_WP_GetValue()           PORTCbits.RC5
#define EE_WP_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define EE_WP_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

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