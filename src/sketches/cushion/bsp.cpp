#include "bsp.h"
#include "Arduino.h"


BSP::BSP() {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
}

void BSP::configureTimer1(int count) {
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  // Set timer1_counter to the correct value for our interrupt interval
  //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  //timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz
  loadTimer1(count);  // preload timer
  // TCCR1B |= (1 << CS12);    // 256 prescaler 
  TCCR1B |= (5 << CS10);     // 1024 prescaler
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();   
}

void BSP::loadTimer1(int count) {
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
