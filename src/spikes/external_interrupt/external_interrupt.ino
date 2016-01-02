// adapted from https://www.arduino.cc/en/Reference/AttachInterrupt
int outpin = 13;
int inpin = 2;
volatile int state = LOW;

void setup() {
    pinMode(outpin, OUTPUT);
    pinMode(inpin, INPUT);
    attachInterrupt(digitalPinToInterrupt(inpin), blink, CHANGE);
}

void loop() {
    digitalWrite(outpin, state);
}

void blink() {
    state = !state;
}
