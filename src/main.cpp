// pio device monitor > sen0257calibration.csv
// With the esp32 the analogRead function operates with 1v is coded into 1024.
// So the coversion should be voltage.v =  analogRead(pin) / 1024.00.
#include <Arduino.h>
#include "my_sen0257.cpp"
#include "common.hpp"

#ifdef ESP32ENV
  MY_SEN0257 s1(35);
#else
  MY_SEN0257 s1(A0);
#endif


void setup()
{
  Serial.begin(9600);
  s1.calibration();
}

void loop()
{
  MY_PRINT("Pressure = %10.3f kPa\n", s1.getPressure());
  delay(2000);
}