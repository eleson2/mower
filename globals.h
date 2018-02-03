#ifndef _globals_h
#define _globals_h

//Typedefs
// typedef unsigned int Time;
typedef enum  {
  CUTTING_STATE = 0,
  CUTTING_COLLISION_STATE,
  BWF_BACKOUT_STATE,
  BWF_TURN_STATE,
  CIRCLE_STATE,
  FIND_BWF_STATE,
  GOING_HOME,
  BWF_COLLISION_STATE,
  NUM_STATES
} State;

typedef enum {
  Left = 0,
  Right 
} Side ;

// Constants
const int MaxSpeed =255<<7;
const int MaxSpeedFwd = MaxSpeed;
const int MaxSpeedBkwd = - MaxSpeed;
const int Speed90 = .9 * MaxSpeed;
const int Speed80 = .8 * MaxSpeed;
const int Speed70 = .7 * MaxSpeed;
const int Speed60 = .6 * MaxSpeed;
const int Speed50 = .5 * MaxSpeed;
const int Speed40 = .4 * MaxSpeed;
const int Speed30 = .3 * MaxSpeed;
const int Speed20 = .2 * MaxSpeed;
const int Speed10 = .1 * MaxSpeed;
const int Speed00 =  0;


// State mowerState;
#endif 