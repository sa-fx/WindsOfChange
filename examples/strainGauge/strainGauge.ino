/**
 * strainGauge.ino
 * Example implementing reading from a strain gauge
 * Author: S Alexander
 * Last Updated: 15/02/2024
 */

#include <WindsOfChange.h>

// Strain gauge connected to pin 13
const int strain_pin = 13;

StrainGauge sensor(strain_pin);

void setup() {
  Serial.begin(9600);
  pinMode(strain_pin, INPUT);
}

void loop() {
  int result = sensor.read();
  Serial.print("Current Strain: ");
  Serial.println(result);
  delay(500);
}