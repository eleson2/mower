#include "wheel.h"

wheel::wheel(){
  CurrSpd = 0;
  TargetSpd = 0;
  SpeedIncrement = 0;
};

wheel::wheel(Side s){
  WheelSide = s;
  wheel();
};

void wheel::setTargetSpeed( int Speed, int iterations) {
  TargetSpd = Speed;
  SpeedIncrement = (CurrSpd - TargetSpd)/iterations; 
};

void wheel::AdjustSpeed() { CurrSpd += SpeedIncrement; }; 
int  wheel::TargetSpeed() { return TargetSpd; };
int  wheel::Speed()       { return CurrSpd; };

void wheel::ReCalcSpeed() {
  AdjustSpeed();
  SendSpeed(); 
};


/*
 * Speed is transcoded as 16 bit 2nd complement nmbr , negative meaning backwards
 * Full speed forward is 32767
*/

void wheel::SendSpeed() {
  int Pin = (WheelSide == Left) ? 1 : 0;  // Left pin# , Right Pin# 
  int Direction = (CurrSpd > 0) ? 1 : 0; 
  int spd = 255 - (CurrSpd >> 7); 
  if (spd < 0) spd = 0;
  
  analogWrite(Pin, spd);
}