#include "Wheel.h"

/* Speed is in the range of -32640 - +32640
 *  (255 << 7 ) 
 *  Analog write sends 8-bit 
 */
Wheel::Wheel(){
  CurSpeed = 0;
  TargetSpeed = 0;
  SpeedIncrement = 0;
  //
  pinMode(LED_BUILTIN, OUTPUT);
};

Wheel::Wheel(Side s){
  WheelID = s;
  Wheel();
};

void Wheel::SetSide(Side s) { WheelID = s; };

void Wheel::setTargetSpeed( int Speed, int iterations) {
  TargetSpeed = Speed;
  SpeedIncrement = (CurSpeed - TargetSpeed)/iterations;
};

void Wheel::EmitNewSpeed() {
  CurSpeed += SpeedIncrement;
  int spd = (CurSpeed >> 7); 
  if (spd < 0) {
    spd = -spd;
    digitalWrite(WheelID,HIGH); // Set Direction
    digitalWrite(WheelID,HIGH); 
    analogWrite(WheelID, spd);  // Set Speed
  } else {
    digitalWrite(WheelID,HIGH); // Set Direction
    digitalWrite(WheelID,HIGH); 
    analogWrite(WheelID, spd);  // Set Speed
  };
};
