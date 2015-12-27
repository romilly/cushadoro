// define BSP class
class BSP {
  public:
    BSP();
    void toggleLed();
    void setTimer(int count);
    int timer();
  private:
    const int LED = 13;
    int ledState = 0;
    int timerCounter;
};

