#include <stdbool.h>
#include <stdint.h>

enum {
    MCP7941x_SEC = 0,
    MCP7941x_MIN = 1,
    MCP7941x_HOUR = 2,
    MCP7941x_WKDAY = 3,
    MCP7941x_DATE = 4,
    MCP7941x_MTH = 5,
    MCP7941x_YEAR = 6,
    MCP7941x_CONTROL = 7,
    MCP7941x_OSC = 8,
    MCP7941x_ALM0SEC = 10,
    MCP7941x_ALM0MIN = 11,
    MCP7941x_ALM0HOUR = 12,
    MCP7941x_ALM0WKDAY = 13,
    MCP7941x_ALM0DATE = 14,
    MCP7941x_ALM0MTH = 15,
    MCP7941x_ALM1SEC = 17,
    MCP7941x_ALM1MIN = 18,
    MCP7941x_ALM1HOUR = 19,
    MCP7941x_ALM1WKDAY = 20,
    MCP7941x_ALM1DATE = 21,
    MCP7941x_ALM1MTH = 22
} MCP7941x_REG;

typedef enum {
    // Square Wave Clock Output Frequency Select bits
    _1Hz = 0x40,
    _4096Hz = 0x41,
    _8192Hz = 0x42,
    _32768Hz = 0x43,
    _0Hz = 0x00,// Off MFP
    //  Logic Level for General Purpose Output bit (Or with above)
    L2H = 0x80,
    H2L = 0x00
} mcp7941x_sqwfs_t;

typedef struct {
    uint8_t DoWeek;
    uint8_t Date;
    uint8_t Month;
    uint16_t Year;
} mcp7941x_date_t;

typedef struct {
    uint8_t Hour;
    uint8_t Minute;
    uint8_t Second;
} mcp7941x_time_t;

typedef struct {
    mcp7941x_date_t Date;
    mcp7941x_time_t Time;
} mcp7941x_rtcc_t;

void MCP7941x_Set_Date(mcp7941x_date_t *pData);
void MCP7941x_Set_Time(mcp7941x_time_t *pData);
void MCP7941x_Set_DateTime(mcp7941x_rtcc_t *pData);

void MCP7941x_Get_Date(mcp7941x_date_t *pData);
void MCP7941x_Get_Time(mcp7941x_time_t *pData);
void MCP7941x_Get_DateTime(mcp7941x_rtcc_t *pData);

volatile bool *MCP7941x_MFP(bool RW);

void MCP7941x_Init(uint8_t trim, mcp7941x_sqwfs_t mfp_clk);