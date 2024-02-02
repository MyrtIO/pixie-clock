#include <MyrtIO.h>
#include <MyrtIO/serial_provider.h>
#include <platform.h>
#include <features.h>

SerialRequestProvider serialProvider(&Serial);
IODispatcher io;

void setup() {
  serialProvider.setListener(&io);
  Serial.begin(9600);
  io.setup()
    ->platforms(
      IO_INJECT(LEDPlatform),
      IO_INJECT(RTCPlatform)
    )
    ->features(
      IO_INJECT(ClockFeature),
      IO_INJECT(IndicatorsFeature),
      IO_INJECT(StopwatchFeature)
      // IO_INJECT(PersistentConfigCapability)
    )
    ->defaultFeature(
      IO_INJECT(ClockFeature)
    );
}

void loop() {
  serialProvider.handle();
  io.handle();
}
