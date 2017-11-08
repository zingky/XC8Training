#include "lvp.h"
#include "Tick_Timer.h"
#include "mcc_generated_files/pin_manager.h"

void ICSP_Init(void)
{
    ICSP_DAT_WR=0;
    ICSP_TRIS_DAT=OUTPUT_PIN;
    ICSP_CLK=0;
    ICSP_TRIS_CLK=OUTPUT_PIN;
    ICSP_nMCLR=SLAVE_RUN;
    ICSP_TRIS_nMCLR=OUTPUT_PIN;
    Delay_ms(100);
}

void ICSP_Release(void)
{
    ICSP_TRIS_DAT=INPUT_PIN;
    ICSP_TRIS_CLK=INPUT_PIN;
    ICSP_nMCLR=SLAVE_RUN;
    ICSP_TRIS_nMCLR=OUTPUT_PIN;
    LED_Off(RED_LED);
    LED_On(GREEN_LED);
}

void sendCmd(uint8_t b)
{
    uint8_t i;
    ICSP_TRIS_DAT=OUTPUT_PIN;
    for(i=0; i<8; i++)
    {
        ICSP_CLK=1;
        ICSP_DAT_WR=(bool) (b); // LSB first
        Delay_us(1);
        ICSP_CLK=0;
        Delay_us(1);
        b>>=1;
    }
    Delay_us(1);
}

void sendData(uint16_t data)
{
    uint8_t i;
    uint32_t w=(uint32_t) data;

    w=(w<<1) & 0x7ffffe; // add start and stop bits
    ICSP_TRIS_DAT=OUTPUT_PIN;
    for(i=0; i<24; i++)
    {
        ICSP_CLK=1;
        ICSP_DAT_WR=(bool) w; // LSB first
        Delay_us(1);
        ICSP_CLK=0;
        Delay_us(1);
        w>>=1;
    }
}

uint8_t getByte(void)
{
    uint8_t i, b;
    ICSP_TRIS_DAT=INPUT_PIN;
    for(i=0; i<8; i++)
    {
        ICSP_CLK=1;
        b<<=1;
        Delay_us(1);
        b|=ICSP_DAT_RD;
        ICSP_CLK=0;
        Delay_us(1);
    }
    return b;
}

uint16_t getData(void)
{
    uint8_t i;
    uint16_t w=0;
    ICSP_TRIS_DAT=INPUT_PIN;
    for(i=0; i<24; i++)
    {
        ICSP_CLK=1;
        w<<=1;
        Delay_us(1);
        w|=ICSP_DAT_RD;
        ICSP_CLK=0;
        Delay_us(1);
    }
    return (w>>1);
}

void LVP_enter(void)
{
    LED_On(RED_LED);
    LED_Off(GREEN_LED);

    ICSP_Init(); // configure I/Os   
    ICSP_nMCLR=SLAVE_RESET; // MCLR = Vil (GND)
    Delay_ms(500);
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
    return (ICSP_nMCLR==SLAVE_RESET);
}

void LVP_bulkErase(void)
{
    sendCmd(0x18);
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
