#include <cushion.h>
#include <examples/CushionTest/mock.h>
#include <cushion_hardware.h>
#include <events.h>
#include <tinyarduinotest.h>
#include <Arduino.h>

Cushion* cushion;
MockHardware *hardware= new MockHardware;

// check transitions from Initial on SitDown to Buzzing
void test_buzzing_after_sitting_down() {
  cushion->initial();
  hardware->checkSleeping();
  hardware->checkT1disabled();
  cushion->handleEvent(SIT_DOWN);
  hardware->checkTickIn1Sec();
  hardware->checkLedOn();
}
  
// check transitions from Buzzing on TimerTick to Sitting
//void test_sitting_after_one_second() {
//  cushion->buzzing();
//  cushion->handleEvent(TICK);
//  checkT1disabled();
//  checkLedOff();
//  checkWDTon();
//  checkSleeping();
//}

// check transition from Sitting to Vibrating after 25 mins worth of WDT ticks
//void test_waits_for_25_minutes_when_sitting() {
//  cushion->sitting();
//  for (int i=0; i < WAIT_25_MINS; i++) {
//    cushion->handleEvent(WDT);
//    checkWDTon();
//    checkSleeping();
//  }
//  cushion->handleEvent(WDT);
//  checkWDToff();
//  checkVibrating();
//}

void test_get_up_when_buzzing() {
  cushion->buzzing();
  cushion->handleEvent(GET_UP);
  ASSERT("should be initial state", cushion->is_initial());
  hardware->checkT1disabled();
  hardware->checkLedOff();
}

//void test_get_up_when_stitting() {
//  cushion->sitting();
//  cushion->handleEvent(GET_UP);
//  hadware->checkT1disabled();
//  hardware->checkLedOff();
//}

//void test_vibrates_for_one_second_then_sleeps() {
//  cushion->vibrating();
//  checkTickIn1Sec();
//  checkVibrating();
//  cushion->handleEvent(TICK);
//  checkNotVibrating();
//  checkT1disabled();
//  checkSleeping();
//}

//void test_get_up_when_vibrating() {
//  cushion->vibrating();
//  cushion->handleEvent(GET_UP);
//  //checkInitalState();
//  checkNotVibrating();
//  checkT1disabled();
//  checkSleeping();
//}

//void test_get_up_when_waiting_to_stand() {
//  cushion->waitingToStand();
//  checkWDToff();
//  cushion->handleEvent(GET_UP);
//  checkWDTon();
//  checkSleeping();
//}

//void test_waits_for_5_minutes_when_standing() {
//  cushion->standing();
//  checkSleeping();
//  for (int i=0; i < WAIT_5_MINS; i++) {
//    cushion->handleEvent(WDT);
//    checkWDTon();;
//  }
//  cushion->handleEvent(WDT);
//  checkWDToff();;
//  checkLedOn();
//  checkTickIn1Sec();
//}

//void test_flashes_for_one_second_then_waits_to_sit_down() {
//  cushion->flashing();
//  checkTickIn1Sec();
//  checkLedOn();
//  cushion->handleEvent(TICK);
//  checkLedOff();
//  checkT1disabled();
//  checkSleeping();
//}

void setup() {
  Serial.begin(9600);
  cushion = new Cushion(hardware);
  RUN(test_buzzing_after_sitting_down);
//  RUN(test_sitting_after_one_second);
//  RUN(test_waits_for_25_minutes_when_sitting);
  RUN(test_get_up_when_buzzing);
//  RUN(test_get_up_when_stitting);
//  RUN(test_vibrates_for_one_second_then_sleeps);
//  RUN(test_get_up_when_vibrating);
//  RUN(test_get_up_when_waiting_to_stand);
//  RUN(test_waits_for_5_minutes_when_standing);
//  RUN(test_flashes_for_one_second_then_waits_to_sit_down);
  TEST_REPORT();
  Serial.println();
}

void loop() {
}

