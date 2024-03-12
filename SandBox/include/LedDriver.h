#ifndef D_LedDriver_H
#define D_LedDriver_H

#include <stdint.h>

void LedDriver_Create(uint16_t* ledState);
void LedDriver_TurnOn(uint16_t ledId);
void LedDriver_TurnOff(uint16_t ledId);

#endif  /* D_LedDriver_H */
