#ifndef LVP_H
#define	LVP_H
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define CMD_LOAD_ADDRESS    0x80
#define CMD_LATCH_DATA      0x00
#define CMD_LATCH_DATA_IA   0x02
#define CMD_INC_ADDR        0xF8
#define CMD_BEGIN_PROG      0xE0
#define CMD_BULK_ERASE      0x18
#define CMD_READ_NVM        0xFC
#define CMD_READ_NVM_IA     0XFE

#define INPUT_PIN           1
#define OUTPUT_PIN          0

#define SLAVE_RUN           1
#define SLAVE_RESET         0

#define ICSP_TRIS_DAT       TRISBbits.TRISB8
#define ICSP_DAT_RD         PORTBbits.RB8
#define ICSP_DAT_WR         LATBbits.LATB8

#define ICSP_TRIS_CLK       TRISFbits.TRISF0
#define ICSP_CLK            LATFbits.LATF0

#define ICSP_TRIS_nMCLR     TRISGbits.TRISG9
#define ICSP_nMCLR          LATGbits.LATG9

#define RED_LED             LATEbits.LATE1
#define GREEN_LED           LATEbits.LATE3
#define LED_On(x)           x=1
#define LED_Off(x)          x=0

#define  LVP_init()         LVP_exit();

uint8_t getByte(void);
uint16_t getData(void);
void sendData(uint16_t data);
void sendCmd(uint8_t b);
void LVP_enter(void);
void LVP_exit(void);
void LVP_addressLoad(uint16_t address);
void LVP_bulkErase(void);
void LVP_skip(uint16_t count);
bool LVP_inProgress(void);
void LVP_rowWrite(uint16_t *buffer, uint8_t n);
void LVP_cfgWrite(uint16_t *buffer, uint8_t n);

#endif