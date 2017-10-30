#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
#include <xc.h>

#define BT1_SetHigh()           LATEbits.LATE0=1
#define BT1_SetLow()            LATEbits.LATE0=0
#define BT1_Toggle()            LATEbits.LATE0=~LATEbits.LATE0
#define BT1_GetValue()          PORTEbits.RE0
#define BT1_SetDigitalInput()   TRISEbits.TRISE0=1
#define BT1_SetDigitalOutput()  TRISEbits.TRISE0=0

#define BT2_SetHigh()           LATEbits.LATE2=1
#define BT2_SetLow()            LATEbits.LATE2=0
#define BT2_Toggle()            LATEbits.LATE2=~LATEbits.LATE2
#define BT2_GetValue()          PORTEbits.RE2
#define BT2_SetDigitalInput()   TRISEbits.TRISE2=1
#define BT2_SetDigitalOutput()  TRISEbits.TRISE2=0

#define BT3_SetHigh()           LATEbits.LATE5=1
#define BT3_SetLow()            LATEbits.LATE5=0
#define BT3_Toggle()            LATEbits.LATE5=~LATEbits.LATE5
#define BT3_GetValue()          PORTEbits.RE5
#define BT3_SetDigitalInput()   TRISEbits.TRISE5=1
#define BT3_SetDigitalOutput()  TRISEbits.TRISE5=0

#define D1_SetHigh()            LATEbits.LATE1=1
#define D1_SetLow()             LATEbits.LATE1=0
#define D1_Toggle()             LATEbits.LATE1=~LATEbits.LATE1
#define D1_GetValue()           PORTEbits.RE1
#define D1_SetState(x)          LATEbits.LATE1=x
#define D1_SetDigitalInput()    TRISEbits.TRISE1=1
#define D1_SetDigitalOutput()   TRISEbits.TRISE1=0

#define D2_SetHigh()            LATEbits.LATE3=1
#define D2_SetLow()             LATEbits.LATE3=0
#define D2_Toggle()             LATEbits.LATE3=~LATEbits.LATE3
#define D2_GetValue()           PORTEbits.RE3
#define D2_SetState(x)          LATEbits.LATE3=x
#define D2_SetDigitalInput()    TRISEbits.TRISE3=1
#define D2_SetDigitalOutput()   TRISEbits.TRISE3=0

#define D3_SetHigh()            LATEbits.LATE4=1
#define D3_SetLow()             LATEbits.LATE4=0
#define D3_Toggle()             LATEbits.LATE4=~LATEbits.LATE4
#define D3_GetValue()           PORTEbits.RE4
#define D3_SetState(x)          LATEbits.LATE4=x
#define D3_SetDigitalInput()    TRISEbits.TRISE4=1
#define D3_SetDigitalOutput()   TRISEbits.TRISE4=0

#define D5_SetHigh()            LATDbits.LATD3=1
#define D5_SetLow()             LATDbits.LATD3=0
#define D5_Toggle()             LATDbits.LATD3=~LATDbits.LATD3
#define D5_GetValue()           PORTDbits.RD3
#define D5_SetState(x)          LATDbits.LATD3=x
#define D5_SetDigitalInput()    TRISDbits.TRISD3=1
#define D5_SetDigitalOutput()   TRISDbits.TRISD3=0

#define PGD_SetHigh()           LATBbits.LATB8=1
#define PGD_SetLow()            LATBbits.LATB8=0
#define PGD_Toggle()            LATBbits.LATB8=~LATBbits.LATB8
#define PGD_GetValue()          PORTBbits.RB8
#define PGD_SetState(x)         LATBbits.LATB8=x
#define PGD_SetDigitalInput()   TRISBbits.TRISB8=1
#define PGD_SetDigitalOutput()  TRISBbits.TRISB8=0

#define PGC_SetHigh()           LATFbits.LATF0=1
#define PGC_SetLow()            LATFbits.LATF0=0
#define PGC_Toggle()            LATFbits.LATF0=~LATFbits.LATF0
#define PGC_GetValue()          PORTFbits.RF0
#define PGC_SetState(x)         LATFbits.LATF0=x
#define PGC_SetDigitalInput()   TRISFbits.TRISF0=1
#define PGC_SetDigitalOutput()  TRISFbits.TRISF0=0

#define MCLR_SetHigh()          LATGbits.LATG9=1
#define MCLR_SetLow()           LATGbits.LATG9=0
#define MCLR_Toggle()           LATGbits.LATG9=~LATGbits.LATG9
#define MCLR_GetValue()         PORTGbits.RG9
#define MCLR_SetState(x)        LATGbits.LATG9=x
#define MCLR_SetDigitalInput()  TRISGbits.TRISG9=1
#define MCLR_SetDigitalOutput() TRISGbits.TRISG9=0

void PIN_MANAGER_Initialize(void);

#endif