#pragma once

#include <Arduino.h>
#include "../request.h"

/**
 * @class SerialRequest
 * Represents a request received over serial communication.
 */
class SerialRequest : public IORequest {
  public:
    SerialRequest(
      uint8_t* payload,
      uint8_t payloadLength,
      Stream* serial
    ) : IORequest(payload, payloadLength) {
      serial_ = serial;
    }
    void flushMessage(uint8_t* message, uint8_t messageLength) override;

  private:
    Stream* serial_ = nullptr;
};
