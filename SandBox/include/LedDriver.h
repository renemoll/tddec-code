#ifndef D_LedDriver_H
#define D_LedDriver_H

#include <stdint.h>

void LedDriver_Create(uint16_t* ledRegister);
void LedDriver_TurnOn(uint16_t ledId);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnOff(uint16_t ledId);
void LedDriver_TurnAllOff(void);

#endif  /* D_LedDriver_H */
