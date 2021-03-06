#include "Data_Convert.h"

uint8_t Make816(uint16_t value, bool idx)
{
    return ((uint8_t *) &value)[idx];
}

uint8_t Make832(uint32_t value, uint8_t idx)
{
    return ((uint8_t *) &value)[idx];
}

uint16_t Make168(uint8_t HByte, uint8_t LByte)
{
    uint16_t res=HByte;
    res<<=8;
    res|=LByte;
    return res;
}

uint16_t Make168a(uint8_t *data)
{
    return Make168(&data[0], &data[1]);
}
