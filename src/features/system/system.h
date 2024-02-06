#pragma once

#include <MyrtIO.h>
#include <platform.h>
#include <Timer.h>
#include "interfaces/features.h"

class SystemFeature : public IOFeature {
public:

  SystemFeature();
  void setup() override;

  // Handles the primary tasks
  void onTask();

  uint8_t code();

  // Handles action requests
  bool onAction(IOActionRequest* request, IOFeatureController* controller);

private:
  bool handleGetName_(IOActionRequest* request);
  ILEDPlatform* leds_ = IO_INJECT(ILEDPlatform);
};
