#ifndef __POWER_METER_H__
#define __POWER_METER_H__

#include <ModbusMaster.h>
// TODOLater - Implement PowerMeter
class PowerMeter {
 public:
  PowerMeter(uint8_t device_address = 0x01, int pin_de, int pin_re);
  ~PowerMeter();
  uint32_t getVoltage();
  uint32_t getCurrent();
  uint32_t getPower();
  uint32_t getEnergy();
  uint32_t getFrequency();
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
  uint8_t device_address_ int pin_de_;
  int pin_re_;
}
#endif
