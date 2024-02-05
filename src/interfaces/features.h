#pragma once

#include <stdint.h>

enum FeatureCode : uint8_t {
  System = 0,
  Clock = 1,
  Indicators = 2,
  Stopwatch = 3,
};

enum SystemAction : uint8_t {
  Ping = 0,
  GetName = 1,
};

enum ClockAction : uint8_t {
  ActivateClockFeature = 0,
  SetTime = 1,
};

enum IndicatorsAction : uint8_t {
  SetColor = 0,
  SetBrightness = 1,
  GetColor = 2,
  GetBrightness = 3,
  SetPower = 4,
  GetPower = 5,
};

enum StopwatchAction : uint8_t {
  ActivateStopwatchFeature = 0,
};
