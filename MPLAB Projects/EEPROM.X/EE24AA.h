#ifndef EE24AA_H
#define EE24AA_H
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

bool EXT_EEPROM_Ready();
void EXT_EEPROM_WriteByte(uint16_t address, uint8_t data);
uint8_t EXT_EEPROM_ReadByte(uint16_t address);
void EXT_EEPROM_WriteArray(uint16_t start_address, uint8_t byte_count, uint8_t *data);
void EXT_EEPROM_ReadArray(uint16_t start_address, uint8_t byte_count, uint8_t *data);
void EXT_EEPROM_EraseBlock(uint16_t start_address, uint8_t byte_count);

#endif