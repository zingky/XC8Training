#include "mcc_generated_files/mcc.h"
#define Port_Toggle(PORT)   PORT=~PORT

//uint8_t i, data;

//void Ef1()
//{
//    for(i=0; i<10; i++)
//    {
//        Port_Toggle(LATA);
//        Port_Toggle(LATB);
//        Port_Toggle(LATC);
//        __delay_ms(100);
//    }
//}
//
//void Ef2()
//{
//    for(i=0, data=0x01; i<8; i++)
//    {
//        LATA=data;
//        data<<=1;
//        __delay_ms(100);
//    }
//    LATA=0;
//    
//    for(i=0, data=0x01; i<8; i++)
//    {
//        LATB=data;
//        data<<=1;
//        __delay_ms(100);
//    }
//    LATB=0;
//    
//    for(i=0, data=0x01; i<8; i++)
//    {
//        LATC=data;
//        data<<=1;
//        __delay_ms(100);
//    }
//    LATC=0;
//}
//
//void Ef3()
//{
//    for(i=0, data=0x80; i<8; i++)
//    {
//        LATC=data;
//        data>>=1;
//        __delay_ms(100);
//    }
//    LATC=0;
//    
//    for(i=0, data=0x80; i<8; i++)
//    {
//        LATB=data;
//        data>>=1;
//        __delay_ms(100);
//    }
//    LATB=0;
//    
//    for(i=0, data=0x80; i<8; i++)
//    {
//        LATA=data;
//        data>>=1;
//        __delay_ms(100);
//    }
//    LATA=0;
//}
//
//void Ef4()
//{
//    LATA=0b10101010;
//    LATB=0b10101010;
//    LATC=0b10101010;
//    for(i=0; i<10; i++)
//    {
//        __delay_ms(100);
//        Port_Toggle(LATA);
//        Port_Toggle(LATB);
//        Port_Toggle(LATC);
//    }
//    LATA=0x00;
//    LATB=0x00;
//    LATC=0x00;
//}

uint8_t rotateleft(uint8_t data, uint8_t nbit)
{
    return (uint8_t)((data<<nbit)|(data>>(8-nbit)));
}

uint8_t rotateright(uint8_t data, uint8_t nbit)
{
    return (uint8_t)((data>>nbit)|(data<<(8-nbit)));
}

void main(void)
{
    SYSTEM_Initialize();
    LATA=0x00;// Port A is low
    LATB=0x00;// Port B is low
    LATC=0x00;// Port C is low
    TRISA=0x00;// Port A is an output port
    TRISB=0x00;// Port B is an output port
    TRISC=0x00;// Port C is an output port
    ANSELA=0x00;// Turn off all analog in port A
    ANSELB=0x00;// Turn off all analog in port B
    // No Analog pin in port C
    while (1)
    {
        uint8_t i, data=0x55;
        for(i=0; i<8; i++)
        {
            LATA=rotateleft(data, i);
            LATC=rotateright(data, i);
            __delay_ms(1000);
        }
//        Ef1();
//        Ef2();
//        Ef3();
//        Ef4();
    }
}