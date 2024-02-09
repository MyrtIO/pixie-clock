#pragma once

#include <Timer.h>
#include "brightness.h"

constexpr uint8_t kSleepBrightness = 10;
constexpr size_t kSleepTimeout = 15000;

class SleepListener {
public:
  void handle();
  void awake();
  void start(SmoothBrightness* brightness);

private:
  Timer wait_;
  SmoothBrightness* brightness_;
  uint8_t lastValue_;
  bool sleeping_ = false;
};
