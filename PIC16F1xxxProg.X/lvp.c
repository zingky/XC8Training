#include "lvp.h"
#include "Tick_Timer.h"
#include "mcc_generated_files/pin_manager.h"

#define CMD_LOAD_ADDRESS    0x80
#define CMD_BULK_ERASE      0x18
#define CMD_ROW_ERASE       0xF0
#define CMD_LATCH_DATA      0x00
#define CMD_LATCH_DATA_IA   0x02
#define CMD_READ_NVM        0xFC
#define CMD_READ_NVM_IA     0xFE
#define CMD_INC_ADDR        0xF8
#define CMD_BEGIN_PROG      0xE0

void ICSP_Init(void)
{
    PGD_SetDigitalInput();
    PGC_SetLow();
    PGC_SetDigitalOutput();
    MCLR_SetState(SLAVE_RUN);
    MCLR_SetDigitalOutput();
}

void ICSP_Release(void)
{
    PGD_SetDigitalInput();
    PGC_SetDigitalInput();
    MCLR_SetState(SLAVE_RUN);
    MCLR_SetDigitalOutput();
    D1_SetLow();
    D2_SetHigh();
}

void sendCmd(uint8_t b)
{
    uint8_t i;
    PGD_SetDigitalOutput();
    for(i=0; i<8; i++)
    {
        if((b&0x80)>0) PGD_SetHigh(); // Msb first
        else PGD_SetLow(); // Msb first
        PGC_SetHigh();
        b<<=1;
        Delay_us(1);
        PGC_SetLow();
        Delay_us(1);
    }
    Delay_us(1);
}

void sendData(uint16_t data)
{
    uint8_t i;
    uint32_t w=(uint32_t) data;

    w=(w<<1) & 0x7ffffe; // add start and stop bits
    PGD_SetDigitalOutput();
    for(i=0; i<24; i++)
    {
        if((w&0x800000)>0) PGD_SetHigh();// Msb first
        else PGD_SetLow();
        PGC_SetHigh();
        w<<=1;
        Delay_us(1);
        PGC_SetLow();
        Delay_us(1);
    }
}

uint8_t getByte(void)
{
    uint8_t i, b;
    PGD_SetDigitalInput();
    for(i=0; i<8; i++)
    {
        PGC_SetHigh();
        b<<=1;
        Delay_us(1);
        b|=PGD_GetValue();
        PGC_SetLow();
        Delay_us(1);
    }
    return b;
}

uint16_t getData(void)
{
    uint8_t i;
    uint16_t w=0;
    PGD_SetDigitalInput();
    for(i=0; i<24; i++)
    {
        PGC_SetHigh();
        w<<=1;
        Delay_us(1);
        w|=PGD_GetValue();
        PGC_SetLow();
        Delay_us(1);
    }
    return (w>>1);
}

void LVP_enter(void)
{
    D1_SetHigh();
    D2_SetLow();

    ICSP_Init(); // configure I/Os   
    MCLR_SetState(SLAVE_RESET); // MCLR = Vil (GND)
    Delay_ms(10);
    sendCmd('M');
    sendCmd('C');
    sendCmd('H');
    sendCmd('P');
    Delay_ms(5);
}

void LVP_exit(void)
{
    ICSP_Release(); // release ICSP-DAT and ICSP-CLK
}

bool LVP_inProgress(void)
{
    return (bool)(MCLR_GetValue()==SLAVE_RESET);
}

void LVP_bulkErase(void)
{
    sendCmd(CMD_LOAD_ADDRESS); // enter config area to erase config words too
    sendData(0x8000);
    sendCmd(CMD_BULK_ERASE);
    Delay_ms(6);
}

void LVP_skip(uint16_t count)
{
    while(count-- >0) sendCmd(CMD_INC_ADDR); // increment address  
}

void LVP_addressLoad(uint16_t address)
{
    sendCmd(CMD_LOAD_ADDRESS);
    sendData(address);
}

void LVP_rowWrite(uint16_t *buffer, uint8_t w)
{
    for(; w>1; w--) // load n-1 latches 
    {
        sendCmd(CMD_LATCH_DATA_IA);
        sendData(*buffer++);
    }
    sendCmd(CMD_LATCH_DATA); // load last latch (n-1)
    sendData(*buffer++);
    sendCmd(CMD_BEGIN_PROG);
    Delay_ms(3);
    sendCmd(CMD_INC_ADDR); // increment address only after prog. command!
}

void LVP_cfgWrite(uint16_t *cfg, uint8_t count)
{
    sendCmd(CMD_LOAD_ADDRESS);
    sendData(0x8007);
    while(count-- >0)
    {
        sendCmd(CMD_LATCH_DATA);
        sendData(*cfg++);
        sendCmd(CMD_BEGIN_PROG);
        Delay_ms(3);
        sendCmd(CMD_INC_ADDR);
    }
    sendCmd(CMD_LOAD_ADDRESS); // enter code area 
    sendData(0x0000);
}


uint16_t LVP_ReadNVM(uint16_t address)
{
    sendCmd(CMD_READ_NVM);
    Delay_us(2);
    sendData(address);
    Delay_us(2);
    return getData();
}