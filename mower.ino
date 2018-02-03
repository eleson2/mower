#include <TaskScheduler.h> 
#include "globals.h"
#include "wheel.h"
#include "sensoractions.h"


const int8_t SchedTicks = 50;  // # of msec between speed adjustments
int seqNumber = 0;
void  (*HandleState[NUM_STATES])();

void RecalculateSpeedCB();
void StateMachineCB();
void SetDuration(int i);


wheel leftWheel(Left), 
      rightWheel(Right);

State mowerState;
Scheduler runner;

#include "moweractions.h"  

Task  RecalculateSpeed(SchedTicks,TASK_FOREVER, RecalculateSpeedCB);
Task  MainStateMachine(50,TASK_FOREVER, &StateMachineCB);

// mowerPath    &currentAction = &straightCutting; 

void SetDuration(int i ){
  RecalculateSpeed.setIterations(i);
  RecalculateSpeed.enableDelayed();
}

void RecalculateSpeedCB(){ 
  leftWheel.ReCalcSpeed();
  rightWheel.ReCalcSpeed();
};

void StateMachineCB() {
  if (RecalculateSpeed.isEnabled()) return;  // allow previous request to complete

  (*HandleState[mowerState])();
};

void setup() {
  //define callbacks for Task
  HandleState[CUTTING_STATE] = &straightCutting;
  //HandleState[CUTTING_STATE] = &HandleCollision;
  HandleState[CUTTING_COLLISION_STATE] = &HandleCollision;
  HandleState[BWF_BACKOUT_STATE] = &BWFBackout;
  HandleState[BWF_TURN_STATE] = &BWFTurn;
  HandleState[CIRCLE_STATE] = &Circle;
  HandleState[FIND_BWF_STATE] = &FindBWF;
  HandleState[GOING_HOME] = &straightCutting;
  HandleState[BWF_COLLISION_STATE] = &straightCutting;

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