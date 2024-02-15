#include "anemometer.h"

Anemometer::Anemometer(int pin) : pin_(pin) {}

// Source: https://forum.arduino.cc/t/reading-a-pwm-signal/603967/5
// TODOLater - Confirm this works
// TODOLater - Change timeouts in pulseIn() to reflect desired PWM signal
int Anemometer::read() {
  unsigned long highTime =
      pulseIn(pin_, HIGH, 50000UL);  // 50 millisecond timeout
  unsigned long lowTime =
      pulseIn(pin_, LOW, 50000UL);  // 50 millisecond timeout

  // pulseIn() returns zero on timeout
  if (highTime == 0 || lowTime == 0)
    return digitalRead(pin_) ? 100 : 0;  // HIGH == 100%,  LOW = 0%

  return (100 * highTime) /
         (highTime + lowTime);  // highTime as percentage of total cycle time
}
