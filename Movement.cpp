#include "Movement.h"

void mov_SetAction(ActionFn Fn) { 
   Action = Fn; 
};

void mov_UpdateMovement() {
   leftWheel.EmitNewSpeed();
   rightWheel.EmitNewSpeed();
};

/* Sets new target speed for left and right wheel 
 * and sets the time to reach the speed.
 * Allows for smooth acceleration. */
void mov_SetTargetSpeed (int LSpeed, int RSpeed, int mSec) {
   int i = mSec / SchedTicks;
   if (i<=0) i=1;
   leftWheel.setTargetSpeed(LSpeed,i);
   rightWheel.setTargetSpeed(RSpeed,i); 
   SetDuration(mSec);
};

void mov_Movement(int8_t Ticks) {
   mov_SetAction(&mov_StraightCutting);
   mowerState = CUTTING_STATE;
};

void InitNextAction() { 
   (*Action)(); 
};

void mov_BWF_Detected(Side s) {
  mov_SetAction(&mov_BWFBackout);
   mowerState = BWF_BACKOUT_STATE;
   mov_seqNumber = 0;
   (*Action)(); 
};

void mov_ContinousCutting(int t){
   mov_seqNumber = 0;
   mov_SetAction(&mov_StraightCutting);
};

void mov_StraightCutting() {
   switch(mov_seqNumber) {
      case 0:
         mov_SetTargetSpeed(MaxSpeed,MaxSpeed,2000);
         break;
      default:
         SetDuration(TASK_FOREVER);
         ;  // Set mowerState to Cutting
   };
   mov_seqNumber++;
};

void mov_HandleCollision() {
   switch(mov_seqNumber) {
      case 0:  // Backout within 100 msec
         mov_SetTargetSpeed (-Speed30,-Speed30,200);
         break;
      case 1:  // Keep backing out and turn.
         mov_SetTargetSpeed (-Speed30,-Speed10,1500);
         break;
      case 2: // turn and go forward.
         mov_SetTargetSpeed (Speed00,Speed40,1400); // Turn
         break;
      case 3:
         mov_SetTargetSpeed (Speed50,Speed50,2000); // go out from collision
         break;
      default:
         mov_ContinousCutting(1500);  // Set mowerState to Cutting
   };
   mov_seqNumber++;
};

void mov_BWFBackout() {
   switch(mov_seqNumber) {
      case 0:  //Backoutstraight
         mov_SetTargetSpeed(Speed00,Speed00,300);
         break;
      case 1: //Backout with turn
         mov_SetTargetSpeed(-Speed30,Speed30,2000);
         break;
      case 2: // Let it turn.
         SetDuration(2000);
         break;
      case 3: // go out from collision
         mov_SetTargetSpeed(Speed50,Speed50,1500);
         break;
      default:
         mov_ContinousCutting(2000);  // Set mowerState to Cutting
   };
   mov_seqNumber++;
};

void mov_BWFTurn() {
   static Side BWFSide; // Remember where the wire is.

   switch(mov_seqNumber) {
      case 0:
         BWFSide = GetWireSide();
         BWFSide = Right;
         break;
      case 1:
         if (BWFSide == Right) {
            mov_SetTargetSpeed(Speed20,Speed80,1500 ); // Turn!
         } else {
            mov_SetTargetSpeed(Speed80,Speed20,1500 ); // Turn!
         }
         break;
      default:
         mov_ContinousCutting(1000);  // Set mowerState to Cutting
         //BWFSide = Left;
   };
   mov_seqNumber++; 
};

void mov_FindBWF(){
   //stopCutterDisc();
   switch (mov_seqNumber) {
      case 0:
         mov_SetTargetSpeed(Speed50,Speed50,1000);
         break;
      case 1:
         ;
      default:
         SetDuration(TASK_FOREVER);
   };
   mov_seqNumber++;
};

void mov_Circle(){
   switch (mov_seqNumber) {
      case 0:
         mov_SetTargetSpeed(Speed00,Speed00,800);
         break;
      case 1:
         mov_SetTargetSpeed(-Speed70,-Speed50,800);
         break;
      case 2:
         mov_SetTargetSpeed(Speed00,Speed60,900);
         break;
      case 3:
         mov_SetTargetSpeed(Speed90,MaxSpeedFwd,30000);
         break;
      default:
         mov_ContinousCutting(1500);
   };
   mov_seqNumber++;
};