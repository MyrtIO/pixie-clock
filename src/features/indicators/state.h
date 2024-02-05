#pragma once

#include <stdint.h>

struct IndicatorsState {
  uint8_t color[3] = {255, 255, 255};
  uint8_t brightness = 255;
};

void copyColor(uint8_t* from, uint8_t* to);

