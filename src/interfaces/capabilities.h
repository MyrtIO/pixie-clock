#pragma once

#include <stdint.h>

enum CapabilityCode : uint8_t {
  Clock = 0,
  PersistentConfig = 1,
};

enum ClockAction : uint8_t {
  SetTime = 0,
  SetColor = 1,
  SetBrightness = 2
};
