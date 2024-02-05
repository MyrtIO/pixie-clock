#pragma once

#include <MyrtIO.h>
#include <platform.h>
#include <Timer.h>
#include "interfaces/features.h"

class StopwatchFeature : public IOFeature {
public:

  StopwatchFeature();
  void setup() override;

  // Handles the primary tasks
  void onTask();

  uint8_t code();

  // Handles action requests
  bool onAction(IOActionRequest* request, IOFeatureController* controller);

private:
  LEDPlatform* leds_ = IO_INJECT(LEDPlatform);
  RTCPlatform* rtc_ = IO_INJECT(RTCPlatform);
  uint32_t startTime_ = 0;
};
