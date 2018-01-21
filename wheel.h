#ifndef wheel_h
#define wheel_h

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



void motorControl(int left, int right){ 
    const int leftPin = 0;
    const int rightPin = 1;
    int dir;
    int spd;
    
    dir = (left>0) ? 1 : 0;
    spd = 255 - (left >> 7); 
    if (spd < 0) spd = 0;
    
    // WriteSpeed to device
    analogWrite(leftPin, spd);
    
    dir = (right>0) ? 1 : 0;
    spd = 255 - (right >> 7); 
    if (spd < 0) spd = 0;
    // WriteSpeed to device     
    analogWrite(rightPin, spd);
};

#endif 