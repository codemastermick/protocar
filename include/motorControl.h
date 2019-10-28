#include <Arduino.h>

extern boolean run;

void motorAOn();
void motorBOn();
void motorAOff();
void motorBOff();
void motorAForward();
void motorABackward();
void motorBForward();
void motorBBackward();
void motorACoast();
void motorABrake();
void motorBCoast();
void motorBBrake();
// Turn on all motors
void enableMotors();
// Turn off all motors
void disableMotors();
// Call to accelerate forwards
void forward(int time);
void backward(int time);
// Call to turn to the left
void left(int time);
// Call to turn to the right
void right(int time);
// Call to cruise straight ahead
void coast(int time);
// Call to stop the car
void brake(int time);
// Motor Control demo
void motorControlDemo(byte loopTimes = 1);
void warmup();
void initializeMotors();