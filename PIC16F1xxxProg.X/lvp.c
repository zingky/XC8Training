#include "lvp.h"
#include "Tick_Timer.h"

#define  CMD_LOAD_ADDRESS     0x80
#define  CMD_LATCH_DATA       0x00
#define  CMD_LATCH_DATA_IA    0x02
#define  CMD_INC_ADDR         0xF8
#define  CMD_BEGIN_PROG       0xE0
#define  CMD_BULK_ERASE       0x18

#define CFG_NUM               5                                                 // number of config words for PIC16F188xx
#define ROW_SIZE              32                                                // for all pic16f188xx
#define CFG_ADDRESS           0x8000                                            // for all pic16f188xx

// internal state
uint16_t row[ ROW_SIZE]; // buffer containing row being formed
uint32_t row_address; // destination address of current row 
bool lvp; // flag: low voltage programming in progress

void ICSP_Init(void)
{
    ICSP_nMCLR=SLAVE_RESET;
    ICSP_TRIS_CLK=INPUT_PIN;
    ICSP_TRIS_DAT=INPUT_PIN;
    ICSP_TRIS_nMCLR=OUTPUT_PIN;
}

void ICSP_Release(void)
{
    ICSP_TRIS_DAT=INPUT_PIN;
    ICSP_TRIS_CLK=INPUT_PIN;
    ICSP_nMCLR=SLAVE_RUN;
    ICSP_TRIS_nMCLR=OUTPUT_PIN;
}

void sendCmd(uint8_t b)
{
    uint8_t i;
    ICSP_TRIS_DAT=OUTPUT_PIN;
    ICSP_TRIS_CLK=OUTPUT_PIN;
    for(i=0; i<8; i++)
    {
        if((b&0x80)>0) ICSP_DAT_OUT=1; // Msb first
        else ICSP_DAT_OUT=0; // Msb first
        ICSP_CLK=1;
        Delay_us(1);
        ICSP_CLK=0;
        Delay_us(1);
        b<<=1;
    }
    Delay_ms(1);
}

void sendData(uint16_t data)
{
    uint8_t i;
    uint32_t w=(uint32_t) data;
    w<<=1;
    ICSP_TRIS_DAT=OUTPUT_PIN;
    ICSP_TRIS_CLK=OUTPUT_PIN;
    for(i=0; i<24; i++)
    {
        if((w&0x800000)>0) ICSP_DAT_OUT=1; // Msb first
        else ICSP_DAT_OUT=0;
        ICSP_CLK=1;
        Delay_us(1);
        ICSP_CLK=0;
        Delay_us(1);
        w<<=1;
    }
    Delay_us(1);
}

uint8_t getByte(void)
{
    uint8_t i, b;
    ICSP_TRIS_DAT=INPUT_PIN;
    ICSP_TRIS_CLK=OUTPUT_PIN;
    for(i=0; i<8; i++)
    {
        ICSP_CLK=1;
        b<<=1;
        Delay_us(1);
        b|=ICSP_DAT_IN;
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
    ICSP_TRIS_CLK=OUTPUT_PIN;
    for(i=0; i<24; i++)
    {
        ICSP_CLK=1;
        w<<=1;
        Delay_us(1);
        w|=ICSP_DAT_IN;
        ICSP_CLK=0;
        Delay_us(1);
    }
    return (w>>1);
}

void LVP_enter(void)
{
    ICSP_Init(); // configure I/Os   
    Delay_ms(1);
    ICSP_nMCLR=SLAVE_RESET; // MCLR = Vil (GND)
    Delay_ms(100);
    sendCmd('M');
    sendCmd('C');
    sendCmd('H');
    sendCmd('P');
    Delay_ms(500);
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
    sendCmd(CMD_LOAD_ADDRESS); // enter config area to erase config words too
    sendData(0x8000);
    sendCmd(CMD_BULK_ERASE);
    Delay_ms(20);
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
    Delay_us(3);
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
        Delay_us(3);
        sendCmd(CMD_INC_ADDR);
    }
    sendCmd(CMD_LOAD_ADDRESS); // enter code area 
    sendData(0x0000);
}

////////////////////////////////////////////////////////////////////////////////

void DIRECT_Initialize()
{
    memset((void*) row, 0xff, sizeof (row)); // fill buffer with blanks
    row_address=0x8000;
    lvp=false;
    LVP_init();
}

void lvpWrite()
{
    // check for first entry in lvp 
    if(!lvp)
    {
        lvp=true;
        LVP_enter();
        LVP_bulkErase();
    }
    if(row_address>=CFG_ADDRESS)
    { // use the special cfg word sequence
        LVP_cfgWrite(&row[7], CFG_NUM);
    }
    else
    { // normal row programming sequence
        LVP_addressLoad(row_address);
        LVP_rowWrite(row, ROW_SIZE);
    }
}

void writeRow()
{
    // latch and program a row, skip if blank
    uint8_t i;
    uint16_t chk=0xffff;
    for(i=0; i<ROW_SIZE; i++) chk&=row[i]; // blank check
    if(chk!=0xffff)
    {
        lvpWrite();
        memset((void*) row, 0xff, sizeof (row)); // fill buffer with blanks
    }
}

void packRow(uint32_t address, uint8_t *data, uint8_t data_count)
{
    // copy only the bytes from the current data packet up to the boundary of a row 
    uint8_t index=(address&0x3e)>>1;
    uint32_t new_row=(address&0xfffc0)>>1;
    if(new_row!=row_address)
    {
        writeRow();
        row_address=new_row;
    }
    // ensure data is always even (rounding up)
    data_count=(data_count+1) & 0xfe;
    // copy data up to the row boundaries
    while((data_count>0) && (index<ROW_SIZE))
    {
        uint16_t word= *data++;
        word+=((uint16_t) (*data++)<<8);
        row[index++]=word;
        data_count-=2;
    }
    // if a complete row was filled, proceed to programming
    if(index==ROW_SIZE)
    {
        writeRow();
        // next consider the split row scenario
        if(data_count>0)
        { // leftover must spill into next row
            row_address+=ROW_SIZE;
            index=0;
            while(data_count>0)
            {
                uint16_t word= *data++;
                word+=((uint16_t) (*data++)<<8);
                row[index++]=word;
                data_count-=2;
            }
        }
    }
}

void programLastRow()
{
    writeRow();
    LVP_exit();
    lvp=false;
}