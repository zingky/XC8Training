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

// get/set LED aliases
#define LED_TRIS               TRISCbits.TRISC1
#define LED_LAT                LATCbits.LATC1
#define LED_PORT               PORTCbits.RC1
#define LED_SetHigh()            LATCbits.LATC1 = 1
#define LED_SetLow()             LATCbits.LATC1 = 0
#define LED_Toggle()             LATCbits.LATC1 = ~LATCbits.LATC1
#define LED_GetValue()           PORTCbits.RC1
#define LED_SetDigitalInput()    TRISCbits.TRISC1 = 1
#define LED_SetDigitalOutput()   TRISCbits.TRISC1 = 0

// get/set FCS aliases
#define FCS_TRIS               TRISCbits.TRISC2
#define FCS_LAT                LATCbits.LATC2
#define FCS_PORT               PORTCbits.RC2
#define FCS_SetHigh()            LATCbits.LATC2 = 1
#define FCS_SetLow()             LATCbits.LATC2 = 0
#define FCS_Toggle()             LATCbits.LATC2 = ~LATCbits.LATC2
#define FCS_GetValue()           PORTCbits.RC2
#define FCS_SetDigitalInput()    TRISCbits.TRISC2 = 1
#define FCS_SetDigitalOutput()   TRISCbits.TRISC2 = 0

// get/set RC3 procedures
#define RC3_SetHigh()    LATCbits.LATC3 = 1
#define RC3_SetLow()   LATCbits.LATC3 = 0
#define RC3_Toggle()   LATCbits.LATC3 = ~LATCbits.LATC3
#define RC3_GetValue()         PORTCbits.RC3
#define RC3_SetDigitalInput()   TRISCbits.TRISC3 = 1
#define RC3_SetDigitalOutput()  TRISCbits.TRISC3 = 0

// get/set RC4 procedures
#define RC4_SetHigh()    LATCbits.LATC4 = 1
#define RC4_SetLow()   LATCbits.LATC4 = 0
#define RC4_Toggle()   LATCbits.LATC4 = ~LATCbits.LATC4
#define RC4_GetValue()         PORTCbits.RC4
#define RC4_SetDigitalInput()   TRISCbits.TRISC4 = 1
#define RC4_SetDigitalOutput()  TRISCbits.TRISC4 = 0

// get/set RC5 procedures
#define RC5_SetHigh()    LATCbits.LATC5 = 1
#define RC5_SetLow()   LATCbits.LATC5 = 0
#define RC5_Toggle()   LATCbits.LATC5 = ~LATCbits.LATC5
#define RC5_GetValue()         PORTCbits.RC5
#define RC5_SetDigitalInput()   TRISCbits.TRISC5 = 1
#define RC5_SetDigitalOutput()  TRISCbits.TRISC5 = 0

// get/set RC6 procedures
#define RC6_SetHigh()    LATCbits.LATC6 = 1
#define RC6_SetLow()   LATCbits.LATC6 = 0
#define RC6_Toggle()   LATCbits.LATC6 = ~LATCbits.LATC6
#define RC6_GetValue()         PORTCbits.RC6
#define RC6_SetDigitalInput()   TRISCbits.TRISC6 = 1
#define RC6_SetDigitalOutput()  TRISCbits.TRISC6 = 0

// get/set RC7 procedures
#define RC7_SetHigh()    LATCbits.LATC7 = 1
#define RC7_SetLow()   LATCbits.LATC7 = 0
#define RC7_Toggle()   LATCbits.LATC7 = ~LATCbits.LATC7
#define RC7_GetValue()         PORTCbits.RC7
#define RC7_SetDigitalInput()   TRISCbits.TRISC7 = 1
#define RC7_SetDigitalOutput()  TRISCbits.TRISC7 = 0

void PIN_MANAGER_Initialize(void);

#endif