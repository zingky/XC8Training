#ifndef IO_H
#define	IO_H

#include <stdint.h>
#include <stdbool.h>

#define HIGH    1
#define LOW     0
#define ENABLE  1
#define DISABLE 0
#define INPUT   1
#define OUTPUT  0

#define _DigitalSet(x)      TRIS=x//INPUT or OUTPUT
#define _AnalogSet(x)       ANSEL=x//ENABLE or DISABLE
#define _StateSet(x)        LAT=x//HIGH or LOW
#define _StateGet()         PORT//Return value
#define _Toggle()           =~//Toggle bit
// RED LED
#define RLED_DigitalSet(x)  TRISCbits.TRISC0=x//INPUT or OUTPUT
#define RLED_AnalogSet(x)   //ENABLE or DISABLE
#define RLED_StateSet(x)    LATCbits.LATC0=x//HIGH or LOW
#define RLED_StateGet()     PORTCbits.RC0//Return value    
#define RLED_Toggle()       LATCbits.LATC0=~LATCbits.LATC0//Toggle bit
// GREEN LED
#define GLED_DigitalSet(x)  TRISCbits.TRISC1=x//INPUT or OUTPUT
#define GLED_AnalogSet(x)   //ENABLE or DISABLE
#define GLED_StateSet(x)    LATCbits.LATC1=x//HIGH or LOW
#define GLED_StateGet()     PORTCbits.RC1//Return value     
#define GLED_Toggle()       LATCbits.LATC1=~LATCbits.LATC1//Toggle bit
// BLUE LED
#define BLED_DigitalSet(x)  TRISCbits.TRISC2=x//INPUT or OUTPUT
#define BLED_AnalogSet(x)   //ENABLE or DISABLE
#define BLED_StateSet(x)    LATCbits.LATC2=x//HIGH or LOW
#define BLED_StateGet()     PORTCbits.RC2//Return value  
#define BLED_Toggle()       LATCbits.LATC2=~LATCbits.LATC2//Toggle bit
// YELLOW LED
#define YLED_DigitalSet(x)  TRISCbits.TRISC3=x//INPUT or OUTPUT
#define YLED_AnalogSet(x)   //ENABLE or DISABLE
#define YLED_StateSet(x)    LATCbits.LATC3=x//HIGH or LOW
#define YLED_StateGet()     PORTCbits.RC3//Return value      
#define YLED_Toggle()       LATCbits.LATC3=~LATCbits.LATC3//Toggle bit
// BUTTON 1
#define BT1_DigitalSet(x)   TRISCbits.TRISC4=x//INPUT or OUTPUT
#define BT1_AnalogSet(x)    //ENABLE or DISABLE
#define BT1_StateGet()      PORTCbits.RC4//Return value       
// BUTTON 2
#define BT2_DigitalSet(x)   TRISCbits.TRISC5=x//INPUT or OUTPUT
#define BT2_AnalogSet(x)    //ENABLE or DISABLE
#define BT2_StateGet()      PORTCbits.RC5//Return value      
// BUTTON 3
#define BT3_DigitalSet(x)   TRISCbits.TRISC6=x//INPUT or OUTPUT
#define BT3_AnalogSet(x)    //ENABLE or DISABLE
#define BT3_StateGet()      PORTCbits.RC6//Return value       
// BUTTON 4
#define BT4_DigitalSet(x)   TRISCbits.TRISC7=x//INPUT or OUTPUT
#define BT4_AnalogSet(x)    //ENABLE or DISABLE
#define BT4_StateGet()      PORTCbits.RC7//Return value     

void IO_Config();
bool BT1_Is_Pressed();
bool BT2_Is_Pressed();
bool BT3_Is_Pressed();
bool BT4_Is_Pressed();

#endif