#pragma once
#include <MyrtIO.h>

#include "leds/leds_platform.h"
#include "rtc/platform.h"
#include "storage/storage_platform.h"

IO_PROVIDE(ILEDPlatform, LEDPlatform);
IO_PROVIDE(IRTCPlatform, RTCPlatform);
IO_PROVIDE(IStoragePlatform, StoragePlatform);
