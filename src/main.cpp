// pio device monitor > sen0257calibration.csv
// With the esp32 the analogRead function operates with 1v is coded into 1024.
// So the coversion should be voltage.v =  analogRead(pin) / 1024.00.
#include <Arduino.h>
#include "my_sen0257.cpp"

MY_SEN0257 s1(35);

void setup()
{
  Serial.begin(9600);
  s1.calibration();
  //sen0257calibration();
  // pinMode(pinPressureSensor, INPUT_PULLDOWN);
}

void loop()
{
  Serial.printf("Pressure = %10.3f kPa\n", s1.getPressure());
  delay(2000);
}