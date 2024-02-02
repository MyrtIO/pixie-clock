#pragma once

#include <stdint.h>
#include "request.h"
#include "action_request.h"

#define IO_DEVICE_MAX_FEATURES 8
#define IO_DEVICE_MAX_PLATFORMS 8

class IOPlatform {
  public:
    virtual void setup() = 0;
    virtual void onLoopStart() = 0;
    virtual void onLoopEnd() = 0;
};

class IOFeature {
  public:
    virtual void onTask() = 0;
    virtual uint8_t code() = 0;
    virtual bool onAction(IOActionRequest* request) = 0;
};

class IODevice {
  public:
    uint8_t featuresCount = 0;
    uint8_t platformsCount = 0;
    IOFeature* featureList[IO_DEVICE_MAX_FEATURES];
    IOPlatform* platformList[IO_DEVICE_MAX_PLATFORMS];
    IOFeature* idleFeature = nullptr;

    IODevice* defaultFeature(IOFeature* feature) {
      idleFeature = feature;
      return this;
    }

    template<typename... Args>
    IODevice* features(IOFeature *last) {
      addFeature_(last);
      return this;
    }

    template<typename... Args>
    IODevice* features(IOFeature* first, Args... args) {
      addFeature_(first);
      return features(args...);
    }

    template<typename... Args>
    IODevice* platforms(IOPlatform *last) {
      addPlatform_(last);
      return this;
    }

    template<typename... Args>
    IODevice* platforms(IOPlatform* first, Args... args) {
      addPlatform_(first);
      return platforms(args...);
    }

  private:
    bool addFeature_(IOFeature* c) {
      if (featuresCount >= IO_DEVICE_MAX_FEATURES) {
        // TODO: add handling
        return false;
      }
      featureList[featuresCount] = c;
      featuresCount++;
      return true;
    }

    bool addPlatform_(IOPlatform* c) {
      c->setup();
      if (platformsCount >= IO_DEVICE_MAX_PLATFORMS) {
        // TODO: add handling
        return false;
      }
      platformList[platformsCount] = c;
      platformsCount++;
      return true;
    }
};
