#pragma once

#include <stdint.h>

struct ClockDigits {
  public:
    uint8_t values_[4] = {0, 0, 0, 0};

    uint8_t* values() {
      return &values_[0];
    }

    void set(uint8_t firstPair, uint8_t secondPair) {
      values_[0] = firstPair / 10;
      values_[1] = firstPair % 10;
      values_[2] = secondPair / 10;
      values_[3] = secondPair % 10;
    }

    void set(uint8_t first, uint8_t second, uint8_t third, uint8_t fourth) {
      values_[0] = first;
      values_[1] = second;
      values_[2] = third;
      values_[3] = fourth;
    }

    // Returns matrix index by digit index.
    // For example, if you request second number (i=1) and it will be 9, you will get 19.
    uint8_t matrixIndex(uint8_t digitIndex) {
      return matrixIndexOf(values_[digitIndex], digitIndex);
    }

    uint8_t matrixIndexOf(uint8_t value, uint8_t position) {
      if (position > 3 || value > 9) {
        return 255;
      }
      return value + (position * 10);
    }

    bool operator == (const ClockDigits& other) const {
      return \
        values_[0] == other.values_[0] &&
        values_[1] == other.values_[1] &&
        values_[2] == other.values_[2] &&
        values_[3] == other.values_[3];
    }

    ClockDigits& operator=(const ClockDigits& other) {
      if (this == &other || *this == other)
          return *this;

      values_[0] = other.values_[0];
      values_[1] = other.values_[1];
      values_[2] = other.values_[2];
      values_[3] = other.values_[3];
      return *this;
  }
};
