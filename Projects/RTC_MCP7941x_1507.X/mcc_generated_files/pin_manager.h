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
        Device            :  PIC16F1507
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

// get/set MFP_STT aliases
#define MFP_STT_TRIS               TRISAbits.TRISA0
#define MFP_STT_LAT                LATAbits.LATA0
#define MFP_STT_PORT               PORTAbits.RA0
#define MFP_STT_WPU                WPUAbits.WPUA0
#define MFP_STT_ANS                ANSELAbits.ANSA0
#define MFP_STT_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define MFP_STT_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define MFP_STT_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define MFP_STT_GetValue()           PORTAbits.RA0
#define MFP_STT_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define MFP_STT_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define MFP_STT_SetPullup()      do { WPUAbits.WPUA0 = 1; } while(0)
#define MFP_STT_ResetPullup()    do { WPUAbits.WPUA0 = 0; } while(0)
#define MFP_STT_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define MFP_STT_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()    do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()   do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()   do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()         PORTAbits.RA2
#define RA2_SetDigitalInput()   do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()  do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()     do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()   do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode() do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS               TRISCbits.TRISC0
#define RS_LAT                LATCbits.LATC0
#define RS_PORT               PORTCbits.RC0
#define RS_ANS                ANSELCbits.ANSC0
#define RS_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RS_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RS_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RS_GetValue()           PORTCbits.RC0
#define RS_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RS_SetAnalogMode()  do { ANSELCbits.ANSC0 = 1; } while(0)
#define RS_SetDigitalMode() do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set EN aliases
#define EN_TRIS               TRISCbits.TRISC1
#define EN_LAT                LATCbits.LATC1
#define EN_PORT               PORTCbits.RC1
#define EN_ANS                ANSELCbits.ANSC1
#define EN_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define EN_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define EN_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define EN_GetValue()           PORTCbits.RC1
#define EN_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define EN_SetAnalogMode()  do { ANSELCbits.ANSC1 = 1; } while(0)
#define EN_SetDigitalMode() do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS               TRISCbits.TRISC2
#define D4_LAT                LATCbits.LATC2
#define D4_PORT               PORTCbits.RC2
#define D4_ANS                ANSELCbits.ANSC2
#define D4_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define D4_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define D4_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define D4_GetValue()           PORTCbits.RC2
#define D4_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define D4_SetAnalogMode()  do { ANSELCbits.ANSC2 = 1; } while(0)
#define D4_SetDigitalMode() do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS               TRISCbits.TRISC3
#define D5_LAT                LATCbits.LATC3
#define D5_PORT               PORTCbits.RC3
#define D5_ANS                ANSELCbits.ANSC3
#define D5_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define D5_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define D5_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define D5_GetValue()           PORTCbits.RC3
#define D5_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define D5_SetAnalogMode()  do { ANSELCbits.ANSC3 = 1; } while(0)
#define D5_SetDigitalMode() do { ANSELCbits.ANSC3 = 0; } while(0)

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

// get/set SW_SCL aliases
#define SW_SCL_TRIS               TRISCbits.TRISC6
#define SW_SCL_LAT                LATCbits.LATC6
#define SW_SCL_PORT               PORTCbits.RC6
#define SW_SCL_ANS                ANSELCbits.ANSC6
#define SW_SCL_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SW_SCL_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SW_SCL_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SW_SCL_GetValue()           PORTCbits.RC6
#define SW_SCL_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SW_SCL_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SW_SCL_SetAnalogMode()  do { ANSELCbits.ANSC6 = 1; } while(0)
#define SW_SCL_SetDigitalMode() do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set SW_SDA aliases
#define SW_SDA_TRIS               TRISCbits.TRISC7
#define SW_SDA_LAT                LATCbits.LATC7
#define SW_SDA_PORT               PORTCbits.RC7
#define SW_SDA_ANS                ANSELCbits.ANSC7
#define SW_SDA_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SW_SDA_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SW_SDA_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SW_SDA_GetValue()           PORTCbits.RC7
#define SW_SDA_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SW_SDA_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SW_SDA_SetAnalogMode()  do { ANSELCbits.ANSC7 = 1; } while(0)
#define SW_SDA_SetDigitalMode() do { ANSELCbits.ANSC7 = 0; } while(0)

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