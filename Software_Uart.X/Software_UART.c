#include "Software_UART.h"
#include "mcc_generated_files/ext_int.h"

struct
{
    uint8_t RXL;
    uint8_t RXH;
    uint8_t TXL;
    uint8_t TXH;
} SUBUFF;

uint8_t i;

inline void Software_UART_Delay()//15 Tcy=15*125ns=1875ns
{
    uint16_t x=SUART.SUBCON;
    while(x--);
}

uint8_t Manchester_Coder(uint8_t data, bool nibble)
{
    uint8_t i;
    uint8_t res=0;
    if(nibble) data>>=4;
    else data&=0x0F;
    for(i=0; i<4; i++)
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
    uint8_t i;
    uint8_t res=0;
    for(i=0; i<16; i++)
    {
        res<<=1;
        if((data&0x1000)==0x1000) res|=1;
        else res|=0;
        data<<=2;
    }
    return res;
}

void Software_UART_Putc_ISR()
{
    TXD_LAT=1;
    Software_UART_Delay();
    for(i=0; i<16; i++)
    {
        
    }
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
    SUART.SUBCON=52; // 1200bps@32MHz FOSC
}
