#include "bsp.h"
#include "Arduino.h"


BSP::BSP() {
    pinMode(LED, OUTPUT);
}

void BSP::blinkLed() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
