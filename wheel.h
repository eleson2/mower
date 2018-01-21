#ifndef wheel_h
#define wheel_h

#include "Arduino.h"
class wheel {
private:
  int  TargetSpd;
  int  CurrSpd;
  int  SpeedIncrement;
public:
  wheel();
  void setTargetSpeed( int Speed, int iterations);
  void AdjustSpeed(void);
  int TargetSpeed(void) ;
  int Speed(); 
};





#endif 