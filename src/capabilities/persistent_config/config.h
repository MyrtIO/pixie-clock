#pragma once

#include <stdint.h>

struct Config {
  uint32_t digits_color_[4] = {0, 0, 0, 0};
  uint32_t dot_color = 0;
};

extern Config config;
