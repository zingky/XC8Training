#include <stdbool.h>
#include <stdint.h>

#define RTC_SEC     0
#define RTC_MIN     1
#define RTC_HOUR    2
#define RTC_WKDAY   3
#define RTC_DATE    4
#define RTC_MTH     5
#define RTC_YEAR    6
#define RTC_CONTROL 7
#define RTC_OSC     8
#define RTC_ALM0SEC   10
#define RTC_ALM0MIN   11
#define RTC_ALM0HOUR  12
#define RTC_ALM0WKDAY 13
#define RTC_ALM0DATE  14
#define RTC_ALM0MTH   15
#define RTC_ALM1SEC   17
#define RTC_ALM1MIN   18
#define RTC_ALM1HOUR  19
#define RTC_ALM1WKDAY 20
#define RTC_ALM1DATE  21
#define RTC_ALM1MTH   22
#define RTC_Get_DateTime() RTC_Get_Date(); RTC_Get_Time()

volatile bool rtc_flag;
volatile uint8_t date_time[8];

uint8_t bcd2int(uint8_t bcd);
uint8_t int2bcd(uint8_t i);
void RTC_Write(uint8_t time_var, uint8_t rtcc_reg);
uint8_t RTC_Read(uint8_t rtcc_reg) ;
void RTC_Set_DateTime(uint8_t day, uint8_t mth, uint8_t year, uint8_t dow,
                      uint8_t hour, uint8_t min, uint8_t sec, bool leap);
void RTC_Get_Date();
void RTC_Get_Time();
void RTC_Init(int8_t trim);