#ifndef MMC_SPI_H
#define	MMC_SPI_H
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

//SanDisks MultiMediaCards clock data in on the rising edge and out on the falling edge.

typedef enum {
    MMC_EC_OK = 0,
    MMC_EC_NOT_IDLE = 1, //after reset command, device wasn't in idle state
    MMC_EC_NOT_INIT = 2, //after init command, device had an error
    MMC_EC_NO_CRC = 3, //CRC wouldn't turn off
    MMC_EC_SET_READ_BLOCKSIZE_FAIL = 4, //gave us an error during set blocksize
    MMC_EC_SET_WRITE_BLOCKSIZE_FAIL = 5, //gave us an error during set blocksize
    MMC_EC_SET_MULTI_BLOCKSIZE_FAIL = 6, //gave us an error during set blocksize
    MMC_EC_SET_WRITE_ADDRESS_FAIL = 7, //gave us an error when we told it we want to write block
    MMC_EC_BLOCK_NOT_WRITTEN = 8, //after sending block, it gave us this response
    MMC_EC_SET_READ_ADDRESS_FAIL = 9, //gave us an error when we told it we wanted to read block
    MMC_EC_ERASE_SECTOR_START_FAIL = 10, //mmc gave us an error when we set the start sector for erase
    MMC_EC_ERASE_SECTOR_END_FAIL = 11, //mmc gave us an error when we set the end sector for erase
    MMC_EC_ERASE_SECTORS_FAIL = 12, //mmc gave us an error when we told it to erase tagged sectors
    MMC_EC_BAD_STATE = 13, //we cant start/continue a multi transfer because we didn't start/finish the last one
    MMC_EC_START_MULTI_READ_FAIL = 14, //mmc gave us an error when we started a multi-read
    MMC_EC_READ_NEXT_BLOCK_FAIL = 15, //mmc gave us an error when started to read the next block (in multi-read)
    MMC_EC_STOP_TRANSMISSION_FAIL = 16, //mmc gave us an error when tried to stup a multi read/write transmission
    MMC_EC_WRITE_ALWAYS_BUSY = 17 //after a block write, we waited longer than timeout period for busy signal to end
} MMC_EC;

/////*** END USER CONFIG ***/////

//if you want to slow down the speed of the MMC clock, define delay_clk to a delay_xx() routine
//#define mmc_delay_clk() delay_us(1)
#define mmc_delay_clk() 

#define MMC_BLOCK_SIZE  512

int16_t mmc_last_result = 0;

// FUNCTIONS
//public functions
MMC_EC mmc_init();

MMC_EC mmc_modify_byte(int32_t address, int8_t val);
MMC_EC mmc_modify_block(int32_t address, int16_t block_size, int *ptr);
MMC_EC mmc_write_block(int32_t address, int16_t block_size, int *ptr);

#define  mmc_read_byte(a,p) mmc_read_block(a,1,p)
MMC_EC mmc_read_block(int32_t address, int16_t block_size, int *ptr);

MMC_EC mmc_erase(int32_t address, int32_t sectors);


MMC_EC mmc_read_enable(int32_t address, int16_t block_size);
MMC_EC mmc_read_mult_block(int *ptr);
MMC_EC mmc_read_disable(void);

/* NOT TESTED ROUTINES
short mmc_write_enable(int32_t address, int16_t block_size);
short mmc_write_mult_block(int *ptr);
void  mmc_write_disable();

void  mmc_read_csd(int *ptr);
void  mmc_write_csd(int *ptr);
 */

//private functions
int16_t mmc_send_cmd(int cmd, int32_t arg, int mode);
void mmc_send_data(int d_byte);
int mmc_read_data();
void mmc_select(void);
void mmc_deselect(void);
bool mmc_wait_for_not_busy(int16_t to); //to in 8 clocks
bool mmc_receive_data(int8_t *ptr, int16_t size);

// GLOBALS

typedef enum {
    MMC_STARTUP_STATE = 0,
    MMC_STANDBY_STATE = 1,
    MMC_WRITE_STATE = 2,
    MMC_READ_STATE = 3,
    MMC_ERASE_STATE = 4
} mmc_state_t;

//holds the current block size of our multi-read or multi-write routines
int16_t mmc_blk_size;

#define MMC_CMD_GO_IDLE_STATE          0
#define MMC_CMD_SEND_OP_COND           1
#define MMC_CMD_STOP_TRANSMISSION      12
#define MMC_CMD_SET_BLOCKLEN           16
#define MMC_CMD_READ_SINGLE_BLOCK      17
#define MMC_CMD_READ_MULTITPLE_BLOCK   18
#define MMC_CMD_WRITE_BLOCK            24
#define MMC_CMD_TAG_SECTOR_START       32
#define MMC_CMD_TAG_SECTOR_END         33
#define MMC_CMD_ERASE                  38
#define MMC_CMD_CRC_ON_OFF             59


#endif