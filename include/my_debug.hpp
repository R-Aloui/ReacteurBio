#pragma once

#define MY_DEBUG

#define D_CALIBRATION

#ifdef MY_DEBUG
  #define D(x)    x
#else
  #define D(x)
#endif

#ifdef D_CALIBRATION
  #define D_CALIB(x)    D(x)
#else
  #define D_CALIB(x)
#endif