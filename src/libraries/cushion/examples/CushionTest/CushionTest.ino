#include <cushion.h>
#include <examples/CushionTest/mock.h>
#include <cushion_hardware.h>
#include <events.h>
#include <tinyarduinotest.h>
#include <Arduino.h>

const int MAX_CAPACITY = 4;
EventBuffer eb = EventBuffer(MAX_CAPACITY);

Cushion* cushion;

MockHardware *hardware= new MockHardware;

void test_beeps_for_one_sec_after_sitting_down() {
  ASSERT("timer one should not be enabled",!hardware->timerOneIsEnabled());
  cushion->handleEvent(SIT_DOWN);
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
  ASSERT("led should be on",hardware->ledIsOn());
  cushion->handleEvent(TICK);
  ASSERT("timer one should not be enabled",!hardware->timerOneIsEnabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void test_waits_for_25_minutes_after_beeping() {
  cushion->handleEvent(SIT_DOWN);
  cushion->handleEvent(TICK);
  ASSERT("watchdog timer should be enabled",hardware->wdTimerIsEnabled());
  ASSERT("sleep mode should be enabled",hardware->isAsleep());
}

void test_stand_up_during_buzzing_returns_to_initial_state() {
  cushion->handleEvent(SIT_DOWN);
  cushion->handleEvent(GET_UP);
  ASSERT("timer one should not be enabled",!hardware->timerOneIsEnabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void test_stand_up_when_stitting_reverts_to_initial_state() {
  cushion->handleEvent(SIT_DOWN);
  cushion->handleEvent(TICK);
  cushion->handleEvent(GET_UP);
  ASSERT("timer one should not be enabled",!hardware->timerOneIsEnabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void setup() {
  Serial.begin(9600);
  cushion = new Cushion(hardware);
  RUN(test_beeps_for_one_sec_after_sitting_down);
  RUN(test_waits_for_25_minutes_after_beeping);
  RUN(test_stand_up_during_buzzing_returns_to_initial_state);
  RUN(test_stand_up_when_stitting_reverts_to_initial_state);
  TEST_REPORT();
  Serial.println();
}

void loop() {
}
