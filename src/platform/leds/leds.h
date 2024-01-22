#pragma once

#include <MyrtIO.h>
#include <FastLED.h>
#include "digits_handler.h"

class LEDPlatform : public IOPlatform {
  public:
    void setup() override;
    void draw();
    DigitsHandler* digits();

  private:
    DigitsHandler digits_ = DigitsHandler();
    // DotHandler dot_ = DotHandler();
};
