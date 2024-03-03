#ifndef __SOLENOID_H__
#define __SOLENOID_H__

#include "WindsOfChange.h"

/**
 * Possible positions of the solenoid plunger
 */
enum SolenoidState { kRetracted = 0, kExtended };

class Solenoid {
 public:
  Solenoid(int pin);
  ~Solenoid();

  /**
   * @brief Set the duty cycle to extend the solenoid
   * @param duty_cycle The new duty cycle
   */
  void setDutyCycle(int duty_cycle);

  /**
   * @brief Extend the solenoid's plunger
   * @note If the plunger is already extended, this method will have no effect
   */
  void extend();

  /**
   * @brief Retract the solenoid's plunger
   * @note If the plunger is already retracted, this method will have no effect
   */
  void retract();

  /**
   * @brief Determine if the solenoid is extended or retracted
   * @returns True if extended; false if retracted
   */
  bool getSolenoidStatus();

 private:
  int pin_;
  // Default 50% duty cycle
  int duty_cycle_ = 128;
  SolenoidState plunger_state_ = kRetracted;
};

#endif
