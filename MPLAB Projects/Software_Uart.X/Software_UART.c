#include "Software_UART.h"
#include "mcc_generated_files/ext_int.h"
#include "mcc_generated_files/pin_manager.h"

uint8_t i, res;
uint8_t SUBUFF;

uint16_t Manchester_Coder(uint8_t data)
{
    res=0;
    for(i=0; i<8; i++)
    {
        res<<=2;
        if(data&0x80) res|=0x10;
        else res|=0x01;
        data>>=1;
    }
    return res;
}

uint8_t Manchester_Decoder(uint16_t c)
{
    res=0;
    for(i=0; i<16; i++)
    {
        res<<=1;
        if((data&0x1000)==0x1000) res|=1;
        else res|=0;
        data<<=2;
    }
    return res;
}

void Software_UART_Delay(uint8_t x)
{
    while(x--);
}

void Software_UART_Putc_ISR()
{
    TXD_LAT=0;
    Software_UART_Delay(115);
    for(i=0; i<16; i++)
    {
        TXD_LAT=(bool) SUBUFF;
        SUBUFF>>=1;
        Software_UART_Delay(116);
    }
    TXD_LAT=1;
    Software_UART_Delay(117);
}

void Software_UART_Putc(uint8_t c)
{

}

void Software_UART_Getc()
{

}

void Software_UART_Init()
{
    EXT_INT_InterruptFlagClear();
    SUART.SURX=0;
    SUART.SUTX=0;
    SUART.SUBS=0;
}
