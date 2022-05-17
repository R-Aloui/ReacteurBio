#pragma once

#ifdef ESP32ENV
  #define min(a,b) ((a)<(b)?(a):(b))
  #define max(a,b) ((a)>(b)?(a):(b))
  #define MY_PRINT Serial.printf
#else
  #include <LibPrintf.h>
  #define MY_PRINT printf
#endif