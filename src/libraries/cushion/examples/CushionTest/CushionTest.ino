#include <cushion.h>
#include <examples/CushionTest/mock.h>
#include <cushion_hardware.h>
#include <events.h>
#include <tinyarduinotest.h>
#include <Arduino.h>

Cushion* cushion;
MockHardware *hardware= new MockHardware;

void test_beeps_for_one_sec_after_sitting_down() {
  checkSleeping();
  checkT1disabled();
  cushion->handleEvent(SIT_DOWN);
  checkTickIn1Sec();
  checkLedOn();
  cushion->handleEvent(TICK);
  checkT1disabled();
  checkLedOff();
}

void test_waits_for_25_minutes_when_sitting() {
  cushion->handleEvent(SIT_DOWN);
  cushion->handleEvent(TICK);
  checkWDTon();
  checkSleeping();
  for (int i=0; i < WAIT_25_MINS; i++) {
    cushion->handleEvent(WDT);
    checkWDTon();
  }
  cushion->handleEvent(WDT);
  checkWDToff();
  checkVibrating();
}

void test_get_up_when_buzzing() {
  cushion->buzzing();
  cushion->handleEvent(GET_UP);
  checkT1disabled();
  checkLedOff();
}

void test_get_up_when_stitting() {
  cushion->handleEvent(GET_UP);
  checkT1disabled();
  checkLedOff();
}

void test_vibrates_for_one_second_then_sleeps() {
  cushion->vibrating();
  checkTickIn1Sec();
  checkVibrating();
  cushion->handleEvent(TICK);
  checkNotVibrating();
  checkT1disabled();
  checkSleeping();
}

void test_get_up_when_vibrating() {
  cushion->vibrating();
  cushion->handleEvent(GET_UP);
  checkNotVibrating();
  checkT1disabled();;
  checkSleeping();
}

void test_get_up_when_waiting_to_stand() {
  cushion->waitingToStand();
  checkWDToff();
  cushion->handleEvent(GET_UP);
  checkWDTon();
  checkSleeping();
}

void test_waits_for_5_minutes_when_standing() {
  cushion->standing();
  checkSleeping();
  for (int i=0; i < WAIT_5_MINS; i++) {
    cushion->handleEvent(WDT);
    checkWDTon();;
  }
  cushion->handleEvent(WDT);
  checkWDToff();;
  checkLedOn();
  checkTickIn1Sec();
}

void test_flashes_for_one_second_then_waits_to_sit_down() {
  cushion->flashing();
  checkTickIn1Sec();
  checkLedOn();
  cushion->handleEvent(TICK);
  checkLedOff();
  checkT1disabled();
  checkSleeping();
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

// helpers

void checkSleeping() {
  ASSERT("should be sleeping",hardware->isSleeping());
}

void checkT1disabled() {
  ASSERT("timer one should be disabled",hardware->timerOneIsDisabled());
}

void checkTickIn1Sec() {
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
}

void checkLedOn() {
  ASSERT("led should be on",hardware->ledIsOn());
}

void checkLedOff() {
  ASSERT("led should be off",hardware->ledIsOff());
}

void checkWDTon() {
  ASSERT("watchdog timer should be enabled",hardware->wdTimerIsEnabled());
}

void checkWDToff() {
  ASSERT("watchdog timer should be disabled",hardware->wdTimerIsDisabled());
}

void checkVibrating() {
  ASSERT("should be vibrating",hardware->isVibrating());
}

void checkNotVibrating() {
  ASSERT("should not be vibrating",hardware->isNotVibrating());
}
