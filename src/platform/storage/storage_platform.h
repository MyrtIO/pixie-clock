#pragma once

#include <MyrtIO.h>
#include <persistent_storage.h>
#include "interfaces/platform.h"

class StoragePlatform : public IOPlatform, public IStoragePlatform {
  public:
    void onLoopStart();
    void onLoopEnd();
    void setup() override;
    bool append(Stored *value);

  private:
    PersistentStorage<8, 128, 5000> storage_;
};
