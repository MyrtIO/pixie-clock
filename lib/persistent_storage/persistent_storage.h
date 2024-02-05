#pragma once

#include <EEPROM.h>
#include <Arduino.h>
#include <Timer.h>
#include "stored.h"

template <int STORE_COUNT = 8, int STORE_SIZE = 128, int STORE_UPDATE_INTERVAL = 5000>
class PersistentStorage {
public:
  void handle() {
    if (update_.isDone()) {
      for (uint8_t i = 0; i < count_; i++) {
        if (descriptors_[i]->shouldUpdate) {
          write_(descriptors_[i]);
          descriptors_[i]->shouldUpdate = false;
        }
      }
      update_.set(STORE_UPDATE_INTERVAL);
    }
  }

  void initialize() {
    // TODO: Add ESP32 support
    // EEPROM.begin(STORE_SIZE);
  }

  bool append(Stored *value) {
    if (count_ == STORE_COUNT - 1
      || (nextAddr_ + value->size + 1) > STORE_SIZE) {
      return false;
    }
    value->addr = nextAddr_;
    nextAddr_ += value->size + 1;
    descriptors_[count_] = value;
    count_++;
    if (isCorrect_(value)) {
      load_(value);
    } else {
      EEPROM.write(value->addr + value->size, value->key);
      write_(value);
    }
    return true;
  }

private:
  Stored *descriptors_[STORE_COUNT];
  Timer update_;
  uint8_t count_ = 0;
  uint16_t nextAddr_ = 0;

  bool isCorrect_(Stored *value) {
      return EEPROM.read(value->addr + value->size) == value->key;
  }

  void load_(Stored *value) {
    for (uint16_t i = 0; i < value->size; i++) {
      value->data[i] = EEPROM.read(value->addr + i);
    }
  }

  void write_(Stored *value) {
    for (uint16_t i = 0; i < value->size; i++) {
      EEPROM.update(value->addr + i, value->data[i]);
    }
    // TODO: Add ESP32 support
    // EEPROM.commit();
  }
};
