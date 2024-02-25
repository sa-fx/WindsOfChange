#ifndef __SOLENOID_H__
#define __SOLENOID_H__

/**
 * Possible positions of the solenoid plunger
 */
enum SolenoidState { kRetracted = 0, kExtended };

class Solenoid {
 public:
  Solenoid(int pin);
  ~Solenoid();

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

 private:
  int pin_;
  SolenoidState plunger_state_;
};

#endif
