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
       
  private:
    boolean timerOneEnabled = false;
    boolean wdTimerEnabled = false;
    boolean sleeping = false;
    boolean ledState;
    boolean vibrating = false;
    unsigned int timerOneScale = 0;
    unsigned int timerOneCount = 0;
};

