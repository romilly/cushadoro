#include <cushion.h>
#include <examples/CushionTest/mock.h>
#include <cushion_hardware.h>
#include <events.h>
#include <tinyarduinotest.h>
#include <Arduino.h>

Cushion* cushion;
MockHardware *hardware= new MockHardware;

const char* SHOULD_BE_SLEEPING = "should be sleeping";
const char* TIMER1DISABLED = "timer one should be disabled";

void test_beeps_for_one_sec_after_sitting_down() {
  ASSERT(SHOULD_BE_SLEEPING,hardware->isSleeping());
  ASSERT(TIMER1DISABLED,hardware->timerOneIsDisabled());
  cushion->handleEvent(SIT_DOWN);
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
  ASSERT("led should be on",hardware->ledIsOn());
  cushion->handleEvent(TICK);
  ASSERT(TIMER1DISABLED,hardware->timerOneIsDisabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void test_waits_for_25_minutes_when_sitting() {
  cushion->handleEvent(SIT_DOWN);
  cushion->handleEvent(TICK);
  ASSERT("watchdog timer should be enabled",hardware->wdTimerIsEnabled());
  ASSERT(SHOULD_BE_SLEEPING,hardware->isSleeping());
  for (int i=0; i < WAIT_25_MINS; i++) {
    cushion->handleEvent(WDT);
    ASSERT("watchdog timer should be enabled",hardware->wdTimerIsEnabled());
  }
  cushion->handleEvent(WDT);
  ASSERT("watchdog timer should be disabled",hardware->wdTimerIsDisabled());
  ASSERT("should be vibrating",hardware->isVibrating());
}

void test_get_up_when_buzzing() {
  cushion->buzzing();
  cushion->handleEvent(GET_UP);
  ASSERT(TIMER1DISABLED,hardware->timerOneIsDisabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void test_get_up_when_stitting() {
  cushion->handleEvent(GET_UP);
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  ASSERT("led should be off",hardware->ledIsOff());
}

void test_vibrates_for_one_second_then_sleeps() {
  cushion->vibrating();
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
  ASSERT("should be vibrating",hardware->isVibrating());
  cushion->handleEvent(TICK);
  ASSERT("should not be vibrating",hardware->isNotVibrating());
  ASSERT(TIMER1DISABLED,hardware->timerOneIsDisabled());
  ASSERT(SHOULD_BE_SLEEPING,hardware->isSleeping());
}

void test_get_up_when_vibrating() {
  cushion->vibrating();
  cushion->handleEvent(GET_UP);
  ASSERT("should not be vibrating",hardware->isNotVibrating());
  ASSERT("timer one should be disabled",hardware->timerOneIsDisabled());
  ASSERT(SHOULD_BE_SLEEPING,hardware->isSleeping());
}


void test_get_up_when_waiting_to_stand() {
  cushion->waitingToStand();
  ASSERT("watchdog timer should be disabled",hardware->wdTimerIsDisabled());
  cushion->handleEvent(GET_UP);
  ASSERT("watchdog timer should be enabled",hardware->wdTimerIsEnabled());
  ASSERT("sleep mode should be enabled",hardware->isSleeping());
}

void test_waits_for_5_minutes_when_standing() {
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

void test_flashes_for_one_second_then_waits_to_sit_down() {
  cushion->flashing();
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
  ASSERT("led should be on",hardware->ledIsOn());
  cushion->handleEvent(TICK);
  ASSERT("led should be off",hardware->ledIsOff());
  ASSERT("timer one should not be enabled",hardware->timerOneIsDisabled());
  ASSERT("should be sleeping",hardware->isSleeping());
}

void setup() {
  Serial.begin(9600);
  cushion = new Cushion(hardware);
  RUN(test_beeps_for_one_sec_after_sitting_down);
  RUN(test_waits_for_25_minutes_when_sitting);
  RUN(test_get_up_when_buzzing);
  RUN(test_get_up_when_stitting);
  RUN(test_vibrates_for_one_second_then_sleeps);
  RUN(test_get_up_when_vibrating);
  RUN(test_get_up_when_waiting_to_stand);
  RUN(test_waits_for_5_minutes_when_standing);
  RUN(test_flashes_for_one_second_then_waits_to_sit_down);
  TEST_REPORT();
  Serial.println();
}

void loop() {
}
