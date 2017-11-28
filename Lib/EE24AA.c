#include "EE24AA.h"
#include "../SGHost.X/mcc_generated_files/i2c.h"
#include "../SGHost.X/mcc_generated_files/pin_manager.h"

bool EXT_EEPROM_Ready()
{
    bool ack;
    i2c_start();
    ack=i2c_write(0xa0);
    i2c_stop();
    return !ack;
}

void EXT_EEPROM_WriteByte(uint16_t address, uint8_t data)
{   
    while(!EXT_EEPROM_Ready());
    i2c_start();
    i2c_write((0xa0|(uint8_t) (address>>7))&0xfe);
    i2c_write(address);
    i2c_write(data);
    i2c_stop();
}

uint8_t EXT_EEPROM_ReadByte(uint16_t address)
{
    uint8_t data;
    while(!EXT_EEPROM_Ready());
    i2c_start();
    i2c_write((0xa0|(uint8_t) (address>>7))&0xfe);
    i2c_write(address);
    i2c_start();
    i2c_write((0xa0|(uint8_t) (address>>7))|1);
    data=i2c_read();
    i2c_stop();
    return (data);
}

void EXT_EEPROM_WriteArray(uint16_t start_address, uint8_t byte_count, uint8_t *data)
{
    while(byte_count>0)
    {
        EXT_EEPROM_WriteByte(start_address++, *data++);
        byte_count--;
    }
}

void EXT_EEPROM_ReadArray(uint16_t start_address, uint8_t byte_count, uint8_t *data)
{
    while(byte_count>0)
    {
        *data=EXT_EEPROM_ReadByte(start_address++);
        data++;
        byte_count--;
    }
}

void EXT_EEPROM_EraseBlock(uint16_t start_address, uint8_t byte_count)
{
    while(byte_count>0)
    {
        EXT_EEPROM_WriteByte(start_address++, 0);
        byte_count--;
    }
}