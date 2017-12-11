#ifndef DATA_CONVERT_H
#define	DATA_CONVERT_H
#include <stdint.h>
#include <stdbool.h>

#define HIGH 1
#define LOW  0

#define Unmask_Data(pData, len) Mask_Data(pData, len)

uint32_t Make328A(uint8_t *val);
uint32_t Make328B(uint8_t B3, uint8_t B2, uint8_t B1, uint8_t B0);
uint32_t Make328IA(uint8_t *val);
uint32_t Make328IB(uint8_t B3, uint8_t B2, uint8_t B1, uint8_t B0);
uint16_t Make1632DW(uint32_t val, bool idx);
uint16_t Make168A(uint8_t *val);
uint16_t Make168B(uint8_t B1, uint8_t B0);
uint16_t Make168IA(uint8_t *val);
uint16_t Make168IB(uint8_t B1, uint8_t B0);
uint16_t Byte2Hex_Convert(uint8_t *pDatain, uint16_t len, uint8_t *pDataout);
uint16_t Hex2Byte_Convert(uint8_t *pDatain, uint16_t len, uint8_t *pDataout);

#endif