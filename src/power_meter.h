#ifndef __POWER_METER_H__
#define __POWER_METER_H__

#include <ModbusMaster.h>

// Implemented for use with PZEM-014

class PowerMeter {
 public:
  PowerMeter(uint8_t device_address, int pin_de, int pin_re);
  ~PowerMeter();

  // TODOLater - Determine if calibration function is required
  // TODOLater - Determine if reset energy function is required

  /**
   * @returns Voltage value in Volts between 80V and 260V
   */
  uint32_t getVoltage();

  /**
   * @returns Current value in Amps between 0 and 10A
   */
  uint32_t getCurrent();

  /**
   * @returns Active power value in Watts
   */
  uint32_t getPower();

  /**
   * @returns Active energy value in Watt-hours
   */
  uint32_t getEnergy();

  /**
   * @returns Frequency value in Hertz between 45Hz and 65Hz
   */
  uint32_t getFrequency();

  /**
   * @returns Power factor value between 0 and 1
   */
  uint32_t getPowerFactor();

  /**
   * @returns 0x0000 for no alarm;
   * 0xFFFF for alarm;
   * 0x0001 for error
   */
  uint32_t getAlarmStatus();

 private:
  void preTransmission();
  void postTransmission();

 private:
  const uint8_t kRegisterVoltage = 0x0000;
  const uint8_t kRegisterCurrentLo = 0x0001;
  const uint8_t kRegisterCurrentHi = 0x0002;
  const uint8_t kRegisterPowerLo = 0x0003;
  const uint8_t kRegisterPowerHi = 0x0004;
  const uint8_t kRegisterEnergyLo = 0x0005;
  const uint8_t kRegisterEnergyHi = 0x0006;
  const uint8_t kRegisterFrequency = 0x0007;
  const uint8_t kRegisterPowerFactor = 0x0008;
  const uint8_t kRegisterAlarmStatus = 0x0009;

  ModbusMaster node_;
  uint8_t device_address_;
  int pin_de_;
  int pin_re_;
};
#endif
