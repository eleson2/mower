#ifndef _Wheel_h
#define _Wheel_h

#include "globals.h"
#include "Arduino.h"

class Wheel {
private:
  int  TargetSpeed;
  int  CurSpeed;
  int  SpeedIncrement;
  Side WheelID;
public:
  Wheel();
  Wheel(Side);
  void SetSide(Side);
  void EmitNewSpeed(); 
  void setTargetSpeed( int Speed, int iterations);
};
#endif