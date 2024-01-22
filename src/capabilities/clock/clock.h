#pragma once

#include <MyrtIO.h>
#include <platform.h>
#include <Timer.h>
#include "interfaces/capabilities.h"

class ClockCapability : public IOCapability {
public:
  ClockCapability();

  // Handles the primary tasks
  void handlePrimary();

  // Handles background tasks
  void handleBackground();

  // Handles action requests
  bool handleAction(IOActionRequest* request);

  // Initializes the capability
  void setup();

private:
  LEDPlatform* leds_ = ioInject(LEDPlatform);
  RTCPlatform* rtc_ = ioInject(RTCPlatform);
  Timer nextFrame_;
  uint8_t currentHour_ = 0;
  uint8_t currentMinute_ = 0;
  bool show_ = true;

  bool handleSetTime_(IOActionRequest* request);
  bool handleSetColor_(IOActionRequest* request);
  bool handleSetBrightness_(IOActionRequest* request);
};
