#include <tinyarduinotest.h>

class MockHardware: public CushionHardware {
  public:
    virtual void configureTimer1(unsigned int scale) { timerOneScale = scale;}
    virtual void enableTimer1() { timerOneEnabled = true;}
    virtual void disableTimer1() { timerOneEnabled = false;}
    virtual void enableWDTimer() { wdTimerEnabled = true;}
    virtual void disableWDTimer() { wdTimerEnabled = false;}
    virtual void sleep() { sleeping = true; }
    virtual void loadTimer1(unsigned int count) { timerOneCount = count;}
    virtual void ledOn() { ledState = HIGH; }
    virtual void ledOff() { ledState = LOW; }
    virtual void startVibrating() {vibrating = true;}
    virtual void stopVibrating() {vibrating = false;}
    // methods for tests
    boolean timerOneIsEnabled() {
      return timerOneEnabled;
    }
    boolean ledIsOn() {
      return ledState == HIGH;
    }
    boolean ledIsOff() {
      return ledState == LOW;
    }
    boolean timerOneWillTickInOneSecond() {
      return timerOneEnabled && (timerOneScale == SCALE1024) && (timerOneCount == 49911);
    }
    boolean timerOneIsDisabled() {
      return timerOneEnabled == false;
    }
    
    boolean wdTimerIsEnabled() {
      return wdTimerEnabled;
    }
    boolean wdTimerIsDisabled() {
      return !wdTimerEnabled;
    }
    boolean isSleeping() {
      return sleeping;
    }
    boolean isVibrating() {
      return vibrating;
    }
    boolean isNotVibrating() {
      return !vibrating;
    }

    void checkSleeping() {
        ASSERT("should be sleeping",isSleeping());
    }

    void checkAwake() {
      ASSERT("should be not sleeping",!isSleeping());
    }

void checkT1disabled() {
  ASSERT("timer one should be disabled",timerOneIsDisabled());
}

void checkTickIn1Sec() {
  ASSERT("timer should tick in one sec",timerOneWillTickInOneSecond());
}

void checkLedOn() {
  ASSERT("led should be on",ledIsOn());
}

void checkLedOff() {
  ASSERT("led should be off",ledIsOff());
}

void checkWDTon() {
  ASSERT("watchdog timer should be enabled",wdTimerIsEnabled());
}

void checkWDToff() {
  ASSERT("watchdog timer should be disabled",wdTimerIsDisabled());
}

void checkVibrating() {
  ASSERT("should be vibrating",isVibrating());
}

void checkNotVibrating() {
  ASSERT("should not be vibrating",isNotVibrating());
}
       
  private:
    boolean timerOneEnabled = false;
    boolean wdTimerEnabled = false;
    boolean sleeping = false;
    boolean ledState;
    boolean vibrating = false;
    unsigned int timerOneScale = 0;
    unsigned int timerOneCount = 0;
};

