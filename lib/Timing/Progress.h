// Copyright 2022, Mikhael Khrustik <misha@myrt.co>
//
// All components of Myrt Desk Firmware are licensed under the BSD 3-Clause
// License. See LICENSE.txt for details.

#pragma once

#include <Arduino.h>

class Progress {
  public:
    uint8_t get() {
      now_ = millis();
      if (now_ >= end_) {
        return max_;
      }
      return map(now_, start_, end_, 0, max_);
    }

    void start(size_t ms) {
      start_ = millis();
      end_ = start_ + ms;
    }

    void setMax(uint8_t max) {
      max_ = max;
    }

  private:
    uint32_t start_ = 0;
    uint32_t end_ = 0;
    uint32_t now_ = 0;
    uint8_t max_ = 255;
};
