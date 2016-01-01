#include <cushion.h>
#include <examples/CushionTest/mock.h>
#include <cushion_hardware.h>
#include <events.h>
#include <tinyarduinotest.h>
#include "Arduino.h"

const int MAX_CAPACITY = 4;
EventBuffer eb = EventBuffer(MAX_CAPACITY);

Cushion* cushion;

MockHardware *hardware= new MockHardware;

void test_beeps_for_one_sec_after_sitting_down() {
  ASSERT("timer one should not be enabled",!hardware->timerOneIsEnabled());
  cushion->handleEvent(SIT_DOWN);
  // hardware->dump();
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
  ASSERT("h/w should beep",hardware->isBeeping());
  cushion->handleEvent(TICK);
  ASSERT("timer one should not be enabled",!hardware->timerOneIsEnabled());
  ASSERT_EQUALS(false, hardware->isBeeping());
}

void test_waits_for_25_minutes_after_beeping() {
  cushion->handleEvent(SIT_DOWN);
  cushion->handleEvent(TICK);
  ASSERT("watchdog timer should be enabled",!hardware->wdtIsEnabled());
  ASSERT("sleep mode should be enabled",!hardware->sleepIsEnabled());
}

void setup() {
  Serial.begin(9600);
  cushion = new Cushion(hardware);
  RUN(test_beeps_for_one_sec_after_sitting_down);
  TEST_REPORT();
  Serial.println();
}

void loop() {
}
