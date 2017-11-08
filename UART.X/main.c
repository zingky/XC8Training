#include "mcc_generated_files/mcc.h"

bool str_cmp(uint8_t *str1, uint8_t *str2, uint8_t len)// So sanh 2 chuoi
{
    while(len--)
    {
        if(*str1!=*str2) return 0;
        str1++;
        str2++;
    }
    return 1;
}

void EUSART_Puts(uint8_t *str)// Gui 1 chuoi ASCII 
{
    while(*str!=0) EUSART_Write(*str++);
}

void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while(1)
    {
        //while(EUSART_DataReady) EUSART_Write(EUSART_Read()); // Uart echo
        bool check;
        uint8_t i;
        uint8_t buf[16];
        i=0;
        check=0;
        while(EUSART_DataReady)// Kiem tra du lieu den
        {
            __delay_ms(100);// Cho de chuoi duoc gui het. Thoi gian delay >= 2x thoi gian gui chuoi
            buf[i++]=EUSART_Read();// Luu chuoi vao buufer
            check=1;
        }
        if(check)
        {
            if(str_cmp(buf, (uint8_t *) "LED1", 4))// So sanh chuoi nhan duoc voi "LED1"
            {
                LED1_Toggle();
                EUSART_Puts((uint8_t *) "Led1 toggle\r\n");
            }
            else if(str_cmp(buf, (uint8_t *) "LED2", 4))// So sanh chuoi nhan duoc voi "LED2"
            {
                LED2_Toggle();
                EUSART_Puts((uint8_t *) "Led2 toggle\r\n");
            }
            else if(str_cmp(buf, (uint8_t *) "LED3", 4))// So sanh chuoi nhan duoc voi "LED3"
            {
                LED3_Toggle();
                EUSART_Puts((uint8_t *) "Led3 toggle\r\n");
            }
            else EUSART_Puts((uint8_t *) "Error command\r\n");// Command sai
        }
    }
}