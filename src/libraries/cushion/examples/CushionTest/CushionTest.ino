#include <cushion.h>
#include <cushion_hardware.h>
#include <events.h>
#include <tinyarduinotest.h>
#include "Arduino.h"

const int MAX_CAPACITY = 4;
EventBuffer eb = EventBuffer(MAX_CAPACITY);

class MockHardware: public CushionHardware {
  public:
    virtual void toggleLed() { if (beeping) beeping = false; else beeping = true;}
    virtual void configureTimer1(unsigned int scale) { timerOneScale = scale;}
    virtual void enableTimer1() { timerOneEnabled = true;}
    virtual void disableTimer1() { timerOneEnabled = false;}
    virtual void loadTimer1(unsigned int count) { timerOneCount = count;}
    // methods for tests
    boolean timerOneIsEnabled() {
      return timerOneEnabled;
    }
    boolean isBeeping() {
      return beeping;
    }
    boolean timerOneWillTickInOneSecond() {
      return timerOneEnabled && (timerOneScale == SCALE1024) && (timerOneCount == 49911);
    }
    void dump() {
      Serial.print(timerOneEnabled); Serial.print(timerOneScale); Serial.println(timerOneCount);
    }
  private:
    boolean timerOneEnabled = false;
    boolean beeping = false;
    unsigned int timerOneScale = 0;
    unsigned int timerOneCount = 0;
};

Cushion* cushion;

MockHardware *hardware= new MockHardware;

void test_beeps_for_one_sec_after_sitting_down() {
  ASSERT("timer one should not be enabled",!hardware->timerOneIsEnabled());
  cushion->handleEvent(SIT_DOWN);
  // hardware->dump();
  ASSERT("timer should tick in one sec",hardware->timerOneWillTickInOneSecond());
  ASSERT("h/w should beep",hardware->isBeeping());
  cushion->handleEvent(TICK);
  ASSERT("timer one should not be enabled",!hardware->timerOneIsEnabled());
  ASSERT_EQUALS(false, hardware->isBeeping());
}

void setup() {
  Serial.begin(9600);
  cushion = new Cushion(hardware);
  RUN(test_beeps_for_one_sec_after_sitting_down);
  TEST_REPORT();
  Serial.println();
}

void loop() {
}