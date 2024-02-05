#pragma once

#include <pixeltypes.h>
#include "clock_digits.h"

struct LEDState {
  ClockDigits currentDigits;
  ClockDigits targetDigits;
  CRGB currentColor = 0xff3503;
  CRGB targetColor = 0xff3503;
  bool animating = false;
  bool enabled = true;

  CRGB finalTargetColor() {
    return enabled ? targetColor : CRGB::Black;
  }
};
