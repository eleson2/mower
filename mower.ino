#include <TaskScheduler.h> 
#include "globals.h"
#include "wheel.h"

#include "sensoractions.h"


wheel leftWheel(Left), 
      rightWheel(Right);


void wait(int a);
void RecalculateSpeedCB();
void StateMachineCB();

Task  RecalculateSpeed(SchedTicks,TASK_FOREVER, RecalculateSpeedCB);
Task  MainStateMachine(50,TASK_FOREVER, &StateMachineCB);

void  (*HandleState[NUM_STATES])();


State mowerState;
Scheduler runner;
 
#include "moweractions.h"  

void RecalculateSpeedCB(){ 
  leftWheel.AdjustSpeed();
  rightWheel.AdjustSpeed();
  leftWheel.SendSpeed();
  rightWheel.SendSpeed();
};


inline bool Completed() { return !RecalculateSpeed.isEnabled(); };

void StateMachineCB() {
  if (!Completed()) return;  // allow previous request to complete
  HandleState[mowerState];
};



void wait(int a) {
  RecalculateSpeed.setIterations(a);
  RecalculateSpeed.enableDelayed();
};

void setup() {
  //define callbacks for Task
  //    HandleState[CUTTING_STATE] = &straightCutting€;
  HandleState[CUTTING_STATE] = HandleCollision;
  HandleState[CUTTING_COLLISION_STATE] = HandleCollision;
  HandleState[BWF_BACKOUT_STATE] = straightCutting;
  HandleState[BWF_TURN_STATE] = straightCutting;
  HandleState[FIND_BWF_STATE] = straightCutting;
  HandleState[BWF_COLLISION_STATE] = straightCutting;

  // put your setup code here, to run once:
  runner.init();

  runner.addTask(RecalculateSpeed);
  runner.addTask(MainStateMachine);

  delay(2000);

  RecalculateSpeed.enable();
  MainStateMachine.enable();
};

void loop() {
  runner.execute();
};