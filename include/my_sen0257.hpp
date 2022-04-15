#pragma once

#ifdef ESP32ENV
  #define min(a,b) ((a)<(b)?(a):(b))
  #define max(a,b) ((a)>(b)?(a):(b))
#endif

#define CALIBRATION_SAMPLES     500


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