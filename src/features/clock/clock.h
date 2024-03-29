#pragma once

#include <MyrtIO.h>
#include <platform.h>
#include <Timer.h>
#include "interfaces/features.h"

class ClockFeature : public IOFeature {
public:

  ClockFeature();

  void setup() override;

  // Handles the primary tasks
  void onTask();

  uint8_t code();

  // Handles action requests
  bool onAction(IOActionRequest* request, IOFeatureController* controller);

private:
  ILEDPlatform* leds_ = IO_INJECT(ILEDPlatform);
  IRTCPlatform* rtc_ = IO_INJECT(IRTCPlatform);

  bool handleSetTime_(IOActionRequest* request);
};
