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
        return 255;
      }
      return map(now_, start_, end_, 0, 255);
    }

    void start(size_t ms) {
      start_ = millis();
      end_ = start_ + ms;
    }

  private:
    uint32_t start_ = 0;
    uint32_t end_ = 0;
    uint32_t now_ = 0;
};
