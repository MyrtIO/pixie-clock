#pragma once

#include <MyrtIO.h>
#include <TroykaRTC.h>
#include "interfaces/platform.h"

class RTCPlatform : public IOPlatform, public IRTCPlatform {
  public:
    // Function called at the start of each loop iteration to read the RTC time.
    void onLoopStart();

    // Function called at the end of each loop iteration.
    void onLoopEnd();

    // Setup function to initialize the RTC and set the initial time.
    void setup() override;

    // Set the RTC time in hours, minutes, and seconds.
    void setTime(uint8_t hours, uint8_t minutes, uint8_t seconds);

    // Get the current hour from the RTC.
    uint8_t getHours();

    // Get the current minutes from the RTC.
    uint8_t getMinutes();

    // Get the current seconds from the RTC.
    uint8_t getSeconds();

    uint32_t getUnixTime();

  private:
    RTC clock;
};
