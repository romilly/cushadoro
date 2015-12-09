/*

 
 http://arduino.cc/en/Tutorial/AnalogInput
 
  additional code from 
  https://learn.adafruit.com/adafruit-trinket-modded-stuffed-animal/animal-sounds
*/

// updated for trinket

int sensorPin = 2;    // select the input pin 
int ledPin = 1;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
const int SPEAKER = 0;
const int THRESHOLD = 500;
enum state { waiting_for_start, sitting, time_to_get_up, break_time, time_to_sit_down };
state current_state = waiting_for_start;
int time = 0;
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(SPEAKER,OUTPUT);  
}

void loop() {
  switch(current_state) {
    case waiting_for_start:
      if (someone_is_sitting) {
        state = sitting;
        digitalWrite(ledPin, HIGH);
        arf();
        time = 0;
      }
      break;
    case sitting:
      if (someone_is_sitting) {
        time += 1;
        if (time > SITTING_TIME) {
          state = time_to_get_up;
          time = 0;
        };
        else {
          state = waiting_for_start;
        }
      } 
      break;
     case
  
  // turn the ledPin on
  if (someone_is_sitting) {
    digitalWrite(ledPin, HIGH);
    arf();       
  }
  else {
    // turn the ledPin off:        
    digitalWrite(ledPin, LOW); 
  }        
  delay(1000);                  
}

boolean someone_is_sitting() {
  return analogRead(A1) >= THRESHOLD;
}

void arf() {    // dog arf
  uint16_t i;
  playTone(890,25);          // "a"    (short)
  for(i=890; i<910; i+=2)    // "rrr"  (vary down)
     playTone(i,5);
  playTone(4545,80);         // intermediate
  playTone(12200,70);        // "ff"   (shorter, hard to do)
}

void playTone(uint16_t tone1, uint16_t duration) {
  if(tone1 < 50 || tone1 > 15000) return;  // these do not play on a piezo
  for (long i = 0; i < duration * 1000L; i += tone1 * 2) {
     digitalWrite(SPEAKER, HIGH);
     delayMicroseconds(tone1);
     digitalWrite(SPEAKER, LOW);
     delayMicroseconds(tone1);
  }     
}
