#include "mcc_generated_files/mcc.h"
#include "Tick_Timer.h"
#include "lvp.h"
#include <stdio.h>
#define ACCESSKEY_LEN   8

const uint8_t ACCESSKEY[ACCESSKEY_LEN]="12345678";                              // Programming access code
const uint8_t PVID[9]="UMB32001";                                               // Device name and firmware version

typedef enum
{
    INIT,
    GET_DATA,
    ENTRY_ICSP_MODE,
    ERASE_USER_APP,
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

void main()
{
    SYSTEM_Initialize();
    LVP_init();
    Delay_Init();
    Task.Prev=ENTRY_ICSP_MODE;
    Task.Next=INIT;
    Tick_Reset(Tick.Led);

    while(1)
    {
        Clear_WDT();
        if(Tick_Over_Ms(Tick.Led, 100)) D5_Toggle();
        switch(Task.Next)
        {
            case INIT:
                Tick_Reset(Tick.RxTout);
                if(Task.Next!=ENTRY_ICSP_MODE) Tick_Reset(Tick.ProgTout);
                Buf.Len=0;
                Task.Next=GET_DATA;
                break;

            case GET_DATA:
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

            case ENTRY_ICSP_MODE:
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
                    LVP_enter();
                    Task.Next=ERASE_USER_APP;
                }
                break;

            case ERASE_USER_APP:
                LVP_bulkErase();
                UART_Puts((uint8_t *) "\r\nErased\r\n");
                Task.Prev=CONVERT;
                Task.Next=DEFAULT;                                          //////////////////////
                break;

            case CONVERT:
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

            case CHECKSUM:
                for(i=0; i<Buf.Len; i++)
                    Buf.Dat[Buf.Len-1]=(uint8_t) Buf.Dat[Buf.Len-1]+Buf.Dat[i];
                if(Buf.Dat[Buf.Len-1]==0)
                {
                    Task.Next=PROGRAM;
                }
                else Task.Next=REP_ERROR;
                break;

            case PROGRAM:
                Task.Next=REP_SUCCESS;
                break;

            case REP_SUCCESS:
                UART_TX('Y');
                Task.Next=INIT;
                break;

            case REP_ERROR:
                UART_TX('N');
                Task.Next=INIT;
                break;

            default:
                ICSP_Release();
                Task.Prev=ENTRY_ICSP_MODE;
                Task.Next=INIT;
                break;
        }
    }
}