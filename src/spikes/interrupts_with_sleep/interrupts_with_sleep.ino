#include <avr/sleep.h>
#include <avr/power.h>

const byte LED = 13;
const byte BUTTON = 2;

// Interrupt Service Routine (ISR)
void switchPressed ()
{
  if (digitalRead (BUTTON) == HIGH)
    digitalWrite (LED, HIGH);
  else
    digitalWrite (LED, LOW);
}  // end of switchPressed

void setup ()
{
  pinMode (LED, OUTPUT);  // so we can update the LED
  pinMode (BUTTON, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt(BUTTON), switchPressed, CHANGE);  // attach interrupt handler
  sleep();
} 

void sleep()
{
  // Set sleep to full power down.  Only external interrupts or
  // the watchdog timer can wake the CPU!
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  power_adc_disable();
  sleep_mode();

  // CPU is now asleep and program execution completely halts!
  // Once awake, execution will resume at this point.

  sleep_disable();
  power_all_enable();
}

void loop ()
{
  // loop doing nothing 
} 

