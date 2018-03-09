#ifndef LVP_H
#define	LVP_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define INPUT_PIN           1
#define OUTPUT_PIN          0

#define SLAVE_RUN           1
#define SLAVE_RESET         0

#define ICSP_TRIS_DAT       TRISBbits.TRISB8
#define ICSP_DAT_OUT        LATBbits.LATB8
#define ICSP_DAT_IN         PORTBbits.RB8

#define ICSP_TRIS_CLK       TRISFbits.TRISF0
#define ICSP_CLK            LATFbits.LATF0

#define ICSP_TRIS_nMCLR     TRISGbits.TRISG9
#define ICSP_nMCLR          LATGbits.LATG9

#define  LVP_init()         LVP_exit();

void LVP_enter(void);
void LVP_exit(void);
void LVP_addressLoad(uint16_t address);
void LVP_bulkErase(void);
void LVP_skip(uint16_t count);
bool LVP_inProgress(void);
void LVP_rowWrite(uint16_t *buffer, uint8_t n);
void LVP_cfgWrite(uint16_t *buffer, uint8_t n);

void DIRECT_Initialize();
void lvpWrite();
void writeRow();
void packRow(uint32_t address, uint8_t *data, uint8_t data_count);
void programLastRow();

#endif