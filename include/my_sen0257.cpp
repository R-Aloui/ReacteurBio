#include "my_sen0257.hpp"
#include "my_debug.hpp"
#include "common.hpp"
#include <Arduino.h>

MY_SEN0257::MY_SEN0257(int pin){
  datapin = pin;
}

void MY_SEN0257::calibration(){
  // D_CALIB(MY_PRINT("Inside MY_SEN0257::calibration()\n");)
  vals_t voltage;
  vals_t pressure;
  int readV;

  MY_PRINT("Start calibration");
  D_CALIB(MY_PRINT("\n%s;%s;%s;%s;%s;%s;%s;%s\n",
                   "nb", "readV", "voltage.minv", "voltage.v", "voltage.maxv",
                   "pressure.minv", "pressure.v", "pressure.maxv");)
  for (int nbReadings = 0; nbReadings < CALIBRATION_SAMPLES; nbReadings++){
    readV = analogRead(datapin);
    voltage.v = num2volt(readV);
    if (nbReadings < 1)
    {
      voltage.maxv = voltage.v;
      voltage.minv = voltage.v;
    }
    voltage.minv = min(voltage.minv, voltage.v);
    voltage.maxv = max(voltage.maxv, voltage.v);

    pressure.v = (voltage.v - voltage.minv) * 400;
    if (nbReadings < 1){
      pressure.maxv = pressure.v;
      pressure.minv = pressure.v;
    }
    pressure.maxv = max(pressure.maxv, pressure.v);
    pressure.minv = min(pressure.minv, pressure.v);

    D_CALIB(MY_PRINT("%d;%d;%.3f;%.3f;%.3f;%.3f;%.3f;%.3f\n",
                     nbReadings, readV, voltage.minv, voltage.v, voltage.maxv,
                     pressure.minv, pressure.v, pressure.maxv);)
    delay(500);
  }

  offset = voltage.minv;
  D_CALIB(MY_PRINT("End calibration, the offset is %.3f\n", offset);)
}

float MY_SEN0257::getPressure(){
  float voltage;
  float pressure;

  voltage = num2volt(analogRead(datapin)); // atx dell
  pressure = (voltage - offset) * 400;

  return pressure;
}
void MY_SEN0257::setOffeset(float o){
  offset = o;
}