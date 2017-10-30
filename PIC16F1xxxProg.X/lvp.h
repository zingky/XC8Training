#ifndef LVP_H
#define	LVP_H
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define INPUT_PIN   1
#define OUTPUT_PIN  0
#define SLAVE_RUN   1
#define SLAVE_RESET 0
#define LVP_init()  LVP_exit();

void LVP_enter(void);
void LVP_exit(void);
void LVP_addressLoad(uint16_t address);
void LVP_bulkErase(void);
void LVP_skip(uint16_t count);
bool LVP_inProgress(void);
void LVP_rowWrite(uint16_t *buffer, uint8_t n);
void LVP_cfgWrite(uint16_t *buffer, uint8_t n);
uint16_t LVP_ReadNVM(uint16_t address);

#endif