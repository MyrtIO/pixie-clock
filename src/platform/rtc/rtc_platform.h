#pragma once

#include <MyrtIO.h>
#include <TroykaRTC.h>

class RTCPlatform : public IOPlatform {
  public:
    void setup() override {
      clock.begin();
      clock.read();
      setTime(getHours(), getMinutes(), getSeconds());
    }

    void setTime(uint8_t hours, uint8_t minutes, uint8_t seconds) {
      clock.setHour(hours);
      clock.setMinute(minutes);
      clock.setSecond(seconds);
    }

    void read() {
      clock.read();
    }

    uint8_t getHours() {
      return clock.getHour();
    }

    uint8_t getMinutes() {
      return clock.getMinute();
    }

    uint8_t getSeconds() {
      return clock.getSecond();
    }

  private:
    RTC clock;
};
