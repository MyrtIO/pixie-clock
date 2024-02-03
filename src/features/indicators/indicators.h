#pragma once

#include <MyrtIO.h>
#include "platform.h"
#include "interfaces/features.h"

class IndicatorsFeature : public IOFeature {
public:
  IndicatorsFeature();

  uint8_t code();
  void onTask();
  bool onAction(IOActionRequest* request, IOFeatureController* controller);

private:
  LEDPlatform* leds_ = IO_INJECT(LEDPlatform);

  bool handleSetColor_(IOActionRequest* request);
  bool handleSetBrightness_(IOActionRequest* request);
  bool handleGetColor_(IOActionRequest* request);
  bool handleGetBrightness_(IOActionRequest* request);
};
