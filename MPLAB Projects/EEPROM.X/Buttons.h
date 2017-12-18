#ifndef BUTTONS_H
#define	BUTTONS_H
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include "Tick_timer.h"
#define L2H 0// Low to High edge
#define H2L 1// High to Low edge

typedef enum BUTTON_TASKS
{
    BT_UNPRESSED=0,
    BT_CHECK_AGAIN,
    BT_CHECK_NOISE,
    BT_PRESSED,
} button_task_t;

typedef struct
{
    tick_timer_t Tick;
    // This lib
    button_task_t BtTask;
    bool State;
} button_t;

bool BT_Is_Pressed(button_t *BT, bool signal, bool edge, uint32_t detect_time);
void Button_Init(button_t *BT);

#endif