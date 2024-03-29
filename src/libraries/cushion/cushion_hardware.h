#ifndef cushion_hardware_h_
#define cushion_hardware_h_

#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
#include "Arduino.h"

const int SCALE256 = 1 << CS12; // prescale / 256
const int SCALE1024 = 5 << CS10; // prescale / 1024

const int WAIT_25_MINS = 187;
const int WAIT_5_MINS = 37;


class CushionHardware {
  public:
    virtual void ledOn();
    virtual void ledOff();
    virtual void configureTimer1(unsigned int scale);
    virtual void enableTimer1();
    virtual void disableTimer1();
    virtual void loadTimer1(unsigned int count);
    virtual void enableWDTimer();
    virtual void disableWDTimer();
    virtual void sleep();
    virtual void startVibrating();
    virtual void stopVibrating();
};

class ArduinoHardware: public CushionHardware {
  public:
    ArduinoHardware();
    virtual void ledOn();
    virtual void ledOff();
    virtual void configureTimer1(unsigned int scale);
    virtual void enableTimer1();
    virtual void disableTimer1();
    virtual void loadTimer1(unsigned int count);
    virtual void enableWDTimer();
    virtual void disableWDTimer();
    virtual void sleep();
    virtual void startVibrating();
    virtual void stopVibrating();
  private:
    const int LED = 13;
    const int VIBRATOR = 11;
};

#endif
