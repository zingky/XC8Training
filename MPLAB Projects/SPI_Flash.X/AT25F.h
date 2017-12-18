#ifndef AT25F_H
#define	AT25F_H
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define AT25VF020B                                                             // 2Mbit Flash  <-------------------- User can redefine this line
//#define AT25PF040B                                                             // 4Mbit Flash  <-------------------- User can redefine this line
//#define AT25VF016B                                                             // 4Mbit Flash  <-------------------- User can redefine this line

/* **********************************************Please to read these documents:
 * http://ww1.microchip.com/downloads/en/DeviceDoc/S71417_03.pdf
 * http://ww1.microchip.com/downloads/en/DeviceDoc/20005051C.pdf
 ******************************************************************************/

// MAX_MEM_ADDR=(Capacity in Mbit *1024^2)/8 - 1 (address start at 0)
#define SECTOR_LENGTH   4096
#define PAGE_LENGTH     256
#define PAGE_IN_SECTOR  16
#if defined(AT25PF040B)
#define MAX_MEM_ADDR    0x7FFFF                                                                                                   
#elif defined(AT25VF020B)
#define MAX_MEM_ADDR    0x3FFFF  
#elif defined AT25VF016B
#define MAX_MEM_ADDR    0x1FFFFF 
#else
#warning "Please define your flash memory"
#endif

#define TEMP_BGN_ADDR               0x00000000// Begin address of temporary zone
#define TEMP_END_ADDR               0x00000FFF// End address of temporary zone

typedef enum AT_PROTECT_RANGE {
    FLASH_PROTECT_NONE=0,
    FLASH_PROTECT_64KB=1,
    FLASH_PROTECT_128KB=2,
    FLASH_PROTECT_256KB=3,
    FLASH_PRTOECT_512KB=4,
    FLASH_PROTECT_1MB=5,
    FLASH_PROTECT_2MB=6,
    FLASH_PROTECT_ALL=7
} sst_protect_range_t;

/*********************************************************************COMMANDS*/
#define AT_READ_DATA        0x03//
#define AT_SECTOR_ERASE     0x52//
#define AT_BULK_ERASE       0x62//
#define AT_BYTE_PROG        0x02//
#define AT_READ_STATUS      0x05//
#define AT_WRITE_STATUS     0x01//
#define AT_WRITE_EN         0x06//
#define AT_WRITE_DIS        0x04//
#define AT_READ_JDECID      0x15//
/*************************************************************PUBLIC FUNCTIONS*/
// address= 0x00000 to MAX_MEM_ADDR
// range= see in FLASH_PROTECT_RANGE
// len=1 to 256, if over 256 bytes, this function will not execute

void AT_Chip_Erase();                                                          // Erase full-memory
void AT_Sector_Erase(uint32_t BAddr);                                          // Erase a sector
void AT_Read_nByte(uint32_t BAddr, uint32_t len, uint8_t *buffer);             // Read n byte(s)
void AT_Write_nByte(uint32_t BAddr, uint16_t len, uint8_t *data);              // Write n byte(s)
void AT_Write_Byte(uint32_t Addr, uint8_t data);                               // Write 1 byte
void AT_Protect(sst_protect_range_t range);                                    // Protect memory zone
bool AT_Init();                                                                // Call this function first (SPI must be initialized before)

#endif