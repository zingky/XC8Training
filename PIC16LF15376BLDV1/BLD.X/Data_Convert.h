#ifndef DATA_CONVERT_H
#define	DATA_CONVERT_H
#include <stdbool.h>
#include <stdint.h>

uint8_t Make816(uint16_t value, bool idx);
uint8_t Make832(uint32_t value, uint8_t idx);
uint16_t Make168(uint8_t HByte, uint8_t LByte);
uint16_t Make168a(uint8_t *data, uint8_t idx);

#endif