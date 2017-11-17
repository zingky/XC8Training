#include "mcc_generated_files/mcc.h"
#include "Tick_Timer.h"
#include "lvp.h"
#include "Buttons.h"
#include "Data_Convert.h"

#define Clear_WDT()     WDTCONbits.WDTCLR=1
#define ACCESSKEY_LEN   8

const uint8_t ACCESSKEY[ACCESSKEY_LEN]="12345678"; // Programming access code
const uint8_t PVID[9]="UMB32001"; // Device name and firmware version

typedef enum HEX_RECORD_TYPES
{
    DATA_RECORD=0, // Data
    END_OF_FILE_RECORD, // End Of File
    EXT_SEG_ADRS_RECORD, // Extended Segment Address
    START_SEG_ADRS, // Start Segment Address
    EXT_LIN_ADRS_RECORD, // Extended Linear Address
    START_LIN_ADRS // Start Linear Address
} hex_record_type_t;

struct
{

    struct
    {
        uint32_t Phy; // Combination of ESeg and ELin
        uint32_t ELin; // Extended linear address
    } Addr;

    struct
    {
        uint8_t *Buf; // Buffer, save Data of a hex record
        uint8_t BCount; // Hex Data Len
    } Data;

    hex_record_type_t RecType; // Hex record type
} Hex;

typedef enum
{
    INIT,
    GET_DATA,
    ENTRY_ICSP_MODE,
    ERASE_TARGET_CHIP_MEM,
    CONVERT,
    CHECKSUM,
    PROGRAM,
    REP_SUCCESS,
    REP_ERROR,
    DEFAULT
} app_task_t;

struct
{
    app_task_t Prev;
    app_task_t Next;
} Task;

struct
{
    tick_timer_t Led;
    tick_timer_t RxTout;
    tick_timer_t ProgTout;
} Tick;

struct
{
    uint8_t Dat[64];
    uint8_t Len;
} Buf;

uint32_t dummy;
uint16_t temp;
uint8_t i, j;
button_t BT1, BT2, BT3;

void Soft_Reset()
{
    SYSTEM_RegUnlock();
    RSWRST=1;
    RSWRST;
}

void main()
{
    SYSTEM_Initialize();
    Delay_Init();
    Button_Init(&BT1);
    Button_Init(&BT2);
    Button_Init(&BT3);
    Task.Prev=ENTRY_ICSP_MODE;
    Task.Next=INIT;
    Tick_Reset(Tick.Led);

    while(1)
    {
        Clear_WDT();
        if(Tick_Over_Ms(Tick.Led, 100)) D5_Toggle(); // Toggle status led

        if(BT_Is_Pressed(&BT1, BT1_GetValue(), L2H, 500)) // Reset Programmer
        {
            D1_SetHigh();
            Delay_ms(100);
            Soft_Reset();
        }

        switch(Task.Next) // Programming tasks
        {
            case INIT: // Reset buffer, tick timer
                Tick_Reset(Tick.RxTout);
                if(Task.Next!=ENTRY_ICSP_MODE) Tick_Reset(Tick.ProgTout);
                Buf.Len=0;
                Task.Next=GET_DATA;
                break;

            case GET_DATA: // Get UART data
                if(UART_RX(&Buf.Dat[Buf.Len]))
                {
                    if(Buf.Dat[Buf.Len]=='\r') Task.Next=Task.Prev;
                    else if(Buf.Len>45) Task.Next=REP_ERROR;
                    else Buf.Len++;
                    Tick_Reset(Tick.RxTout);
                    if(Task.Next!=ENTRY_ICSP_MODE) Tick_Reset(Tick.ProgTout);
                }
                else if((Buf.Len>0)&&Tick_Over_Ms(Tick.RxTout, 100))
                    Task.Next=REP_ERROR;
                else if(Tick_Over_Ms(Tick.ProgTout, 2000)) Task.Next=DEFAULT;
                break;

            case ENTRY_ICSP_MODE: // Check Access Programming key
                for(i=0; i<ACCESSKEY_LEN; i++)
                {
                    if(Buf.Dat[i]!=ACCESSKEY[i])
                    {
                        Task.Next=INIT;
                        break;
                    }
                }
                if(Task.Next!=INIT)
                {
                    UART_Puts((uint8_t *) PVID);
                    DIRECT_Initialize();
                    Task.Next=ERASE_TARGET_CHIP_MEM;
                }
                break;

            case ERASE_TARGET_CHIP_MEM: // Erase target chip memory
                Hex.Addr.ELin=0;
                UART_Puts((uint8_t *) "\r\nErased\r\n");
                Task.Prev=CONVERT;
                Task.Next=REP_SUCCESS;
                break;

            case CONVERT: // Convert UART data to Hex data format
                Buf.Len--;
                if(Buf.Dat[0]=='@')
                {
                    for(i=1, j=0; i<Buf.Len; i+=2, j++)
                    {
                        Buf.Dat[i]-='A';
                        Buf.Dat[i+1]-='A';
                        Buf.Dat[j]=(Buf.Dat[i]<<4)|Buf.Dat[i+1];
                    }
                    Buf.Len=j;
                    Task.Next=CHECKSUM;
                }
                else Task.Next=REP_ERROR;
                break;

            case CHECKSUM: // Checksum of Hex data
                for(i=0; i<Buf.Len; i++)
                    Buf.Dat[Buf.Len-1]=(uint8_t) Buf.Dat[Buf.Len-1]+Buf.Dat[i];
                if(Buf.Dat[Buf.Len-1]==0)
                {
                    Hex.Data.BCount=Buf.Dat[0];
                    Hex.RecType=Buf.Dat[3];
                    Hex.Data.Buf=&Buf.Dat[4];
                    Task.Next=PROGRAM;
                }
                else Task.Next=REP_ERROR;
                break;

            case PROGRAM: // Write Hex data to target chip
                Task.Next=REP_SUCCESS;
                switch(Hex.RecType)
                {
                    case DATA_RECORD:
                        Hex.Addr.Phy=Make328B(0, 0, Buf.Dat[1], Buf.Dat[2]);
                        Hex.Addr.Phy|=Hex.Addr.ELin; // Hex address=16-bit higher address|Hex address
                        packRow(Hex.Addr.Phy, Hex.Data.Buf, Hex.Data.BCount);
                        break;

                    case END_OF_FILE_RECORD:
                        programLastRow();
                        break;

                    case EXT_LIN_ADRS_RECORD:
                        Hex.Addr.ELin=Make328B(Hex.Data.Buf[0], Hex.Data.Buf[1], 0, 0);
                        break;

                    default:
                        Task.Next=REP_ERROR;
                        break;
                }
                break;

            case REP_SUCCESS: // Response for PC UI that task is complete
                UART_TX('Y');
                Task.Next=INIT;
                break;

            case REP_ERROR: // Response for PC UI that task is incomplete
                UART_TX('N');
                Task.Next=INIT;
                break;

            default:
                Task.Prev=ENTRY_ICSP_MODE;
                Task.Next=INIT;
                break;
        }
    }
}