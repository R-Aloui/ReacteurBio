#include <Arduino.h>
#include "my_sen0257.cpp"
#include "common.hpp"

MY_SEN0257 s1(A0);

void setup(){
  Serial.begin(57600);
  Serial.print("Bonjour\n");
  //s1.calibration();
  s1.setOffeset(0.474);
}

void loop(){
  MY_PRINT("La pressions actuelle est : %.3f\n", s1.getPressure());
  delay(500);
}