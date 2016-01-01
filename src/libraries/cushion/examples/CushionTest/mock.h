class MockHardware: public CushionHardware {
  public:
    virtual void configureTimer1(unsigned int scale) { timerOneScale = scale;}
    virtual void enableTimer1() { timerOneEnabled = true;}
    virtual void disableTimer1() { timerOneEnabled = false;}
    virtual void loadTimer1(unsigned int count) { timerOneCount = count;}
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
    void dump() {
      Serial.print(timerOneEnabled); Serial.print(timerOneScale); Serial.println(timerOneCount);
    }
  private:
    boolean timerOneEnabled = false;
    unsigned int timerOneScale = 0;
    unsigned int timerOneCount = 0;
};

