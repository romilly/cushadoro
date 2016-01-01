#include <avr/wdt.h>
#include <cushion_hardware.h>
#include <events.h>
#include <Arduino.h>

ArduinoHardware * hardware = new ArduinoHardware();
volatile int wdtCount = 0;
int timerCount = 0;
ISR(WDT_vect) {
  hardware->disableWDTimer();
  wdtCount++;
}

void setup() {
  hardware->enableWDTimer();
  Serial.begin(9600);
  hardware->sleep();
}

void loop() {
  delay(1000);
  Serial.print("count = ");
  Serial.print(timerCount++);
  Serial.print(" wdt count =");
  Serial.println(wdtCount);
}


  
