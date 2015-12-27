#include "bsp.h"
#include "Arduino.h"


BSP::BSP() {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
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
