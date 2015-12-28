#ifndef bsp_h_
#define bsp_h_

#include "Arduino.h"

const int SCALE256 = 1 << CS12; // prescale / 256
const int SCALE1024 = 5 << CS10; // prescale / 1024
// define BSP class
class BSP {
  public:
    BSP();
    void toggleLed();
    void configureTimer1(int scale);
    void enableTimer1();
    void disableTimer1();
    void loadTimer1(int count);
  private:
    const int LED = 13;
    int ledState = 0;
};

#endif
