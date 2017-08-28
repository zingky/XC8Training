#ifndef SST25VF_H
#define	SST25VF_H

#include <stdint.h>
#include <stdbool.h>

typedef enum SST_PROTECT_RANGE {
    FLASH_PROTECT_NONE=0,
    FLASH_PROTECT_64KB=1,
    FLASH_PROTECT_128KB=2,
    FLASH_PROTECT_256KB=3,
    FLASH_PRTOECT_512KB=4,
    FLASH_PROTECT_1MB=5,
    FLASH_PROTECT_2MB=6,
    FLASH_PROTECT_ALL=7
} sst_protect_range_t;

/*************************************************************PUBLIC FUNCTIONS*/
// device=SST1 or SST2
// address= 0x00000 to MAX_MEM_ADDR
// range= see in FLASH_PROTECT_RANGE
// len=1 to 256, if over 256 bytes, this function will not execute

void SST_Chip_Erase();
void SST_Sector_Erase(uint32_t BAddr);
void SST_Read_nByte(uint32_t BAddr, uint32_t len, uint8_t *buffer);
void SST_Write_nByte(uint32_t BAddr, uint16_t len, uint8_t *data);
void SST_Protect(sst_protect_range_t range);
bool SST_Init();

#endif