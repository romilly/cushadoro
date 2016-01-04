#include <cushion.h>
#include <examples/CushionTest/mock.h>
#include <cushion_hardware.h>
#include <events.h>
#include <tinyarduinotest.h>
#include <Arduino.h>

Cushion* cushion;
MockHardware *hardware= new MockHardware;

void test_beeps_for_one_sec_after_sitting_down() {
  cushion->initial();
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  cushion->handleEvent(SIT_DOWN);
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
  ASSERT("led should be on",hardware->ledIsOn());
  cushion->handleEvent(TICK);
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void test_waits_for_25_minutes_after_beeping() {
  cushion->initial();
  cushion->handleEvent(SIT_DOWN);
  cushion->handleEvent(TICK);
  ASSERT("watchdog timer should be enabled",hardware->wdTimerIsEnabled());
  ASSERT("sleep mode should be enabled",hardware->isAsleep());
  for (int i=0; i < WAIT_25_MINS; i++) {
    cushion->handleEvent(WDT);
    ASSERT("watchdog timer should be enabled",hardware->wdTimerIsEnabled());
  }
  cushion->handleEvent(WDT);
  ASSERT("watchdog timer should be disabled",hardware->wdTimerIsDisabled());
  ASSERT("should be vibrating",hardware->isVibrating());
}

void test_stand_up_during_buzzing_returns_to_initial_state() {
  cushion->initial();
  cushion->handleEvent(SIT_DOWN);
  cushion->handleEvent(GET_UP);
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void test_stand_up_when_stitting_reverts_to_initial_state() {
  cushion->initial();
  cushion->handleEvent(SIT_DOWN);
  cushion->handleEvent(TICK);
  cushion->handleEvent(GET_UP);
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void test_vibrates_for_one_second() {
  cushion->initial();
  cushion->handleEvent(SIT_DOWN);
  cushion->handleEvent(TICK);
  for (int i=0; i <= WAIT_25_MINS; i++) {
    cushion->handleEvent(WDT);
  }
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
  ASSERT("should be vibrating",hardware->isVibrating());
  cushion->handleEvent(TICK);
  ASSERT("should not be vibrating",hardware->isNotVibrating());
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());  
}


void setup() {
  Serial.begin(9600);
  cushion = new Cushion(hardware);
  RUN(test_beeps_for_one_sec_after_sitting_down);
  RUN(test_waits_for_25_minutes_after_beeping);
  RUN(test_stand_up_during_buzzing_returns_to_initial_state);
  RUN(test_stand_up_when_stitting_reverts_to_initial_state);
  RUN(test_vibrates_for_one_second);
  TEST_REPORT();
  Serial.println();
}

void loop() {
}
