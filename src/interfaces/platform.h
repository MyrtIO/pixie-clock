#pragma once

#include <stdint.h>
#include <stored.h>

class ILEDPlatform {
  public:
    virtual void setDigits(uint8_t firstPair, uint8_t secondPair) = 0;
    virtual void setDigitsColor(uint8_t r, uint8_t g, uint8_t b) = 0;
    virtual void setBrightness(uint8_t brightness) = 0;
    virtual bool getPower() = 0;
    virtual void setPower(bool status) = 0;
    virtual void setEffect(uint8_t effectCode) = 0;
    virtual void handlePing() = 0;
};

class IRTCPlatform {
  public:
    virtual uint8_t getHours() = 0;
    virtual uint8_t getMinutes() = 0;
    virtual uint8_t getSeconds() = 0;
    virtual uint32_t getUnixTime() = 0;
    virtual void setTime(uint8_t hours, uint8_t minutes, uint8_t seconds);
};

class IStoragePlatform {
  public:
    virtual bool append(Stored *value) = 0;
};
