#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT                   1
#define OUTPUT                  0
#define HIGH                    1
#define LOW                     0
#define ANALOG                  1
#define DIGITAL                 0
#define PULL_UP_ENABLED         1
#define PULL_UP_DISABLED        0
// get/set TXD aliases
#define TXD_TRIS                TRISAbits.TRISA1
#define TXD_LAT                 LATAbits.LATA1
#define TXD_PORT                PORTAbits.RA1
#define TXD_WPU                 WPUAbits.WPUA1
#define TXD_ANS                 ANSELAbits.ANSA1
#define TXD_SetHigh()           LATAbits.LATA1 = 1
#define TXD_SetLow()            LATAbits.LATA1 = 0
#define TXD_Toggle()            LATAbits.LATA1 = ~LATAbits.LATA1
#define TXD_GetValue()          PORTAbits.RA1
#define TXD_SetDigitalInput()   TRISAbits.TRISA1 = 1
#define TXD_SetDigitalOutput()  TRISAbits.TRISA1 = 0
#define TXD_SetPullup()         WPUAbits.WPUA1 = 1
#define TXD_ResetPullup()       WPUAbits.WPUA1 = 0
#define TXD_SetAnalogMode()     ANSELAbits.ANSA1 = 1
#define TXD_SetDigitalMode()    ANSELAbits.ANSA1 = 0
// get/set RA2 procedures
#define RA2_SetHigh()           LATAbits.LATA2 = 1
#define RA2_SetLow()            LATAbits.LATA2 = 0
#define RA2_Toggle()            LATAbits.LATA2 = ~LATAbits.LATA2
#define RA2_GetValue()          PORTAbits.RA2
#define RA2_SetDigitalInput()   TRISAbits.TRISA2 = 1
#define RA2_SetDigitalOutput()  TRISAbits.TRISA2 = 0
#define RA2_SetPullup()         WPUAbits.WPUA2 = 1
#define RA2_ResetPullup()       WPUAbits.WPUA2 = 0
#define RA2_SetAnalogMode()     ANSELAbits.ANSA2 = 1
#define RA2_SetDigitalMode()    ANSELAbits.ANSA2 = 0

void PIN_MANAGER_Initialize (void);

#endif