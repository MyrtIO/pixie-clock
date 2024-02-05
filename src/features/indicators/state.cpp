#include "state.h"

void copyColor(uint8_t* from, uint8_t* to) {
  for (uint8_t i = 0; i < 3; i++) {
    to[i] = from[i];
  }
}
