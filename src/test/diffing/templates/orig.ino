#include "qp_port.h"
#include "Arduino.h"  // always include in your sketch

Q_DEFINE_THIS_FILE

using namespace QP;

#define BSP_TICKS_PER_SEC 100

enum BlinkySignals { // signals for the Blinky application
    TIMEOUT_SIG = Q_USER_SIG
};

//............................................................................
void BSP_init(void) {
    DDRB  = 0xFF; // All PORTB pins are outputs (user LED)
    PORTB = 0x00; // drive all pins low
}
//............................................................................
void BSP_ledOff(void) {
    PORTB &= ~(1 << 5);
}
//............................................................................
void BSP_ledOn(void) {
    PORTB |= (1 << 5);
}
//............................................................................
ISR(TIMER2_COMPA_vect) {
    QF::TICK((void *)0); // process all armed time events
}
//............................................................................
void QF::onStartup(void) {
    // set Timer2 in CTC mode, 1/1024 prescaler, start the timer ticking
    TCCR2A = (1 << WGM21) | (0 << WGM20);
    TCCR2B = (1 << CS22 ) | (1 << CS21) | (1 << CS20); // 1/2^10
    ASSR  &= ~(1 << AS2);
    TIMSK2 = (1 << OCIE2A); // Enable TIMER2 compare Interrupt
    TCNT2  = 0;
    OCR2A  = (F_CPU / BSP_TICKS_PER_SEC / 1024) - 1;
}
//............................................................................
void QF::onCleanup(void) {
}
//............................................................................
void QF::onIdle() {
    QF_INT_ENABLE(); // re-enable interrupts
}
//............................................................................
void Q_onAssert(char const Q_ROM * const file, int line) {
    QF_INT_DISABLE(); // disable all interrupts
    BSP_ledOn(); // User LED permanently ON
    asm volatile ("jmp 0x0000"); // perform a software reset of the Arduino
}

//============================================================================
// generate code for the Blinky application...
$declare(AOs::Blinky)
$define(AOs::Blinky)

//............................................................................
static Blinky l_blinky;                           // instantiate the Blinky AO
QActive *AO_Blinky = &l_blinky;     // initialize the global pointer to Blinky

//............................................................................
void setup() {
    BSP_init(); // initialize the BSP
    QF::init(); // initialize the framework and the underlying RT kernel

    static QEvt const *blinky_queueSto[10]; // alocate event queue buffer
    AO_Blinky->start(1, blinky_queueSto, Q_DIM(blinky_queueSto),
                     (void *)0, 0U);        // start the Blinky active object
}

//////////////////////////////////////////////////////////////////////////////
// NOTE1: Do not define the loop() function, because this function is
// already defined in the QP port to Arduino