#pragma once

#include <MyrtIO.h>
#include <platform.h>
#include <Timer.h>
#include "interfaces/features.h"

class SystemFeature : public IOFeature {
public:

  SystemFeature();

  // Handles the primary tasks
  void onTask();

  uint8_t code();

  // Handles action requests
  bool onAction(IOActionRequest* request, IOFeatureController* controller);

private:
  bool handleGetName_(IOActionRequest* request);
};
