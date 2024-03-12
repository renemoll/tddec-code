
#include "LedDriver.h"
// #include <stdlib.h>
// #include <memory.h>

static uint16_t* g_ledState = NULL;

void LedDriver_Create(uint16_t* ledState)
{
	g_ledState = ledState;
	*g_ledState = 0;
}

void LedDriver_TurnOn(uint16_t ledId)
{
	*g_ledState |= (1 << (ledId - 1));
}

void LedDriver_TurnOff(uint16_t ledId)
{
	*g_ledState &= ~(1 << (ledId - 1));
}