#include "cushion_hardware.h"
#include "Arduino.h"


ArduinoHardware::ArduinoHardware() {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
}

void ArduinoHardware::configureTimer1(unsigned int scale) {
  noInterrupts();  
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= scale;   
  interrupts();   
}

void ArduinoHardware::enableTimer1() {
  noInterrupts();
  TIMSK1 |= (1 << TOIE1);
  interrupts();
}

void ArduinoHardware::disableTimer1() {
  noInterrupts();
  TIMSK1 ^= (1 << TOIE1);
  interrupts();
}

void ArduinoHardware::loadTimer1(unsigned int count) {
  // Set timer1_counter to the correct value for our interrupt interval
  //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  //timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz
  TCNT1 = count;
}

// TODO: change to toggleBeep
void ArduinoHardware::toggleLed() {
  if (ledState == LOW) {
    ledState = HIGH;
  }
  else {
    ledState = LOW;
  }
  digitalWrite(LED, ledState);
}
