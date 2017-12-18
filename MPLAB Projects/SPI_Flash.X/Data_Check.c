#include "Data_Check.h"

bool Cmp(uint8_t *str1, uint8_t idx1, const uint8_t *str2, uint8_t len)
{
    while(len--)
    {
        if(str1[idx1]!=*str2) return 0;
        idx1++;
        str2++;
    }
    return 1;
}

bool Contain(uint8_t *str, uint8_t strlen, const uint8_t *sample, uint8_t samlen)
{
    uint8_t i, j;
    
    for(i=0; i<strlen; i++)
    {
        if(str[i]==sample[0])
        {
            i++;
            for(j=1; j<samlen; j++, i++)
            {
                if(str[i]!=sample[j]) break;
            }
            if(j==samlen) return 1;
            else i--;
        }
    }
    return 0;
}

uint16_t Copy(uint8_t *strin, uint8_t *strout)
{
    uint16_t lenout=0;
    while(*strin!=0x00)
    {
        *strout=*strin;
        strout++;
        strin++;
        lenout++;
    }
    return lenout;
}

uint16_t Concatenate(uint8_t *strin1, uint8_t *strin2, uint8_t *strout)
{
    uint16_t lenout=0;
    while(*strin1!=0x00)
    {
        *strout=*strin1;
        strout++;
        strin1++;
        lenout++;
    }
    while(*strin2!=0x00)
    {
        *strout=*strin2;
        strout++;
        strin2++;
        lenout++;
    }
    return lenout;
}