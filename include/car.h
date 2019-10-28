#ifndef CAR_H /* include guards */
#define CAR_H

extern bool alarmActive; // True if the car alarm is going off

void drive();
void reverse();
void brake();
void turnLeft();
void turnRight();
void honk();
void initializeCar();
void alarm();
void deactivateAlarm();

#endif /* CAR_H */