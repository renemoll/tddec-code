
extern "C"
{
#include "LedDriver.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LedDriver)
{
    uint16_t ledState = 0;

    void setup()
    {
      LedDriver_Create(&ledState);
    }
};

TEST(LedDriver, Initialization)
{
  // Prepare
  uint16_t ledStateLocal = 0xA5A5;

  // Execute
  LedDriver_Create(&ledStateLocal);

  // Verify
  CHECK_EQUAL(ledStateLocal, 0);
}

TEST(LedDriver, TurnOnLedOne)
{
  // Prepare

  // Execute
  LedDriver_TurnOn(1);

  // Verify
  CHECK_EQUAL(ledState, 0x0001);
}

TEST(LedDriver, TurnOffLedOne)
{
  // Prepare
  LedDriver_TurnOn(1);

  // Execute
  LedDriver_TurnOff(1);

  // Verify
  CHECK_EQUAL(ledState, 0x0000);
}

TEST(LedDriver, TurnOnMultipleLeds)
{
  // Prepare

  // Execute
  LedDriver_TurnOn(1);
  LedDriver_TurnOn(8);
  LedDriver_TurnOn(9);

  // Verify
  CHECK_EQUAL(ledState, 0x0181);
}

TEST(LedDriver, TurnOffMultipleLeds)
{
  // Prepare
  LedDriver_TurnOn(2);
  LedDriver_TurnOn(8);
  LedDriver_TurnOn(9);

  // Execute
  LedDriver_TurnOff(8);
  LedDriver_TurnOff(9);

  // Verify
  CHECK_EQUAL(ledState, 0x0002);
}

TEST(LedDriver, TurnOnAllLeds)
{
  // Prepare

  // Execute
  for (int i = 0; i < 16; ++i) {
    LedDriver_TurnOn(i + 1);  // note: LED ID starts at 1
  }

  // Verify
  CHECK_EQUAL(ledState, 0xFFFF);
}

TEST(LedDriver, TurnOffAllLeds)
{
  // Prepare
  for (int i = 0; i < 16; ++i) {
    LedDriver_TurnOn(i + 1);
  }

  // Execute
  for (int i = 0; i < 16; ++i) {
    LedDriver_TurnOff(i + 1);
  }

  // Verify
  CHECK_EQUAL(ledState, 0x0000);
}

TEST(LedDriver, TurningOnUnsupportedLedHasNoEffect)
{
  // Prepare
  LedDriver_TurnOn(2);
  LedDriver_TurnOn(8);
  LedDriver_TurnOn(9);

  // Execute
  LedDriver_TurnOn(17);

  // Verify
  CHECK_EQUAL(ledState, 0x0182);
}
