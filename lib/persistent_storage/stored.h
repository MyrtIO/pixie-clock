#pragma once

#include <stdint.h>

class Stored {
 public:
  uint8_t *data;
  uint16_t size;
  uint8_t key;
  uint16_t addr = 0;
  bool shouldUpdate = false;

  template <typename T> Stored(const T &data, uint8_t key) {
    this->data = (uint8_t*) &data;  // NOLINT(readability/casting)
    size = sizeof(T);
    this->key = key;
  }

  void update() {
    shouldUpdate = true;
  }
};

