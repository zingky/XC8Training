#ifndef DATA_CHECK_H
#define DATA_CHECK_H
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool Cmp(uint8_t *str1, uint8_t idx1, const uint8_t *str2, uint8_t len);
bool Contain(uint8_t *str, uint8_t strlen, const uint8_t *sample, uint8_t samlen);
uint16_t Copy(uint8_t *strin, uint8_t *strout);
uint16_t Concatenate(uint8_t *strin1, uint8_t *strin2, uint8_t *strout);

#endif