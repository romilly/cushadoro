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
  TCNT1 = count;
}

void ArduinoHardware::sleep() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  power_adc_disable();
  sleep_mode();
  sleep_disable();
  power_all_enable();
}

void ArduinoHardware::enableWDTimer() {
  noInterrupts();
  MCUSR &= ~(1<<WDRF);
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  WDTCSR = (1<<WDP0) | (1<<WDP3); // 8 sec
  WDTCSR |= (1<<WDIE);
  interrupts();
}

void ArduinoHardware::disableWDTimer() {
  noInterrupts();
  wdt_reset();
  MCUSR &= ~(1<<WDRF);
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  WDTCSR = 0x00;
  interrupts();
}

void ArduinoHardware::toggleLed() {
  CushionHardware::toggleLed();
  digitalWrite(LED, ledState);
}
