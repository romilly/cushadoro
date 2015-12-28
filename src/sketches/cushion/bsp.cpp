#include "bsp.h"
#include "Arduino.h"


BSP::BSP() {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
}

void BSP::configureTimer1(int scale) {
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= scale;   
  interrupts();   
}

void BSP::enableTimer1() {
  noInterrupts();
  TIMSK1 |= (1 << TOIE1);
  interrupts();
}

void BSP::loadTimer1(int count) {
  // Set timer1_counter to the correct value for our interrupt interval
  //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  //timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz
  TCNT1 = count;
}

void BSP::toggleLed() {
  if (ledState == LOW) {
    ledState = HIGH;
  }
  else {
    ledState = LOW;
  }
  digitalWrite(LED, ledState);
}
