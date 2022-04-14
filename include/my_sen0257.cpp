#include "my_sen0257.hpp"
#include "my_debug.hpp"
#include <Arduino.h>


MY_SEN0257::MY_SEN0257(int pin)
{
  datapin = pin;
}

void MY_SEN0257::calibration()
{
  D_CALIB(Serial.printf("Inside MY_SEN0257::calibration()\n");)
  vals_t voltage;
  vals_t pressure;
  int readV;

  Serial.println("Start calibration");
  for (int nbReadings = 0; nbReadings < CALIBRATION_SAMPLES; nbReadings++)
  {
    readV = analogRead(datapin);
    voltage.v = readV / 1024.00;
    if (nbReadings < 1)
    {
      voltage.maxv = voltage.v;
      voltage.minv = voltage.v;
      D_CALIB(Serial.printf("%s;%s;%s;%s;%s;%s;%s;%s\n",
                    "nb", "readV", "voltage.minv", "voltage.v", "voltage.maxv",
                    "pressure.minv", "pressure.v", "pressure.maxv");)
    }
    voltage.minv = min(voltage.minv, voltage.v);
    voltage.maxv = max(voltage.maxv, voltage.v);

    pressure.v = (voltage.v - voltage.minv) * 400;
    if (nbReadings < 1)
    {
      pressure.maxv = pressure.v;
      pressure.minv = pressure.v;
    }
    pressure.maxv = max(pressure.maxv, pressure.v);
    pressure.minv = min(pressure.minv, pressure.v);

    D_CALIB(Serial.printf("%d;%d;%.3f;%.3f;%.3f;%.3f;%.3f;%.3f\n",
                  nbReadings, readV, voltage.minv, voltage.v, voltage.maxv,
                  pressure.minv, pressure.v, pressure.maxv);)
    delay(500);
  }
  
  offset = voltage.minv;
  D_CALIB(Serial.printf("End calibration, the offset is %.3f\n", offset);)
}

float MY_SEN0257::getPressure()
{
  float voltage;
  float pressure;

  voltage = analogRead(datapin) / 1024.00;
  pressure = (voltage - offset) * 400;

  return pressure;
}