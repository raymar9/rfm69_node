#ifndef LIBAVRHAL_IO_H_
#define LIBAVRHAL_IO_H_

#include <stdint.h>

void Io_SetInput(uint8_t pin);
void Io_SetOutput(uint8_t pin);

void Io_EnablePullUp(uint8_t pin);
void Io_DisablePullUp(uint8_t pin);

void Io_SetHigh(uint8_t pin);
void Io_SetLow(uint8_t pin);
void Io_Toggle(uint8_t pin);

uint8_t Io_GetValue(uint8_t pin);

#endif
