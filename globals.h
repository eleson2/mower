#ifndef _globals_h
#define _globals_h
#include <TaskSchedulerDeclarations.h>

//Typedefs

typedef enum  {
  CUTTING_STATE = 0,
  CUTTING_COLLISION_STATE,
  BWF_BACKOUT_STATE,
  BWF_TURN_STATE,
  CIRCLE_STATE,
  FIND_BWF_STATE,
  GOING_HOME,
  BWF_COLLISION_STATE,
  BWF_DETECTED,
  NUM_STATES
} State;

typedef enum  {
  BWF_LEFT = 0,
  BW_RIGHT,
  LIFTED,
  NUM_SENSORS
} Sensor;

typedef enum {
  Left = 25,
  Right = 31
}  Side;

typedef unsigned int Time;
typedef void (*sensorActivatedCB)(Sensor s);
typedef void (*ActionFn)();
typedef void (*DurationCB)(int i);

// Constants
constexpr int MaxSpeed =255<<7;
constexpr int MaxSpeedFwd = MaxSpeed;
constexpr int MaxSpeedBkwd = - MaxSpeed;
constexpr int Speed90 = .9 * MaxSpeed;
constexpr int Speed80 = .8 * MaxSpeed;
constexpr int Speed70 = .7 * MaxSpeed;
constexpr int Speed60 = .6 * MaxSpeed;
constexpr int Speed50 = .5 * MaxSpeed;
constexpr int Speed40 = .4 * MaxSpeed;
constexpr int Speed30 = .3 * MaxSpeed;
constexpr int Speed20 = .2 * MaxSpeed;
constexpr int Speed10 = .1 * MaxSpeed;
constexpr int Speed00 =  0;

#endif