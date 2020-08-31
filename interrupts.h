#ifndef _interrupts_h_
#define _interrupts_h_
#include "globals.h"
#include "arduino.h"

void setupIRQ();
extern volatile int BWFDetected;
extern volatile int CollisionDetected;

void ISR_BWF_detection();
void ISR_Collision_detection();
void ISR_BWF_setup();
void ISR_Collision_setup();
#endif