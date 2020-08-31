#ifndef _movement_h
#define _movement_h
#include "globals.h"
#include "Wheel.h"
#include "sensoractions.h"

// variables
extern const int8_t SchedTicks;
extern int mov_seqNumber;
extern Wheel leftWheel;
extern Wheel rightWheel;
extern State mowerState;

extern ActionFn Action;
 
//prototypes
void mov_Movement(int8_t Ticks);
void mov_UpdateMovement();
void SetDuration(int i);
void InitNextAction();
void mov_BWF_Detected(Side s);
void mov_SetAction(ActionFn Fn);
void mov_SetTargetSpeed(int Left, int Right, int Duration);
void mov_ContinousCutting(int t);
void mov_StraightCutting();
void mov_HandleCollision();
void mov_BWFBackout();
void mov_BWFTurn();
void mov_FindBWF();
void mov_Circle();
#endif