#include <pic.h>
#include "mcc_generated_files/mcc.h"
#include "Tick_Timer.h"

#define EUSART_TX_BUFFER_SIZE 64// this value is located in eusart.c
#define EUSART_RX_BUFFER_SIZE 64// this value is located in eusart.c

volatile uint8_t eusartTxBufferRemaining;// this variable is located in eusart.h
volatile uint8_t eusartRxCount;// this variable is located in eusart.h

struct
{
    uint8_t Len;// user's RX buffer length
    uint8_t Idx;// byte index which is being read
    uint8_t Dat[EUSART_RX_BUFFER_SIZE];// user's RX buffer
    tick_timer_t Timeout;// Read timeout timer service
} UART;

uint8_t Task;// Application task

void main(void)
{
    Task=0;
    SYSTEM_Initialize();
    Delay_Ms(500);// Waiting for system is stable
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    while(1)
    {
        CLRWDT();
        switch(Task)
        {
            case 0:// UART RX buffer reset
                PIE1bits.RCIE=0; // Disable UART interrupt
                eusartRxCount=0; // External variable which is number of bytes in RX buffer
                UART.Len=0;// User's buffer length
                Tick_Reset(UART.Timeout);// Reset RX read timeout timer
                PIR1bits.RCIF=0; // Clear UART interrupt bit
                PIE1bits.RCIE=1; // Enable UART interrupt
                Task=0xFF; // default state
                break;

            case 1:// Read UART buffer
                UART.Len=0;
                while(eusartRxCount>0) UART.Dat[UART.Len++]=EUSART_Read();// Read all data in RX buffer
                Task=2;
                break;
                
            case 2:
                UART.Idx=0;// Reset UART data byte index
                Task=3;
                break;
                
            case 3:// Process data
                while(eusartTxBufferRemaining<EUSART_TX_BUFFER_SIZE)
                {
                    if(UART.Len-->0) EUSART_Write(UART.Dat[UART.Idx++]);//Send 1 byte
                    else Task=0;// Sending completed
                }
                break;

            default:
                if(eusartRxCount>0)// RX buffer is not empty
                {
                    if(UART.Len!=eusartRxCount)// Size of buffer is changed
                    {
                        UART.Len=eusartRxCount;// Update new buffer size
                        Tick_Reset(UART.Timeout);// Reset RX timeout timer
                    }
                    else if(Tick_Is_Over(&UART.Timeout, 100)) Task=2;// RX buffer is not changed in 100ms, Read RX buffer
                }
                break;
        }
    }
}