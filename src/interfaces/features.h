#pragma once

#include <stdint.h>

enum FeatureCode : uint8_t {
  Clock = 0,
  Indicators = 1,
  Stopwatch = 2,
};

enum ClockAction : uint8_t {
  ActivateClockFeature = 0,
  SetTime = 1,
};

enum IndicatorsAction : uint8_t {
  SetColor = 0,
  SetBrightness = 1,
};

enum StopwatchAction : uint8_t {
  ActivateStopwatchFeature = 0,
};
