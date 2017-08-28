#ifndef _SPI_H
#define _SPI_H

#include <stdbool.h>
#include <stdint.h>

void SPI_Initialize(void);
void SPI_Xfer(bool enCS, uint8_t *data, uint8_t lenIn, uint8_t lenOut, bool dnCS);

#endif