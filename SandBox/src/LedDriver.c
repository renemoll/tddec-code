
#include "LedDriver.h"
// #include <stdlib.h>
// #include <memory.h>

static uint16_t* g_ledRegister = NULL;
static uint16_t g_ledState = 0;

static void setState(uint16_t value) {
	g_ledState = value;
	*g_ledRegister = g_ledState;
}

void LedDriver_Create(uint16_t* ledRegister)
{
	g_ledRegister = ledRegister;
	setState(0);
}

void LedDriver_TurnOn(uint16_t ledId)
{
	setState(g_ledState | (1 << (ledId - 1)));
}

void LedDriver_TurnOff(uint16_t ledId)
{
	setState(g_ledState & ~(1 << (ledId - 1)));
}

void LedDriver_TurnAllOn(void)
{
	setState(0xffff);
}

void LedDriver_TurnAllOff(void)
{
	setState(0x0000);
}
