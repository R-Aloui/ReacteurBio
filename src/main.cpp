#include <Arduino.h>
#include "my_sen0257.cpp"
#include "common.hpp"

MY_SEN0257 sensors[] = {MY_SEN0257(A0), MY_SEN0257(A1), MY_SEN0257(A2), MY_SEN0257(A3)};
// These values have been taken from the calibration results of each sensor.
float offesets[] = {0.459, 0.479, 0.469, 0.459};
int nbLect = 0;

void setup(){
  Serial.begin(57600);
  MY_PRINT("Starting calibration ...\n");
  // Calibration according to previous experiments
  for (size_t i = 0; i < 4; i++)
  {
    sensors[i].setOffeset(offesets[i]);
  }
  MY_PRINT("Starting readings ...\n");
  MY_PRINT("nb,\tp0,\tp1,\tp2,\tp3,\tdp0,\tdp1\n");
}

void loop(){
  float p[4];

  for (size_t i = 0; i < 4; i++)
  {
    p[i] = sensors[i].getPressure();
  }
  MY_PRINT("%5d,%10.3f,%10.3f,%10.3f,%10.3f,%10.3f,%10.3f\n", nbLect++, 
      p[0], p[1], p[2], p[3], p[1] - p[0], p[3] - p[2]);
  delay(1000);
}