#include "interrupts.h"

void setupIRQ(){
    //BWF Detect
    pinMode(2,INPUT_PULLUP);
    ISR_BWF_setup();

    pinMode(3,INPUT_PULLUP);
    ISR_Collision_setup();
};

void ISR_BWF_detection() {
    BWFDetected =1;
    attachInterrupt(digitalPinToInterrupt(3),ISR_BWF_setup,RISING);
};

void ISR_Collision_detection() {
    CollisionDetected =1;
    attachInterrupt(digitalPinToInterrupt(3),ISR_Collision_detection,RISING);
};

void ISR_BWF_setup() {
    BWFDetected =0;
    attachInterrupt(digitalPinToInterrupt(3),ISR_BWF_detection,FALLING);
};

void ISR_Collision_setup() {
    CollisionDetected =0;
    attachInterrupt(digitalPinToInterrupt(3),ISR_Collision_detection,FALLING);
};
