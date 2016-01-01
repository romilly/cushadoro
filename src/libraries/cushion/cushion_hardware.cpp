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

// Set timer1_counter to the correct value for our interrupt interval
  //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  //timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz

void ArduinoHardware::loadTimer1(unsigned int count) {
  TCNT1 = count;
}

void ArduinoHardware::sleep()
{
  // Set sleep to full power down.  Only external interrupts or
  // the watchdog timer can wake the CPU!
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  power_adc_disable();
  sleep_mode();

  // CPU is now asleep and program execution completely halts!
  // Once awake, execution will resume at this point.

  sleep_disable();
  power_all_enable();
}

void ArduinoHardware::enableWDTimer(){
  noInterrupts();
  // Set the watchdog reset bit in the MCU status register to 0.
  MCUSR &= ~(1<<WDRF);
  // Set WDCE and WDE bits in the watchdog control register.
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  // TODO: find out how to set the timer for different intervals
  // Set watchdog clock prescaler bits to a value of 8 seconds.
  WDTCSR = (1<<WDP0) | (1<<WDP3);
  // Enable watchdog as interrupt only (no reset).
  WDTCSR |= (1<<WDIE);
  interrupts();
}

void ArduinoHardware::disableWDTimer() {
  noInterrupts();
  wdt_reset();
  /* Clear WDRF in MCUSR */
  MCUSR &= ~(1<<WDRF);
  /* Write logical one to WDCE and WDE */
  /* Keep old prescaler setting to prevent unintentional time-out */
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  /* Turn off WDT */
  WDTCSR = 0x00;
  interrupts();
}


void ArduinoHardware::toggleLed() {
  CushionHardware::toggleLed();
  digitalWrite(LED, ledState);
}
