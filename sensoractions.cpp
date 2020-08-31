#include "sensoractions.h"

sensorActivatedCB sensorActivated; 

Side GetWireSide() { 
   if (1 /*rightSensorActivated()*/){
      return Right;
   }
   else {
      return Left;
   };
};

void SetSensorCallback(sensorActivatedCB s) { 
   sensorActivated = s; 
};

void BWFCrossed(void) {
   (*sensorActivated)(BWF_LEFT); 
};