#ifndef _UART4_H
#define _UART4_H
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#define UART4_DataReady  (U4STAbits.URXDA == 1)

void UART4_Initialize(void);
bool UART_RX(uint8_t *byte);
void UART_TX(uint8_t txChar);
void UART_Puts(uint8_t *s);

#endif