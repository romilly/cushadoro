#include <cushion.h>
#include <examples/CushionTest/mock.h>
#include <cushion_hardware.h>
#include <events.h>
#include <tinyarduinotest.h>
#include <Arduino.h>

Cushion* cushion;
MockHardware *hardware= new MockHardware;

void test_beeps_for_one_sec_after_sitting_down() {
  cushion = new Cushion(hardware);
  ASSERT("should be sleeping",hardware->isSleeping());
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  cushion->handleEvent(SIT_DOWN);
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
  ASSERT("led should be on",hardware->ledIsOn());
  cushion->handleEvent(TICK);
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void test_waits_for_25_minutes_when_sitting() {
  cushion = new Cushion(hardware);
  cushion->handleEvent(SIT_DOWN);
  cushion->handleEvent(TICK);
  ASSERT("watchdog timer should be enabled",hardware->wdTimerIsEnabled());
  ASSERT("sleep mode should be enabled",hardware->isSleeping());
  for (int i=0; i < WAIT_25_MINS; i++) {
    cushion->handleEvent(WDT);
    ASSERT("watchdog timer should be enabled",hardware->wdTimerIsEnabled());
  }
  cushion->handleEvent(WDT);
  ASSERT("watchdog timer should be disabled",hardware->wdTimerIsDisabled());
  ASSERT("should be vibrating",hardware->isVibrating());
}

void test_get_up_when_buzzing() {
  cushion = new Cushion(hardware);
  cushion->buzzing();
  cushion->handleEvent(GET_UP);
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void test_get_up_when_stitting() {
  cushion = new Cushion(hardware);
  cushion->handleEvent(GET_UP);
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void test_vibrates_for_one_second_then_sleeps() {
  cushion = new Cushion(hardware);
  cushion->vibrating();
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
  ASSERT("should be vibrating",hardware->isVibrating());
  cushion->handleEvent(TICK);
  ASSERT("should not be vibrating",hardware->isNotVibrating());
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  ASSERT("should be sleeping",hardware->isSleeping());
}

void test_get_up_when_vibrating() {
  cushion = new Cushion(hardware);
  cushion->vibrating();
  cushion->handleEvent(GET_UP);
  ASSERT("should not be vibrating",hardware->isNotVibrating());
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  ASSERT("should be sleeping",hardware->isSleeping());
}


void test_get_up_when_waiting_to_stand() {
  cushion = new Cushion(hardware);
  cushion->waitingToStand();
  ASSERT("watchdog timer should be disabled",hardware->wdTimerIsDisabled());
  cushion->handleEvent(GET_UP);
  ASSERT("watchdog timer should be enabled",hardware->wdTimerIsEnabled());
  ASSERT("sleep mode should be enabled",hardware->isSleeping());
}

void test_waits_for_5_minutes_when_standing() {
  cushion = new Cushion(hardware);
  cushion->standing();
  ASSERT("sleep mode should be enabled",hardware->isSleeping());
  for (int i=0; i < WAIT_5_MINS; i++) {
    cushion->handleEvent(WDT);
    ASSERT("watchdog timer should be enabled",hardware->wdTimerIsEnabled());
  }
  cushion->handleEvent(WDT);
  ASSERT("watchdog timer should be disabled",hardware->wdTimerIsDisabled());
  ASSERT("led should be on",hardware->ledIsOn());
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
}

void setup() {
  Serial.begin(9600);
  RUN(test_beeps_for_one_sec_after_sitting_down);
  RUN(test_waits_for_25_minutes_when_sitting);
  RUN(test_get_up_when_buzzing);
  RUN(test_get_up_when_stitting);
  RUN(test_vibrates_for_one_second_then_sleeps);
  RUN(test_get_up_when_vibrating);
  RUN(test_get_up_when_waiting_to_stand);
  RUN(test_waits_for_5_minutes_when_standing);
  TEST_REPORT();
  Serial.println();
}

void loop() {
}
