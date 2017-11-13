#ifndef SOFTWARE_UART_H
#define	SOFTWARE_UART_H
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    uint8_t SUTX;
    uint8_t SURX;
    bool SUBS;
} software_uart_t;

software_uart_t SUART;

void Software_UART_Putc(uint8_t c);
void Software_UART_Getc();
void Software_UART_Init();

#endif