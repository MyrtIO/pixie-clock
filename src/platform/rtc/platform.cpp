#include "platform.h"

// Implementation of the function called at the start of each loop iteration to read the RTC time.
void RTCPlatform::onLoopStart() {
  clock.read();
}

// Implementation of the function called at the end of each loop iteration.
void RTCPlatform::onLoopEnd() {
  // Do nothing
}

// Implementation of the setup function to initialize the RTC and set the initial time.
void RTCPlatform::setup() {
  clock.begin();
  clock.start();
}

// Implementation of the public method to set the RTC time in hours, minutes, and seconds.
void RTCPlatform::setTime(uint8_t hours, uint8_t minutes, uint8_t seconds) {
  clock.setHour(hours);
  clock.setMinute(minutes);
  clock.setSecond(seconds);
}

// Implementation of the public method to get the current hour from the RTC.
uint8_t RTCPlatform::getHours() {
  return clock.getHour();
}

// Implementation of the public method to get the current minutes from the RTC.
uint8_t RTCPlatform::getMinutes() {
  return clock.getMinute();
}

// Implementation of the public method to get the current seconds from the RTC.
uint8_t RTCPlatform::getSeconds() {
  return clock.getSecond();
}

uint32_t RTCPlatform::getUnixTime() {
  return clock.getUnixTime();
}
