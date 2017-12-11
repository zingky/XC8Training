#include "mcc_generated_files/mcc.h"
#include "Tick_Timer.h"
#include "Data_Check.h"
#include "Data_Convert.h"
#include "AT25F.h"

struct
{

    struct
    {
        uint8_t Pres;
        uint8_t Prev;
    } Len;
    uint8_t Data[64];
    tick_timer_t Timeout;
} UBuf; // uart buffer

struct
{
    uint16_t Len;
    uint32_t Addr;
    uint8_t Data[32];
} FBuf; // Flash buffer

typedef enum
{
    INIT,
    GET_LEN,
    GET_ADDR,
    FLASH_READ,
    FLASH_WRITE,
    FLASH_ERASE_SECTOR,
    FLASH_ERASE_CHIP,
    UART_RX,
    UART_TX,
    PROCESS_CMD,
    ERROR,
    DEFAULT,
} task_t;

struct
{
    task_t Stt1;
    task_t Stt2;
} Task;

void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    Task.Stt1=INIT;

    while(1)
    {
        CLRWDT();
        switch(Task.Stt1)
        {
            case INIT:
                // Uart buffer init
                Tick_Reset(UBuf.Timeout);
                UBuf.Len.Pres=0;
                UBuf.Len.Prev=0;
                // Check flash ready
                if(SST_Init()) Task.Stt1=ERROR; // Flash error
                else Task.Stt1=DEFAULT; // Flash is OK
                break;

            case GET_LEN:
                Hex2Byte_Convert(&UBuf.Data[13], 2, &FBuf.Len);
                FBuf.Len&=0x1F; // Length isn't over 32 bytes

            case GET_ADDR:// FLx 00000000 01\r
                Hex2Byte_Convert(&UBuf.Data[4], 8, &FBuf.Data[0]);
                FBuf.Addr=Make328A(&FBuf.Data[0]);
                Task.Stt1=Task.Stt2;
                break;

            case FLASH_READ:
                // Read Flash
                SST_Read_nByte(FBuf.Addr, FBuf.Len, &FBuf.Data[0]);
                // Response
                UBuf.Len.Prev=0;
                UBuf.Len.Pres=Copy((uint8_t *) "\r\nRead:\r\n", UBuf.Data[0]);
                UBuf.Len.Pres+=Byte2Hex_Convert(&FBuf.Data[0], FBuf.Len, UBuf.Data[UBuf.Len.Pres]);
                Task.Stt1=UART_TX;
                break;

            case FLASH_WRITE:
                // Write Flash
                SST_Write_nByte(FBuf.Addr, FBuf.Len, &UBuf.Data[15]);
                // Response
                UBuf.Len.Prev=0;
                UBuf.Len.Pres=Copy((uint8_t *) "\r\nOK\r\n", UBuf.Data[0]);
                Task.Stt1=UART_TX;
                break;

            case FLASH_ERASE_SECTOR:
                SST_Sector_Erase(FBuf.Addr);
                // Response
                UBuf.Len.Prev=0;
                UBuf.Len.Pres=Copy((uint8_t *) "\r\nOK\r\n", UBuf.Data[0]);
                Task.Stt1=UART_TX;
                break;

            case FLASH_ERASE_CHIP:
                SST_Chip_Erase();
                // Response
                UBuf.Len.Prev=0;
                UBuf.Len.Pres=Copy((uint8_t *) "\r\nOK\r\n", UBuf.Data[0]);
                Task.Stt1=UART_TX;
                break;

            case UART_RX:
                UBuf.Len.Pres=0;
                while(EUSART_is_rx_ready())
                    UBuf.Data[UBuf.Len.Pres++]=EUSART_Read();
                Task.Stt1=PROCESS_CMD;
                break;

            case UART_TX:
                if(EUSART_is_tx_ready()&&(UBuf.Len.Prev<UBuf.Len.Pres))
                    EUSART_Write(UBuf.Data[UBuf.Len.Prev++]);
                if(EUSART_is_tx_done()&&(UBuf.Len.Prev==UBuf.Len.Pres))
                    Task.Stt1=DEFAULT;
                break;

            case PROCESS_CMD:
                if(UBuf.Data[UBuf.Len.Pres-1]=='\r')
                {
                    if(Cmp(UBuf.Data, 0, (uint8_t *) "FLW ", 4))
                    {
                        Task.Stt1=GET_LEN;
                        Task.Stt2=FLASH_WRITE;
                    }
                    else if(Cmp(UBuf.Data, 0, (uint8_t *) "FLR ", 4))
                    {
                        Task.Stt1=GET_LEN;
                        Task.Stt2=FLASH_READ;
                    }
                    else if(Cmp(UBuf.Data, 0, (uint8_t *) "FLE ", 4))
                    {
                        Task.Stt1=GET_ADDR;
                        Task.Stt2=FLASH_ERASE_SECTOR;
                    }
                    else if(Cmp(UBuf.Data, 0, (uint8_t *) "FLF ", 4))
                        Task.Stt1=FLASH_ERASE_CHIP;
                    else
                    {
                        UBuf.Len.Prev=0;
                        UBuf.Len.Pres=Copy((uint8_t *) "\r\nBad command\r\n", UBuf.Data[0]);
                        Task.Stt1=UART_TX;
                    }
                }
                else
                {
                    UBuf.Len.Prev=0;
                    UBuf.Len.Pres=Copy((uint8_t *) "\r\nMissing 0x0D\r\n", UBuf.Data[0]);
                    Task.Stt1=UART_TX;
                }
                break;

            case ERROR:
                UBuf.Len.Prev=0;
                UBuf.Len.Pres=Copy((uint8_t *) "\r\nFlash error\r\n", UBuf.Data[0]);
                Task.Stt1=UART_TX;
                break;

            default:
                UBuf.Len.Pres=EUSART_is_rx_ready();
                if(UBuf.Len.Pres>0)
                {
                    if(UBuf.Len.Prev!=UBuf.Len.Pres)
                    {
                        Tick_Reset(UBuf.Timeout);
                        UBuf.Len.Prev=UBuf.Len.Pres;
                    }
                    else if(Tick_Is_Over(&UBuf.Timeout, 100)) Task.Stt1=UART_RX;
                }
                break;
        }
    }
}