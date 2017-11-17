/**
  System Interrupts Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the MPLAB(c) Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for MPLAB(c) Code Configurator interrupts.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC32MX530F128H
        Version           :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC32 1.42
        MPLAB             :  MPLAB X 3.55

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

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>
/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RB8, high using LATBbits.LATB8.

  @Description
    Sets the GPIO pin, RB8, high using LATBbits.LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 high (1)
    ICSPDAT_SetHigh();
    </code>

*/
#define ICSPDAT_SetHigh()          LATBbits.LATB8 = 1
/**
  @Summary
    Sets the GPIO pin, RB8, low using LATBbits.LATB8.

  @Description
    Sets the GPIO pin, RB8, low using LATBbits.LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 low (0)
    ICSPDAT_SetLow();
    </code>

*/
#define ICSPDAT_SetLow()           LATBbits.LATB8 = 0
/**
  @Summary
    Toggles the GPIO pin, RB8, using LATBbits.LATB8.

  @Description
    Toggles the GPIO pin, RB8, using LATBbits.LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB8
    ICSPDAT_Toggle();
    </code>

*/
#define ICSPDAT_Toggle()           LATBbits.LATB8 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB8.

  @Description
    Reads the value of the GPIO pin, RB8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB8
    postValue = ICSPDAT_GetValue();
    </code>

*/
#define ICSPDAT_GetValue()         PORTBbits.RB8
/**
  @Summary
    Configures the GPIO pin, RB8, as an input.

  @Description
    Configures the GPIO pin, RB8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an input
    ICSPDAT_SetDigitalInput();
    </code>

*/
#define ICSPDAT_SetDigitalInput()  TRISBbits.TRISB8 = 1
/**
  @Summary
    Configures the GPIO pin, RB8, as an output.

  @Description
    Configures the GPIO pin, RB8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an output
    ICSPDAT_SetDigitalOutput();
    </code>

*/
#define ICSPDAT_SetDigitalOutput() TRISBbits.TRISB8 = 0
/**
  @Summary
    Sets the GPIO pin, RD3, high using LATDbits.LATD3.

  @Description
    Sets the GPIO pin, RD3, high using LATDbits.LATD3.

  @Preconditions
    The RD3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD3 high (1)
    D5_SetHigh();
    </code>

*/
#define D5_SetHigh()          LATDbits.LATD3 = 1
/**
  @Summary
    Sets the GPIO pin, RD3, low using LATDbits.LATD3.

  @Description
    Sets the GPIO pin, RD3, low using LATDbits.LATD3.

  @Preconditions
    The RD3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD3 low (0)
    D5_SetLow();
    </code>

*/
#define D5_SetLow()           LATDbits.LATD3 = 0
/**
  @Summary
    Toggles the GPIO pin, RD3, using LATDbits.LATD3.

  @Description
    Toggles the GPIO pin, RD3, using LATDbits.LATD3.

  @Preconditions
    The RD3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD3
    D5_Toggle();
    </code>

*/
#define D5_Toggle()           LATDbits.LATD3 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD3.

  @Description
    Reads the value of the GPIO pin, RD3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD3
    postValue = D5_GetValue();
    </code>

*/
#define D5_GetValue()         PORTDbits.RD3
/**
  @Summary
    Configures the GPIO pin, RD3, as an input.

  @Description
    Configures the GPIO pin, RD3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD3 as an input
    D5_SetDigitalInput();
    </code>

*/
#define D5_SetDigitalInput()  TRISDbits.TRISD3 = 1
/**
  @Summary
    Configures the GPIO pin, RD3, as an output.

  @Description
    Configures the GPIO pin, RD3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD3 as an output
    D5_SetDigitalOutput();
    </code>

*/
#define D5_SetDigitalOutput() TRISDbits.TRISD3 = 0
/**
  @Summary
    Sets the GPIO pin, RE0, high using LATEbits.LATE0.

  @Description
    Sets the GPIO pin, RE0, high using LATEbits.LATE0.

  @Preconditions
    The RE0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE0 high (1)
    BT1_SetHigh();
    </code>

*/
#define BT1_SetHigh()          LATEbits.LATE0 = 1
/**
  @Summary
    Sets the GPIO pin, RE0, low using LATEbits.LATE0.

  @Description
    Sets the GPIO pin, RE0, low using LATEbits.LATE0.

  @Preconditions
    The RE0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE0 low (0)
    BT1_SetLow();
    </code>

*/
#define BT1_SetLow()           LATEbits.LATE0 = 0
/**
  @Summary
    Toggles the GPIO pin, RE0, using LATEbits.LATE0.

  @Description
    Toggles the GPIO pin, RE0, using LATEbits.LATE0.

  @Preconditions
    The RE0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE0
    BT1_Toggle();
    </code>

*/
#define BT1_Toggle()           LATEbits.LATE0 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE0.

  @Description
    Reads the value of the GPIO pin, RE0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE0
    postValue = BT1_GetValue();
    </code>

*/
#define BT1_GetValue()         PORTEbits.RE0
/**
  @Summary
    Configures the GPIO pin, RE0, as an input.

  @Description
    Configures the GPIO pin, RE0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE0 as an input
    BT1_SetDigitalInput();
    </code>

*/
#define BT1_SetDigitalInput()  TRISEbits.TRISE0 = 1
/**
  @Summary
    Configures the GPIO pin, RE0, as an output.

  @Description
    Configures the GPIO pin, RE0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE0 as an output
    BT1_SetDigitalOutput();
    </code>

*/
#define BT1_SetDigitalOutput() TRISEbits.TRISE0 = 0
/**
  @Summary
    Sets the GPIO pin, RE1, high using LATEbits.LATE1.

  @Description
    Sets the GPIO pin, RE1, high using LATEbits.LATE1.

  @Preconditions
    The RE1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE1 high (1)
    D1_SetHigh();
    </code>

*/
#define D1_SetHigh()          LATEbits.LATE1 = 1
/**
  @Summary
    Sets the GPIO pin, RE1, low using LATEbits.LATE1.

  @Description
    Sets the GPIO pin, RE1, low using LATEbits.LATE1.

  @Preconditions
    The RE1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE1 low (0)
    D1_SetLow();
    </code>

*/
#define D1_SetLow()           LATEbits.LATE1 = 0
/**
  @Summary
    Toggles the GPIO pin, RE1, using LATEbits.LATE1.

  @Description
    Toggles the GPIO pin, RE1, using LATEbits.LATE1.

  @Preconditions
    The RE1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE1
    D1_Toggle();
    </code>

*/
#define D1_Toggle()           LATEbits.LATE1 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE1.

  @Description
    Reads the value of the GPIO pin, RE1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE1
    postValue = D1_GetValue();
    </code>

*/
#define D1_GetValue()         PORTEbits.RE1
/**
  @Summary
    Configures the GPIO pin, RE1, as an input.

  @Description
    Configures the GPIO pin, RE1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE1 as an input
    D1_SetDigitalInput();
    </code>

*/
#define D1_SetDigitalInput()  TRISEbits.TRISE1 = 1
/**
  @Summary
    Configures the GPIO pin, RE1, as an output.

  @Description
    Configures the GPIO pin, RE1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE1 as an output
    D1_SetDigitalOutput();
    </code>

*/
#define D1_SetDigitalOutput() TRISEbits.TRISE1 = 0
/**
  @Summary
    Sets the GPIO pin, RE2, high using LATEbits.LATE2.

  @Description
    Sets the GPIO pin, RE2, high using LATEbits.LATE2.

  @Preconditions
    The RE2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE2 high (1)
    BT2_SetHigh();
    </code>

*/
#define BT2_SetHigh()          LATEbits.LATE2 = 1
/**
  @Summary
    Sets the GPIO pin, RE2, low using LATEbits.LATE2.

  @Description
    Sets the GPIO pin, RE2, low using LATEbits.LATE2.

  @Preconditions
    The RE2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE2 low (0)
    BT2_SetLow();
    </code>

*/
#define BT2_SetLow()           LATEbits.LATE2 = 0
/**
  @Summary
    Toggles the GPIO pin, RE2, using LATEbits.LATE2.

  @Description
    Toggles the GPIO pin, RE2, using LATEbits.LATE2.

  @Preconditions
    The RE2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE2
    BT2_Toggle();
    </code>

*/
#define BT2_Toggle()           LATEbits.LATE2 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE2.

  @Description
    Reads the value of the GPIO pin, RE2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE2
    postValue = BT2_GetValue();
    </code>

*/
#define BT2_GetValue()         PORTEbits.RE2
/**
  @Summary
    Configures the GPIO pin, RE2, as an input.

  @Description
    Configures the GPIO pin, RE2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE2 as an input
    BT2_SetDigitalInput();
    </code>

*/
#define BT2_SetDigitalInput()  TRISEbits.TRISE2 = 1
/**
  @Summary
    Configures the GPIO pin, RE2, as an output.

  @Description
    Configures the GPIO pin, RE2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE2 as an output
    BT2_SetDigitalOutput();
    </code>

*/
#define BT2_SetDigitalOutput() TRISEbits.TRISE2 = 0
/**
  @Summary
    Sets the GPIO pin, RE3, high using LATEbits.LATE3.

  @Description
    Sets the GPIO pin, RE3, high using LATEbits.LATE3.

  @Preconditions
    The RE3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE3 high (1)
    D2_SetHigh();
    </code>

*/
#define D2_SetHigh()          LATEbits.LATE3 = 1
/**
  @Summary
    Sets the GPIO pin, RE3, low using LATEbits.LATE3.

  @Description
    Sets the GPIO pin, RE3, low using LATEbits.LATE3.

  @Preconditions
    The RE3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE3 low (0)
    D2_SetLow();
    </code>

*/
#define D2_SetLow()           LATEbits.LATE3 = 0
/**
  @Summary
    Toggles the GPIO pin, RE3, using LATEbits.LATE3.

  @Description
    Toggles the GPIO pin, RE3, using LATEbits.LATE3.

  @Preconditions
    The RE3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE3
    D2_Toggle();
    </code>

*/
#define D2_Toggle()           LATEbits.LATE3 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE3.

  @Description
    Reads the value of the GPIO pin, RE3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE3
    postValue = D2_GetValue();
    </code>

*/
#define D2_GetValue()         PORTEbits.RE3
/**
  @Summary
    Configures the GPIO pin, RE3, as an input.

  @Description
    Configures the GPIO pin, RE3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE3 as an input
    D2_SetDigitalInput();
    </code>

*/
#define D2_SetDigitalInput()  TRISEbits.TRISE3 = 1
/**
  @Summary
    Configures the GPIO pin, RE3, as an output.

  @Description
    Configures the GPIO pin, RE3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE3 as an output
    D2_SetDigitalOutput();
    </code>

*/
#define D2_SetDigitalOutput() TRISEbits.TRISE3 = 0
/**
  @Summary
    Sets the GPIO pin, RE4, high using LATEbits.LATE4.

  @Description
    Sets the GPIO pin, RE4, high using LATEbits.LATE4.

  @Preconditions
    The RE4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE4 high (1)
    D3_SetHigh();
    </code>

*/
#define D3_SetHigh()          LATEbits.LATE4 = 1
/**
  @Summary
    Sets the GPIO pin, RE4, low using LATEbits.LATE4.

  @Description
    Sets the GPIO pin, RE4, low using LATEbits.LATE4.

  @Preconditions
    The RE4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE4 low (0)
    D3_SetLow();
    </code>

*/
#define D3_SetLow()           LATEbits.LATE4 = 0
/**
  @Summary
    Toggles the GPIO pin, RE4, using LATEbits.LATE4.

  @Description
    Toggles the GPIO pin, RE4, using LATEbits.LATE4.

  @Preconditions
    The RE4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE4
    D3_Toggle();
    </code>

*/
#define D3_Toggle()           LATEbits.LATE4 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE4.

  @Description
    Reads the value of the GPIO pin, RE4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE4
    postValue = D3_GetValue();
    </code>

*/
#define D3_GetValue()         PORTEbits.RE4
/**
  @Summary
    Configures the GPIO pin, RE4, as an input.

  @Description
    Configures the GPIO pin, RE4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE4 as an input
    D3_SetDigitalInput();
    </code>

*/
#define D3_SetDigitalInput()  TRISEbits.TRISE4 = 1
/**
  @Summary
    Configures the GPIO pin, RE4, as an output.

  @Description
    Configures the GPIO pin, RE4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE4 as an output
    D3_SetDigitalOutput();
    </code>

*/
#define D3_SetDigitalOutput() TRISEbits.TRISE4 = 0
/**
  @Summary
    Sets the GPIO pin, RE5, high using LATEbits.LATE5.

  @Description
    Sets the GPIO pin, RE5, high using LATEbits.LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE5 high (1)
    BT3_SetHigh();
    </code>

*/
#define BT3_SetHigh()          LATEbits.LATE5 = 1
/**
  @Summary
    Sets the GPIO pin, RE5, low using LATEbits.LATE5.

  @Description
    Sets the GPIO pin, RE5, low using LATEbits.LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE5 low (0)
    BT3_SetLow();
    </code>

*/
#define BT3_SetLow()           LATEbits.LATE5 = 0
/**
  @Summary
    Toggles the GPIO pin, RE5, using LATEbits.LATE5.

  @Description
    Toggles the GPIO pin, RE5, using LATEbits.LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE5
    BT3_Toggle();
    </code>

*/
#define BT3_Toggle()           LATEbits.LATE5 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE5.

  @Description
    Reads the value of the GPIO pin, RE5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE5
    postValue = BT3_GetValue();
    </code>

*/
#define BT3_GetValue()         PORTEbits.RE5
/**
  @Summary
    Configures the GPIO pin, RE5, as an input.

  @Description
    Configures the GPIO pin, RE5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE5 as an input
    BT3_SetDigitalInput();
    </code>

*/
#define BT3_SetDigitalInput()  TRISEbits.TRISE5 = 1
/**
  @Summary
    Configures the GPIO pin, RE5, as an output.

  @Description
    Configures the GPIO pin, RE5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE5 as an output
    BT3_SetDigitalOutput();
    </code>

*/
#define BT3_SetDigitalOutput() TRISEbits.TRISE5 = 0
/**
  @Summary
    Sets the GPIO pin, RF0, high using LATFbits.LATF0.

  @Description
    Sets the GPIO pin, RF0, high using LATFbits.LATF0.

  @Preconditions
    The RF0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF0 high (1)
    ICSPCLK_SetHigh();
    </code>

*/
#define ICSPCLK_SetHigh()          LATFbits.LATF0 = 1
/**
  @Summary
    Sets the GPIO pin, RF0, low using LATFbits.LATF0.

  @Description
    Sets the GPIO pin, RF0, low using LATFbits.LATF0.

  @Preconditions
    The RF0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF0 low (0)
    ICSPCLK_SetLow();
    </code>

*/
#define ICSPCLK_SetLow()           LATFbits.LATF0 = 0
/**
  @Summary
    Toggles the GPIO pin, RF0, using LATFbits.LATF0.

  @Description
    Toggles the GPIO pin, RF0, using LATFbits.LATF0.

  @Preconditions
    The RF0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF0
    ICSPCLK_Toggle();
    </code>

*/
#define ICSPCLK_Toggle()           LATFbits.LATF0 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF0.

  @Description
    Reads the value of the GPIO pin, RF0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF0
    postValue = ICSPCLK_GetValue();
    </code>

*/
#define ICSPCLK_GetValue()         PORTFbits.RF0
/**
  @Summary
    Configures the GPIO pin, RF0, as an input.

  @Description
    Configures the GPIO pin, RF0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF0 as an input
    ICSPCLK_SetDigitalInput();
    </code>

*/
#define ICSPCLK_SetDigitalInput()  TRISFbits.TRISF0 = 1
/**
  @Summary
    Configures the GPIO pin, RF0, as an output.

  @Description
    Configures the GPIO pin, RF0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF0 as an output
    ICSPCLK_SetDigitalOutput();
    </code>

*/
#define ICSPCLK_SetDigitalOutput() TRISFbits.TRISF0 = 0
/**
  @Summary
    Sets the GPIO pin, RG9, high using LATGbits.LATG9.

  @Description
    Sets the GPIO pin, RG9, high using LATGbits.LATG9.

  @Preconditions
    The RG9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG9 high (1)
    nMCLR_SetHigh();
    </code>

*/
#define nMCLR_SetHigh()          LATGbits.LATG9 = 1
/**
  @Summary
    Sets the GPIO pin, RG9, low using LATGbits.LATG9.

  @Description
    Sets the GPIO pin, RG9, low using LATGbits.LATG9.

  @Preconditions
    The RG9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG9 low (0)
    nMCLR_SetLow();
    </code>

*/
#define nMCLR_SetLow()           LATGbits.LATG9 = 0
/**
  @Summary
    Toggles the GPIO pin, RG9, using LATGbits.LATG9.

  @Description
    Toggles the GPIO pin, RG9, using LATGbits.LATG9.

  @Preconditions
    The RG9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG9
    nMCLR_Toggle();
    </code>

*/
#define nMCLR_Toggle()           LATGbits.LATG9 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG9.

  @Description
    Reads the value of the GPIO pin, RG9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG9
    postValue = nMCLR_GetValue();
    </code>

*/
#define nMCLR_GetValue()         PORTGbits.RG9
/**
  @Summary
    Configures the GPIO pin, RG9, as an input.

  @Description
    Configures the GPIO pin, RG9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG9 as an input
    nMCLR_SetDigitalInput();
    </code>

*/
#define nMCLR_SetDigitalInput()  TRISGbits.TRISG9 = 1
/**
  @Summary
    Configures the GPIO pin, RG9, as an output.

  @Description
    Configures the GPIO pin, RG9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG9 as an output
    nMCLR_SetDigitalOutput();
    </code>

*/
#define nMCLR_SetDigitalOutput() TRISGbits.TRISG9 = 0

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC32MX530F128H
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the MPLAB(c) Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize(void);

#endif
