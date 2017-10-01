#ifndef VIM332DP_LCD_MAPS_H
#define	VIM332DP_LCD_MAPS_H
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#define SEG_RC      SEG0COM0
#define SEG_BATT    SEG0COM1
#define SEG_MINUS   SEG0COM2
#define SEG_AC      SEG0COM3

#define SEG_DH      SEG1COM0
#define SEG_RH      SEG1COM1
#define SEG_4BC     SEG1COM2
#define SEG_DP3     SEG1COM3

#define SEG_3A      SEG2COM0
#define SEG_3F      SEG2COM1
#define SEG_3E      SEG2COM2
#define SEG_3D      SEG2COM3

#define SEG_3B      SEG3COM0
#define SEG_3G      SEG3COM1
#define SEG_3C      SEG3COM2
#define SEG_DP2     SEG3COM3

#define SEG_2A      SEG4COM0
#define SEG_2F      SEG4COM1
#define SEG_2E      SEG4COM2
#define SEG_2D      SEG4COM3

#define SEG_2B      SEG5COM0
#define SEG_2G      SEG5COM1
#define SEG_2C      SEG5COM2
#define SEG_DP1     SEG5COM3

#define SEG_1A      SEG6COM0
#define SEG_1F      SEG6COM1
#define SEG_1E      SEG6COM2
#define SEG_1D      SEG6COM3

#define SEG_1B      SEG7COM0
#define SEG_1G      SEG7COM1
#define SEG_1C      SEG7COM2
#define SEG___      SEG7COM3

#define SEG_S1      SEG8COM0
#define SEG_S2      SEG8COM1
#define SEG_m       SEG8COM2
#define SEG_M       SEG8COM3

#define SEG_A       SEG9COM0
#define SEG_V       SEG9COM1
#define SEG_K       SEG9COM2
#define SEG_S3      SEG9COM3

#define SegDisplayOn(x)  x=1
#define SegDisplayOff(x) x=0

void SegDisplayInit();
void SegDisplayDigit(uint8_t digit, uint8_t value, bool state);
void SegDisplayNum(uint16_t value, uint8_t dotIdx);

#endif