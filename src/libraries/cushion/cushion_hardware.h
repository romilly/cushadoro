#ifndef cushion_hardware_h_
#define cushion_hardware_h_

#include "Arduino.h"

const int SCALE256 = 1 << CS12; // prescale / 256
const int SCALE1024 = 5 << CS10; // prescale / 1024


class CushionHardware {
  public:
    virtual void toggleLed();
    virtual void configureTimer1(unsigned int scale);
    virtual void enableTimer1();
    virtual void disableTimer1();
    virtual void loadTimer1(unsigned int count);
};

class ArduinoHardware: public CushionHardware {
  public:
    ArduinoHardware();
    virtual void toggleLed();
    virtual void configureTimer1(unsigned int scale);
    virtual void enableTimer1();
    virtual void disableTimer1();
    virtual void loadTimer1(unsigned int count);
  private:
    const int LED = 13;
    int ledState = 0;
};

#endif
