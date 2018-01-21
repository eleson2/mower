#include "wheel.h"

wheel::wheel(){
  CurrSpd = 0;
  TargetSpd = 0;
  SpeedIncrement = 0;
};
void wheel::setTargetSpeed( int Speed, int iterations) {
  TargetSpd = Speed;
  SpeedIncrement = (CurrSpd - TargetSpd)/iterations; 
};
void wheel::AdjustSpeed() { CurrSpd += SpeedIncrement; }; 
int  wheel::TargetSpeed() { return TargetSpd; };
int  wheel::Speed()       { return CurrSpd; };
