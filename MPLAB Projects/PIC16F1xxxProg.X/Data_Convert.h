#ifndef DATA_CONVERT_H
#define	DATA_CONVERT_H
#include <stdint.h>
#include <stdbool.h>

#define HIGH 1
#define LOW  0

uint32_t Make328(uint8_t *val);                                                 // Make 32bit value from 8bit array. ex: val[]={0x01, 0x02, 0x03, 0x04, 0x05}; Make328(val)=0x01020304
uint32_t Make328I(uint8_t *val);                                                // Make 32bit value from 8bit array. ex: val[]={0x01, 0x02, 0x03, 0x04, 0x05}; Make328I(val)=0x04030201
uint32_t Make328B(uint8_t MB, uint8_t UB, uint8_t HB, uint8_t LB);              // Make 32bit value from 4x8bit value. ex: val1=0x01, val2=0x02, val=0x03, val4=0x04; Make328B(val1, val2, val3, val4)=0x01020304
uint16_t Make1632(uint32_t val, bool idx);                                      // Make 16bit value from 32bit value. ex: val=0x12345678; Make1632(val, HIGH)=0x1234; Make1632(val, LOW)=0x5678
uint16_t Make168(uint8_t *val);                                                 // Make 16bit value from 8bit array. ex: val[]={0x01, 0x02, 0x03}; Make168(val)=0x0102
uint16_t Make168I(uint8_t *val);                                                // Make 16bit value from 8bit array. ex: val[]={0x01, 0x02, 0x03}; Make168I(val)=0x0201

#endif