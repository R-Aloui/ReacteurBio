#pragma once

#define CALIBRATION_SAMPLES     40
#ifdef ESP32ENV
  #define num2volt(x) (float) (x) / 1024.00
#else
  #define num2volt(x) (float) (x) * 5/ 1024.00
#endif

class MY_SEN0257
{
private:
  typedef struct
  {
    float v;
    float minv;
    float maxv;
  } vals_t;

  int datapin;
  float offset;
public:
  MY_SEN0257(int);
  void calibration();
  float getPressure();
  void setOffeset(float);
};