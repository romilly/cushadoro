// define BSP class
class BSP {
  public:
    BSP();
    void toggleLed();
  private:
    const int LED = 13;
    int ledState = 0;
};

