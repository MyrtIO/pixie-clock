#pragma once

#include <stdint.h>

enum FeatureCode : uint8_t {
  Clock = 0,
  Indicators = 1,
  Stopwatch = 2,
};

enum ClockAction : uint8_t {
  SetTime = 0,
};

enum IndicatorsAction : uint8_t {
  SetColor = 0,
  SetBrightness = 1,
};
