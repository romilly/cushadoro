#include <cushion.h>
#include <examples/CushionTest/mock.h>
#include <cushion_hardware.h>
#include <events.h>
#include <tinyarduinotest.h>
#include <Arduino.h>

State* state;
MockHardware *hardware= new MockHardware;

void test_initial_state() {
  state = new Initial(hardware);
  hardware->checkAwake();
  hardware->checkT1disabled();
  hardware->checkLedOff();
  hardware->checkWDToff();
  state->enter();
  hardware->checkSleeping();
}

void setup() {
  Serial.begin(9600);
  RUN(test_initial_state);
  TEST_REPORT();
  Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:

}
