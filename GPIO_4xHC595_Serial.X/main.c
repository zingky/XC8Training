#include "mcc_generated_files/mcc.h"
// <editor-fold defaultstate="collapsed" desc="Dieu khien nhieu IC 74595">
#define NUM_OF_595  4
// <editor-fold defaultstate="collapsed" desc="Dieu khien nhieu IC 74595 - Cach 1">
// Cach nay de xu ly du lieu dau vao (value), nhung xu ly cham nhat
//void HC595_Write_Idx(uint8_t idx, uint8_t value)// Ghi gia tri value ra IC o vi tri Idx 
//{
//    static uint8_t value_bk[NUM_OF_595];
//    value_bk[idx]=value;
//    uint8_t i, j;
//    STCP_SetLow();
//    for(i=0; i<NUM_OF_595; i++)
//    {
//        value=value_bk[i];
//        for(j=0; j<8; j++)
//        {
//            SHCP_SetLow();
//            DS_LAT=((value&0x80)==0x80);
//            SHCP_SetHigh();
//            value<<=1;
//        }
//    }
//    STCP_SetHigh();
//}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Dieu khien nhieu IC 74595 - Cach 2">
// Cach nay xu ly nhanh nhat nhung kho xu ly du lieu dau vao (*value)
void HC595_nWrite(uint8_t *value)// Ghi chuoi du lieu
{
    uint8_t i, j;
    STCP_SetLow();
    for(i=0; i<NUM_OF_595; i++)
    {
        for(j=0; j<8; j++)
        {
            SHCP_SetLow();
            DS_LAT=((*value&0x80)==0x80);
            SHCP_SetHigh();
            *value<<=1;
        }
        value++;
    }
    STCP_SetHigh();
}
// </editor-fold>
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Dieu khien 1 IC 74595">
//void HC595_Write(uint8_t value)
//{
//    uint8_t i;
//    STCP_SetLow();
//    for(i=0; i<8; i++)
//    {
//        SHCP_SetLow();
//        DS_LAT=((value&0x80)==0x80);
//        SHCP_SetHigh();
//        value<<=1;
//    }
//    STCP_SetHigh();
//}
// </editor-fold>

void main(void)
{
    SYSTEM_Initialize();
    while (1)
    {
        // <editor-fold defaultstate="collapsed" desc="Dieu khien 1 IC 74595">
//        uint8_t i;
//        for(i=0; i<8; i++)
//        {
//            HC595_Write(1<<i);// So 1 dich trai 8 lan
//            __delay_ms(1000);
//        }
        // </editor-fold>
        
        // <editor-fold defaultstate="collapsed" desc="Dieu khien nhieu IC 74595 - Cach 1">
//        HC595_Write_Idx(0, 0x05);
//        __delay_ms(1000);
//        HC595_Write_Idx(1, 0xAA);
//        __delay_ms(1000);
//        HC595_Write_Idx(2, 0xF0);
//        __delay_ms(1000);
//        HC595_Write_Idx(3, 0x0F);
//        __delay_ms(1000);
//        HC595_Write_Idx(3, 0);
//        HC595_Write_Idx(2, 0);
//        HC595_Write_Idx(1, 0);
//        HC595_Write_Idx(0, 0);
//        __delay_ms(1000);
        // </editor-fold>
        
        // <editor-fold defaultstate="collapsed" desc="Dieu khien nhieu IC 74595 - Cach 2">
        uint8_t data1[4]={0x05, 0xAA, 0xF0, 0x0F};
        uint8_t data2[4]={0x00, 0x00, 0x00, 0x00};
        HC595_nWrite(data1);
        __delay_ms(1000);
        HC595_nWrite(data2);
        __delay_ms(1000);
        // </editor-fold>
    }
}