#pragma once

#include <stdint.h>

enum CapabilityCode : uint8_t {
  Clock = 0,
  Indicators = 1,
};

enum ClockAction : uint8_t {
  SetTime = 0,
};

enum IndicatorsAction : uint8_t {
  SetColor = 1,
  SetBrightness = 2
};
