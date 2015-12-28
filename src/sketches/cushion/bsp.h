// define BSP class
class BSP {
  public:
    BSP();
    void toggleLed();
    void configureTimer1(int count);
    void loadTimer1(int count);
  private:
    const int LED = 13;
    int ledState = 0;
};

