#pragma once

#include <MyrtIO.h>
#include <platform/rtc_storage.h>
#include "interfaces/capabilities.h"

#include "config.h"

class PersistentConfigCapability : public IOCapability {
  public:
    uint8_t code = CapabilityCode::PersistentConfig;

    PersistentConfigCapability() {

    }

    void handlePrimary() {

    }

    void handleBackground() {

    }

    bool handleAction(IOActionRequest* request) {
      return false;
    }

    void setup() {
      // storage_.attach(&descriptor_);
    }

    Config *get();
    void write();

  private:
    Config config_;
    // Stored descriptor_ = Stored(config_);
    // RTCStoragePlatform storage_;
};
