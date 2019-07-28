#ifndef LIBAVRHAL_TIMER_H
#define LIBAVRHAL_TIMER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct Timer_s {
    uint8_t clock_select;
    void (*overflow_cb)(void);
} Timer;

Timer timers[1];

void Timer_Initialize(Timer* self, uint8_t clock_select, void* overflow_cb);
void Timer_Start(Timer* self);
void Timer_Stop(Timer* self);
void Timer_Clear(Timer* self, bool restart);

#endif
