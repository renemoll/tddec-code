
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
  CHECK_EQUAL(0, ledStateLocal);
}

TEST(LedDriver, TurnOnLedOne)
{
  // Prepare

  // Execute
  LedDriver_TurnOn(1);

  // Verify
  CHECK_EQUAL(0x0001, ledState);
}

TEST(LedDriver, TurnOffLedOne)
{
  // Prepare
  LedDriver_TurnOn(1);

  // Execute
  LedDriver_TurnOff(1);

  // Verify
  CHECK_EQUAL(0x0000, ledState);
}

TEST(LedDriver, TurnOnMultipleLeds)
{
  // Prepare

  // Execute
  LedDriver_TurnOn(1);
  LedDriver_TurnOn(8);
  LedDriver_TurnOn(9);

  // Verify
  CHECK_EQUAL(0x0181, ledState);
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
  CHECK_EQUAL(0x0002, ledState);
}

TEST(LedDriver, TurnOnAllLeds)
{
  // Prepare

  // Execute
  LedDriver_TurnAllOn();

  // Verify
  CHECK_EQUAL(0xFFFF, ledState);
}

TEST(LedDriver, TurnOffAllLeds)
{
  // Prepare
  LedDriver_TurnAllOn();

  // Execute
  LedDriver_TurnAllOff();

  // Verify
  CHECK_EQUAL(0x0000, ledState);
}

TEST(LedDriver, TurningOnUnsupportedLedHasNoEffect)
{
  // Prepare
  LedDriver_TurnOn(2);
  LedDriver_TurnOn(8);
  LedDriver_TurnOn(9);

  // Execute
  LedDriver_TurnOn(0);
  LedDriver_TurnOn(17);

  // Verify
  CHECK_EQUAL(0x0182, ledState);
}

TEST(LedDriver, RegisterIsWriteOnly)
{
  // Prepare
  ledState = 0xffff;

  // Execute
  LedDriver_TurnOn(8);

  // Verify
  CHECK_EQUAL(0x0080, ledState);
}
