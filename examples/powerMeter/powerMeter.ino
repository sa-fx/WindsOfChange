/**
 * powerMeter.ino
 * Example implementing reading from the PZEM-014 energy meter
 * Author: S Alexander
 * Last Updated: 24/02/2024
 */

#include <WindsOfChange.h>

// Pin connections - Change as required
const int pin_de = 2;
const int pin_re = 3;

// Device Modbus address - Change as required
const int device_address = 0x01;

PowerMeter sensor(device_address, pin_de, pin_re);

void setup() {
  // TODOLater - Check this will work, if PowerMeter is using Serial already
  Serial.begin(9600);
}

void loop() {
  uint32_t voltage = sensor.getVoltage();
  Serial.print("Voltage: ");
  Serial.println(voltage);
  uint32_t current = sensor.getCurrent();
  Serial.print("Current: ");
  Serial.println(current);
  uint32_t power = sensor.getPower();
  Serial.print("Power: ");
  Serial.println(power);
  uint32_t energy = sensor.getEnergy();
  Serial.print("Energy: ");
  Serial.println(energy);
  uint32_t frequency = sensor.getFrequency();
  Serial.print("Frequency: ");
  Serial.println(frequency);
  uint32_t power_factor = sensor.getPowerFactor();
  Serial.print("Power Factor: ");
  Serial.println(power_factor);
  uint32_t alarm_status = sensor.getAlarmStatus();
  Serial.print("Alarm Status: ");
  Serial.println(alarm_status);
}