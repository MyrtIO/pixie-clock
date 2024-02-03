#pragma once

#include "request.h"
#include "device.h"

class IODispatcher : public IORequestListener, public IOFeatureController {
  public:
    // Initializes the IODevice
    IODevice* setup();

    // Handles incoming IORequest
    void onRequest(IORequest* request) override;

    // Primary handler for processing
    void handle();

    void setActive(uint8_t code);

    void unsetActive();

  private:
      IODevice* device_ = nullptr;
      IOFeature* active_ = nullptr;

      void runAction_(IORequest* request, IOFeature* target);
};
