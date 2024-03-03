/**
 * solenoid.ino
 * Example implementing actuation of solenoid valve every 2 seconds
 * Author: S Alexander
 * Last Updated: 25/02/2024
 */

#include <WindsOfChange.h>

// Solenoid connected to pin 13
const int solenoid_pin = 13;

Solenoid solenoid(solenoid_pin);

void setup() {
  Serial.begin(9600);
  pinMode(solenoid_pin, OUTPUT);
}

void loop() {
  if (solenoid.getSolenoidStatus()) {
    solenoid.retract();
    Serial.println("Solenoid retracted");
  } else {
    solenoid.extend();
    Serial.println("Solenoid extended");
  }
  delay(2000);
}