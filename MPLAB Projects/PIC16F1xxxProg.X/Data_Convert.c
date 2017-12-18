#include "Data_Convert.h"

uint32_t Make328(uint8_t *val)                                                  // <editor-fold defaultstate="collapsed" desc="Combine 4 Bytes to a 32-bit Word">
{
    uint32_t res=val[0];
    res<<=8;
    res|=val[1];
    res<<=8;
    res|=val[2];
    res<<=8;
    res|=val[3];
    return res;
}                                                                               // </editor-fold>

uint32_t Make328I(uint8_t *val)                                                 // <editor-fold defaultstate="collapsed" desc="Combine 4 Bytes to a 32-bit Word">
{
    uint32_t res=0x00;                                                          // The highest data bytes of 16Bit MCU are 0x00
    res<<=8;
    res|=val[2];
    res<<=8;
    res|=val[1];
    res<<=8;
    res|=val[0];
    return res;
}                                                                               // </editor-fold>

uint32_t Make328B(uint8_t MB, uint8_t UB, uint8_t HB, uint8_t LB)               // <editor-fold defaultstate="collapsed" desc="Combine 4 Bytes to a 32-bit Word">
{
    uint32_t res=MB;
    res<<=8;
    res|=UB;
    res<<=8;
    res|=HB;
    res<<=8;
    res|=LB;
    return res;
}                                                                               // </editor-fold>

uint16_t Make1632(uint32_t val, bool idx)                                       // <editor-fold defaultstate="collapsed" desc="Decombine a 32-bit DWord to 16-bit Word">
{
    if(idx) val>>=16;
    return (uint16_t) val;
}                                                                               // </editor-fold>

uint16_t Make168(uint8_t *val)                                                  // <editor-fold defaultstate="collapsed" desc="Combine a 16-bit Word from 2 bytes - Little endian">
{
    uint16_t res=val[0];
    res<<=8;
    res|=val[1];
    return res;
}                                                                               // </editor-fold>

uint16_t Make168I(uint8_t *val)                                                 // <editor-fold defaultstate="collapsed" desc="Combine a 16-bit Word from 2 bytes - Big endian">
{
    uint16_t res=val[1];
    res<<=8;
    res|=val[0];
    return res;
}                                                                               // </editor-fold>