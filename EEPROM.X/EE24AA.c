#include "EE24AA.h"
#include "mcc_generated_files/pin_manager.h"
#include "MSSP_I2C_Master.h"

bool EXT_EEPROM_Ready()
{
    bool ack;
    I2C_Start();
    ack=I2C_Write(0xa0);
    I2C_Stop();
    return !ack;
}

void EXT_EEPROM_WriteByte(uint16_t address, uint8_t data)
{
    EE_WP_SetLow();
    while(!EXT_EEPROM_Ready());
    I2C_Start();
    I2C_Write((0xa0|(uint8_t) (address>>7))&0xfe);
    I2C_Write(address);
    I2C_Write(data);
    I2C_Stop();
    EE_WP_SetHigh();
}

uint8_t EXT_EEPROM_ReadByte(uint16_t address)
{
    uint8_t data;

    while(!EXT_EEPROM_Ready());
    I2C_Start();
    I2C_Write((0xa0|(uint8_t) (address>>7))&0xfe);
    I2C_Write(address);
    I2C_Start();
    I2C_Write((0xa0|(uint8_t) (address>>7))|1);
    data=I2C_Read(0);
    I2C_Stop();
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