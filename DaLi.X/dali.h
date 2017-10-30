#ifndef DALI_H
#define	DALI_H
#include <stdbool.h>
#include <stdint.h>

struct
{
    uint8_t RXD;// Receive register
    uint8_t TXD;// Transmit register
    uint8_t bitCount;
    bool busy;
} DALI;

void Dali_Xfer();
void Dali_Init();
#endif