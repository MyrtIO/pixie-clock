#pragma once

#include <MyrtIO.h>
#include "platform.h"
#include "interfaces/features.h"

class IndicatorsFeature : public IOFeature {
  public:
    // Constructor
    IndicatorsFeature();

    // Function that runs as a background task.
    void onTask();

    uint8_t code();

    // Handles action requests and performs actions based on the request.
    // Returns true if the action was successfully handled, false otherwise.
    bool onAction(IOActionRequest* request);

  private:
    LEDPlatform* leds_ = IO_INJECT(LEDPlatform);

    // Private method to handle setting LED color based on the request.
    // Returns true if the color was successfully set, false otherwise.
    bool handleSetColor_(IOActionRequest* request);

    // Private method to handle setting LED brightness based on the request.
    // Returns true if the brightness was successfully set, false otherwise.
    bool handleSetBrightness_(IOActionRequest* request);
};
