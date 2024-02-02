#pragma once

#include <MyrtIO.h>

class SmoothBrightness : public IRenderer {
  public:
    // Public method to handle frame and update brightness gradually.
    // Returns true if the brightness needs to be updated, false otherwise.
    bool handleFrame();

    // Set the target brightness level and initiate a gradual transition.
    void setBrightness(uint8_t value);

    // Set the target brightness level immediately without transition.
    void setBrightnessImmediately(uint8_t value);

  private:
    uint8_t current_ = 255;
    uint8_t previous_ = 255;
    uint8_t target_ = 255;
    bool mustRender_ = false;
    Progress transition_;
    int brightnessStep_ = 0;
};
