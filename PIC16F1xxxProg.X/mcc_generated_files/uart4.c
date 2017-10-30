#include "uart4.h"

void UART4_Initialize(void)
{
    // STSEL 1S; IREN disabled; PDSEL 8N; RTSMD disabled; RXINV disabled; SIDL disabled; WAKE disabled; ABAUD disabled; LPBACK disabled; BRGH enabled; UEN TX_RX; ON enabled; 
    U4MODE=0x8008;
    // UTXISEL TX_ONE_CHAR; UTXINV disabled; ADDR 0; URXEN disabled; OERR disabled; ADM_EN disabled; URXISEL RX_ONE_CHAR; UTXBRK disabled; UTXEN disabled; ADDEN disabled; 
    U4STA=0x0;
    // BaudRate = 10000; Frequency = 48000000 Hz; BRG 1199; 
    U4BRG=0x4AF;
    U4STAbits.UTXEN=1;
    U4STAbits.URXEN=1;
}

bool UART_RX(uint8_t *byte)
{
    if(U4STA&0x000E)
    {
        uint32_t dummy=U4RXREG;
        U4STAbits.OERR=0;
    }
    if(U4STAbits.URXDA)
    {
        *byte=U4RXREG;
        return 1;
    }
    return 0;
}

void UART_TX(uint8_t txChar)
{
    U4TXREG=txChar;
    while(!U4STAbits.TRMT);
}

void UART_Puts(uint8_t *s)
{
    while(*s!=0) UART_TX(*s++);
}