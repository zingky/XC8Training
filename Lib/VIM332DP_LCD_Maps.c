#include "VIM332DP_LCD_Maps.h"
const uint8_t _7SegCode[11]={
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x27, // 7
    0x7F, // 8
    0x6F, // 9
    0x80  // .
};

void SegDisplayInit()
{
    SegDisplayDigit(0, 0, 0);
    SegDisplayDigit(1, 0, 0);
    SegDisplayDigit(2, 0, 0);
    SegDisplayDigit(3, 0, 0);
    SegDisplayDigit(4, 0, 0);
}

void SegDisplayDigit(uint8_t digit, uint8_t value, bool state)
{
    if(state) value=0;
    switch(digit)
    {
        case 1:
            SEG_1A=(bool) value;
            value>>=1;
            SEG_1B=(bool) value;
            value>>=1;
            SEG_1C=(bool) value;
            value>>=1;
            SEG_1D=(bool) value;
            value>>=1;
            SEG_1E=(bool) value;
            value>>=1;
            SEG_1F=(bool) value;
            value>>=1;
            SEG_1G=(bool) value;
            break;

        case 2:
            SEG_2A=(bool) value;
            value>>=1;
            SEG_2B=(bool) value;
            value>>=1;
            SEG_2C=(bool) value;
            value>>=1;
            SEG_2D=(bool) value;
            value>>=1;
            SEG_2E=(bool) value;
            value>>=1;
            SEG_2F=(bool) value;
            value>>=1;
            SEG_2G=(bool) value;
            value>>=1;
            SEG_DP1=(bool) value;
            break;

        case 3:
            SEG_3A=(bool) value;
            value>>=1;
            SEG_3B=(bool) value;
            value>>=1;
            SEG_3C=(bool) value;
            value>>=1;
            SEG_3D=(bool) value;
            value>>=1;
            SEG_3E=(bool) value;
            value>>=1;
            SEG_3F=(bool) value;
            value>>=1;
            SEG_3G=(bool) value;
            value>>=1;
            SEG_DP2=(bool) value;
            break;

        case 4:
            if((value&0b01111111)==_7SegCode[1]) SEG_4BC=1;
            else SEG_4BC=0;
            value>>=7;
            SEG_DP3=(bool) value;
            break;

        default:
            SegDisplayOff(SEG_RC);
            SegDisplayOff(SEG_BATT);
            SegDisplayOff(SEG_MINUS);
            SegDisplayOff(SEG_AC);
            SegDisplayOff(SEG_DH);
            SegDisplayOff(SEG_RH);
            SegDisplayOff(SEG_m);
            SegDisplayOff(SEG_M);
            SegDisplayOff(SEG_A);
            SegDisplayOff(SEG_V);
            SegDisplayOff(SEG_K);
            SegDisplayOff(SEG_S3);
            SegDisplayOff(SEG_S2);
            SegDisplayOff(SEG_S1);
            break;
    }
}

void SegDisplayNum(uint16_t value, uint8_t dotIdx)
{
    uint8_t digit, display_code;
    for(digit=1; digit<5; digit++)
    {
        if((dotIdx>1)&&(dotIdx<5)&&(digit==dotIdx))
            display_code=(uint8_t)(_7SegCode[(uint8_t)(value%10)]|_7SegCode[10]);
        else 
            display_code=_7SegCode[(uint8_t)(value%10)];
        SegDisplayDigit(digit, display_code, 0);
        value/=10;
    }
}