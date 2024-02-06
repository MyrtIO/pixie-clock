#pragma once

#include <MyrtIO.h>
#include <platform.h>
#include "interfaces/features.h"
#include "state.h"
#include "stored.h"

class IndicatorsFeature : public IOFeature {
public:
  IndicatorsFeature();
  void setup() override;

  uint8_t code();
  void onTask();
  bool onAction(IOActionRequest* request, IOFeatureController* controller);

private:
  IndicatorsState state_;
  Stored stateDescriptor_ = Stored(state_, FeatureCode::Indicators);
  ILEDPlatform* leds_ = IO_INJECT(ILEDPlatform);
  IStoragePlatform* storage_ = IO_INJECT(IStoragePlatform);

  bool handleSetColor_(IOActionRequest* request);
  bool handleSetBrightness_(IOActionRequest* request);
  bool handleGetColor_(IOActionRequest* request);
  bool handleGetBrightness_(IOActionRequest* request);
  bool handleSetPower_(IOActionRequest* request);
  bool handleGetPower_(IOActionRequest* request);
  bool handleSetEffect_(IOActionRequest* request);
  bool handleGetEffect_(IOActionRequest* request);
};
