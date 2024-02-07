#include <MyrtIO.h>
#include <MyrtIO/serial_provider.h>
#include <platform.h>
#include <features.h>

SerialRequestProvider serialProvider(&Serial);
IODispatcher io;

SystemFeature systemFeature;
ClockFeature clockFeature;
IndicatorsFeature indicatorsFeature;
StopwatchFeature stopwatchFeature;

void setup() {
  serialProvider.setListener(&io);
  Serial.begin(28800);
  io.setup()
    ->platforms(
      IO_INJECT_INSTANCE(LEDPlatform),
      IO_INJECT_INSTANCE(RTCPlatform),
      IO_INJECT_INSTANCE(StoragePlatform)
    )
    ->features(
      &systemFeature,
      &clockFeature,
      &indicatorsFeature,
      &stopwatchFeature
    )
    ->defaultFeature(&clockFeature);
}

void loop() {
  serialProvider.handle();
  io.handle();
}
