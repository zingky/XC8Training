#ifndef _EUSART_H
#define _EUSART_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#define EUSART_DataReady()  (eusartRxCount)

extern volatile uint8_t eusartTxBufferRemaining;
extern volatile uint8_t eusartRxCount;

void EUSART_Initialize(void);
uint8_t EUSART_Read(void);
void EUSART_Write(uint8_t txData);
void EUSART_Receive_ISR(void);

#endif