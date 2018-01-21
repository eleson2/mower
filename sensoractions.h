#ifndef _sensoractions_h
#define _sensoractions_h  
#include "globals.h"


int GetWireSide() { 
  if (1 /*rightSensorActivated()*/){
    return RIGHT;}
  else {
    return LEFT;
  };
};

/*
void BWFCrossed(void) {
  switch(mowerState) {
    case FIND_BWF_STATE:
      mowerState = GOING_HOME;
      break;
    case CUTTING_STATE:
      mowerState = BWF_TURN_STATE;
      break;
    case CUTTING_COLLISION_STATE:
      mowerState = BWF_BACKOUT_STATE;
      break;
    
    default:  
    ;
  }; 
  seqNumber=0;
};
*/

#endif 