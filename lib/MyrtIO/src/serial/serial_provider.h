#pragma once

#include <Arduino.h>
#include "../request.h"
#include "serial_request.h"

#define SERIAL_PROVIDER_READ_DELAY 10

/**
 * @class SerialRequestProvider
 * Provides functionalities to handle and process serial requests.
 */
class SerialRequestProvider : public IORequestProvider {
public:
    SerialRequestProvider(Stream* serial);

    /**
     * Handles incoming serial data and processes requests.
     */
    void handle();

    void setup() {
      
    }

    /**
     * Creates a new SerialRequest instance.
     * @return Pointer to the newly created SerialRequest instance.
     */
    SerialRequest* createRequest();

private:
    Stream* serial_;
    uint8_t message_[IO_PROTOCOL_MESSAGE_MAX_LENGTH];

    bool findHeader_();
    bool readLength_();
    bool readBody_();
    void emitPayload_();
};
