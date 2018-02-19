
#ifndef moweractions_h
#define moweractions_h
#include "globals.h"

/* Set a new target speed and how long time it should take to reach it. */

void mowerCommand(int LSpeed,int RSpeed,int t){
    int i = t / SchedTicks;
    if (i<=0) i=1;

    leftWheel.setTargetSpeed(LSpeed,i);
    rightWheel.setTargetSpeed(RSpeed,i);
    SetDuration(i);
};

void StartCutting(int t){
    if (t<=0) { t=1; }; 
    mowerState = CUTTING_STATE;
    seqNumber = -1;
    mowerCommand(Speed90,Speed90,t);
};

void straightCutting() {
    switch(seqNumber) {
        case 0  :
            mowerCommand(MaxSpeed,MaxSpeed,2000);
            break;
        case 1 :
            SetDuration(TASK_FOREVER); 
            break;
        default :
            ;  // Set mowerState to Cutting 
    };
    seqNumber++;
  };


  void HandleCollision() {
    switch(seqNumber) {
        case 0  :  // Backout within 100 msec
            mowerCommand (-Speed30,-Speed30,100 );
            break;
        case 1 :  // Keep backing out and turn. 
            mowerCommand (-Speed30,-Speed10,1500); 
            break;
        case 2 : // Keep backing out and turn.
            mowerCommand (Speed10,Speed40,1400); // Turn!
            break;
        case 3 :
            mowerCommand (Speed50,Speed50,2000); // go out from collision
            break;
        default :
            StartCutting(1500);  // Set mowerState to Cutting 
    };
    seqNumber++; // Advance to next phase
  };
  
  void BWFBackout () {
    switch(seqNumber) {
        case 0 :  //Backoutstraight
            mowerCommand(-Speed30,-Speed30,100);
            break;
        case 1 : //Backout with turn
            mowerCommand(-Speed30,Speed30,2000); 
            break;
        case 2 : // Let it turn.
            SetDuration(2000); 
            break;
        case 3 : // go out from collision
            mowerCommand(Speed50,Speed50,1500); 
            break;
        default : 
            StartCutting(2000);  // Set mowerState to Cutting 
    };
    seqNumber++; // Advance to next phase
  };

  void BWFTurn() {
    static Side BWFSide; // Remember where the wire is.
  
    switch(seqNumber) {
        case 0 :
            BWFSide = GetWireSide();
            break;
        case 1 :
            if (BWFSide == Right) { 
                mowerCommand(Speed20,Speed80,1500 ); // Turn!    
            } else {
                mowerCommand(Speed80,Speed20,1500 ); // Turn!    
            }
            break;
        default : 
            StartCutting(1000);  // Set mowerState to Cutting 
            //BWFSide = Left;
    };
    seqNumber++; // Advance to next phase
  };
  
  void FindBWF(){
    //stopCutterDisc();
    switch (seqNumber) {
        case 0: 
            mowerCommand(Speed50,Speed50,1000);
            break;
        case 1:
            ;
        default:
            SetDuration(TASK_FOREVER);
    };
    seqNumber++;
  };


  void Circle(){
    //stopCutterDisc();
    switch (seqNumber) {
        case 0:
            mowerCommand(Speed00,Speed00,800);
            break;
        case 1:
            mowerCommand(-Speed70,-Speed50,800);
            break;
        case 2:
            mowerCommand(Speed90,MaxSpeedFwd,30000);
            break;
        case 3:
            mowerCommand(MaxSpeedFwd,MaxSpeedFwd,1000);
            break;
        default:
            SetDuration(TASK_FOREVER);
    };
    seqNumber++;
  };

#endif