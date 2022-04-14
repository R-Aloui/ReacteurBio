#pragma once

#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)
#define CALIBRATION_SAMPLES     50


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
};