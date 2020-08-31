#include "globals.h"
#include <TaskScheduler.h> 
#include "Wheel.h"
#include "Movement.h"
#include "interrupts.h" 
//#include "sensoractions.h"

const int8_t SchedTicks = 10;  // # of msec between speed adjustments
int mov_seqNumber = 0;

// Volatile indicators
volatile int BWFDetected;
volatile int CollisionDetected;

Wheel leftWheel(Left);
Wheel rightWheel(Right);
State mowerState;
ActionFn Action;
Scheduler runner;

// Adjusts the speed of each wheel with current increment
// and emits it to wheel control.
Task UpdateSpeed(SchedTicks,TASK_FOREVER,mov_UpdateMovement,&runner,false,NULL,InitNextAction);

void SetDuration(int i) {
   UpdateSpeed.setIterations(i);
   UpdateSpeed.restartDelayed();
};

void SensorActivatedCB(Sensor s) {
   mov_BWF_Detected(Left);
   // Do stuff
};

void setup() {
   setupIRQ();
   mov_Movement(SchedTicks); 
   SetSensorCallback(&SensorActivatedCB);
   runner.init();
   runner.addTask(UpdateSpeed);
   delay(200);
   UpdateSpeed.enable();
};

void loop() {
   runner.execute();
   if(BWFDetected) {
      mov_seqNumber = 0;
      mov_SetAction(&mov_BWFBackout);
   } else if (CollisionDetected) {
      mov_seqNumber = 0;
      mov_SetAction(&mov_HandleCollision);
   };
};