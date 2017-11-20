#ifndef BLD_H
#define	BLD_H
#include "mcc_generated_files/mcc.h"
#include "Data_Convert.h"
#include "Tick_Timer.h"

#define APP_START_ADDR  0x0000                                                  // Application start-address
#define APP_STOP_ADDR   0x3AFF                                                  // Application stop-address    

// <editor-fold defaultstate="collapsed" desc="Intel Hex file format">
typedef enum HEX_RECORD_TYPES {                                                 // Hex format record type
    DATA_RECORD = 0,                                                            // Data
    END_OF_FILE_RECORD,                                                         // End Of File
    EXT_SEG_ADRS_RECORD,                                                        // Extended Segment Address
    START_SEG_ADRS,                                                             // Start Segment Address
    EXT_LIN_ADRS_RECORD,                                                        // Extended Linear Address
    START_LIN_ADRS                                                              // Start Linear Address
} hex_record_type_t;

struct {

    struct {
        uint16_t Phy;                                                           // Physical address of MCU
        uint16_t ELin;                                                          // Extended linear address
    } Addr;

    struct {
        uint8_t BCount;                                                         // Hex Data Len
        uint16_t Write1;                                                        // 32bit-Word Data1
        uint16_t Write2;                                                        // 32bit-Word Data2
    } Data;

    hex_record_type_t RecType;                                                  // Hex record type
} Hex;// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Process tasks">
typedef enum {
    /************************************************************* Main Tasks */
    INIT,                                                                       // Start up, reset buffer
    GET_DATA,                                                                   // Get data from UART
    ENTER_BLD_MODE,                                                             // Check bootloader password
    CONVERT,                                                                    // Un-frame UART streaming data 
    CHECKSUM,                                                                   // Data checksum
    PROGRAM,                                                                    // Write data to SST flash
    REP_SUCCESS,                                                                // Response success-task to PC soft
    REP_ERROR,                                                                  // Response error-task to PC soft
    DEFAULT                                                                     // The other cases
} app_task_t;

struct {                                                                        // Main tasks of this firmware
    app_task_t Prev;
    app_task_t Next;
} Task;// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Tick timer">
struct {
    tick_timer_t Led;                                                           // Toggle led
    tick_timer_t RxTout;                                                        // UART RX timeout
    tick_timer_t BldTout;                                                       // Bootloader timeout
} Tick;// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="UART Buffer">
struct {
    uint8_t Dat[48];                                                            // UART RX buffer Data
    uint8_t Len;                                                                // UART RX buffer Len
} Buf;// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Common variable">
uint8_t i, j;
// </editor-fold>

#endif