#ifndef wheel_h
#define wheel_h

#include "Arduino.h"
#include "globals.h"

// #include "physWheel.h"

class wheel {
private:
  int  TargetSpd;
  int  CurrSpd;
  int  SpeedIncrement;
  Side WheelSide;
public:
  wheel();
  wheel(Side);
  void ReCalcSpeed(); 
  void setTargetSpeed( int Speed, int iterations);
  void AdjustSpeed(void);
  int  TargetSpeed(void) ;
  int  Speed(); 
  void SendSpeed();
};





#endif 