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
  solenoid.extend();
  delay(2000);
  solenoid.retract();
  delay(2000);
}