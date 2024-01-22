#pragma once

#include <stdint.h>
#include "request.h"
#include "action_request.h"

#define IO_DEVICE_MAX_CAPABILITIES 8

class IOPlatform {
  public:
    virtual void setup() = 0;
};

class IOCapability {
  public:
    uint8_t code;

    virtual void setup() = 0;
    virtual void handlePrimary() = 0;
    virtual void handleBackground() = 0;
    virtual bool handleAction(IOActionRequest* request) = 0;
};

class IODevice {
  public:
    uint8_t count = 0;
    IOCapability* list[IO_DEVICE_MAX_CAPABILITIES];
    IOCapability* idle = nullptr;

    IODevice* defaultCapability(IOCapability* capability) {
      idle = capability;
      return this;
    }

    template<typename... Args>
    IODevice* capabilities(IOCapability *last) {
      addCapability_(last);
      return this;
    }

    template<typename... Args>
    IODevice* capabilities(IOCapability* first, Args... args) {
      addCapability_(first);
      return capabilities(args...);
    }

    template<typename... Args>
    IODevice* platform(IOPlatform *last) {
      last->setup();
      return this;
    }

    template<typename... Args>
    IODevice* platform(IOPlatform* first, Args... args) {
      first->setup();
      return platform(args...);
    }

  private:
    bool addCapability_(IOCapability* c) {
      if (count >= IO_DEVICE_MAX_CAPABILITIES) {
        // TODO: add handling
        return false;
      }
      list[count] = c;
      count++;
      return true;
    }
};
