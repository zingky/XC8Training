#include "Data_Convert.h"

/******************************************************************************/

uint32_t Make328A(uint8_t *val) // <editor-fold defaultstate="collapsed" desc="Combine 4 Bytes to a 32-bit Word">
{
    uint32_t res=val[0];
    res<<=8;
    res|=val[1];
    res<<=8;
    res|=val[2];
    res<<=8;
    res|=val[3];
    return res;
} // </editor-fold>

uint32_t Make328B(uint8_t B3, uint8_t B2, uint8_t B1, uint8_t B0) // <editor-fold defaultstate="collapsed" desc="Combine 4 Bytes to a 32-bit Word">
{
    uint32_t res=B3;
    res<<=8;
    res|=B2;
    res<<=8;
    res|=B1;
    res<<=8;
    res|=B0;
    return res;
} // </editor-fold>

uint32_t Make328IA(uint8_t *val) // <editor-fold defaultstate="collapsed" desc="Combine 4 Bytes to a 32-bit Word">
{
    uint32_t res=val[3]; // The highest data bytes of 16Bit MCU are 0x00
    res<<=8;
    res|=val[2];
    res<<=8;
    res|=val[1];
    res<<=8;
    res|=val[0];
    return res;
} // </editor-fold>

uint32_t Make328IB(uint8_t B3, uint8_t B2, uint8_t B1, uint8_t B0) // <editor-fold defaultstate="collapsed" desc="Combine 4 Bytes to a 32-bit Word">
{
    uint32_t res=B0; // The highest data bytes of 16Bit MCU are 0x00
    res<<=8;
    res|=B1;
    res<<=8;
    res|=B2;
    res<<=8;
    res|=B3;
    return res;
} // </editor-fold> 

uint16_t Make1632DW(uint32_t val, bool idx) // <editor-fold defaultstate="collapsed" desc="Decombine a 32-bit DWord to 16-bit Word">
{
    if(idx) val>>=16;
    return (uint16_t) val;
} // </editor-fold>                                                                            // </editor-fold>

uint16_t Make168A(uint8_t *val) // <editor-fold defaultstate="collapsed" desc="Combine a 16-bit Word from 2 bytes - Little endian">
{
    uint16_t res=val[0];
    res<<=8;
    res|=val[1];
    return res;
} // </editor-fold>

uint16_t Make168B(uint8_t B1, uint8_t B0) // <editor-fold defaultstate="collapsed" desc="Combine a 16-bit Word from 2 bytes - Little endian">
{
    uint16_t res=B1;
    res<<=8;
    res|=B0;
    return res;
} // </editor-fold>

uint16_t Make168IA(uint8_t *val) // <editor-fold defaultstate="collapsed" desc="Combine a 16-bit Word from 2 bytes - Big endian">
{
    uint16_t res=val[1];
    res<<=8;
    res|=val[0];
    return res;
} // </editor-fold>

uint16_t Make168IB(uint8_t B1, uint8_t B0) // <editor-fold defaultstate="collapsed" desc="Combine a 16-bit Word from 2 bytes - Big endian">
{
    uint16_t res=B0;
    res<<=8;
    res|=B1;
    return res;
} // </editor-fold>

uint16_t Byte2Hex_Convert(uint8_t *pDatain, uint16_t len, uint8_t *pDataout)// <editor-fold defaultstate="collapsed" desc="Byte to Ascii hex">
{
    uint16_t newlen=len<<1;
    while(len--)
    {
        uint8_t H, h;
        H=*pDatain>>4;
        if(H>9) H+='7';
        else H+='0';

        h=*pDatain&0x0F;
        if(h>9) h+='7';
        else h+='0';

        *pDataout=H;
        pDataout++;
        *pDataout=h;
        pDataout++;
        pDatain++;
    }
    return newlen;
}// </editor-fold>

uint16_t Hex2Byte_Convert(uint8_t *pDatain, uint16_t len, uint8_t *pDataout)// <editor-fold defaultstate="collapsed" desc="Ascii hex to byte">
{
    uint16_t newlen=len>>1;
    while(len--)
    {
        uint8_t B, b;
        B=*pDatain++;
        if(B>='a') B-='Y';
        else if(B>='A') B-='7';
        else B-='0';

        b=*pDatain++;
        if(b>='a') b-='Y';
        else if(b>='A') b-='7';
        else b-='0';
        
        *pDataout=(B<<4)|b;
        *pDataout++;
    }
    return newlen;
}// </editor-fold>