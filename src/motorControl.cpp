#include <Arduino.h>
#include <settings.h>

boolean run = true;

#pragma region Low Level Commands
//enable motors
void motorAOn()
{
    digitalWrite(MOTOR_A_EN, HIGH);
}

void motorBOn()
{
    digitalWrite(MOTOR_B_EN, HIGH);
}

//disable motors
void motorAOff()
{
    digitalWrite(MOTOR_B_EN, LOW);
}

void motorBOff()
{
    digitalWrite(MOTOR_A_EN, LOW);
}

//motor A controls
void motorAForward()
{
    digitalWrite(PIN_A1, HIGH);
    digitalWrite(PIN_A2, LOW);
}

void motorABackward()
{
    digitalWrite(PIN_A1, LOW);
    digitalWrite(PIN_A2, HIGH);
}

//motor B controls
void motorBForward()
{
    digitalWrite(PIN_B1, HIGH);
    digitalWrite(PIN_B2, LOW);
}

void motorBBackward()
{
    digitalWrite(PIN_B1, LOW);
    digitalWrite(PIN_B2, HIGH);
}

void motorACoast()
{
    digitalWrite(PIN_A1, LOW);
    digitalWrite(PIN_A2, LOW);
}

void motorBCoast()
{
    digitalWrite(PIN_B1, LOW);
    digitalWrite(PIN_B2, LOW);
}

void motorABrake()
{
    digitalWrite(PIN_A1, HIGH);
    digitalWrite(PIN_A2, HIGH);
}

void motorBBrake()
{
    digitalWrite(PIN_B1, HIGH);
    digitalWrite(PIN_B2, HIGH);
}
#pragma endregion

#pragma region High Level Commands
void enableMotors()
{
    motorAOn();
    motorBOn();
}

void disableMotors()
{
    motorAOff();
    motorBOff();
}

void forward(int time)
{
    motorAForward();
    motorBForward();
    delay(time);
}

void backward(int time)
{
    motorABackward();
    motorBBackward();
    delay(time);
}

void left(int time)
{
    motorABackward();
    motorBForward();
    delay(time);
}

void right(int time)
{
    motorAForward();
    motorBBackward();
    delay(time);
}

void coast(int time)
{
    motorACoast();
    motorBCoast();
    delay(time);
}

void brake(int time)
{
    motorABrake();
    motorBBrake();
    delay(time);
}
#pragma endregion

// Basic control demo
void motorControlDemo(byte loopTimes = 1)
{
    for (byte counter = 0; counter < loopTimes; counter++)
    {
        if (run)
        {
            enableMotors();  // Turn the motors on
            forward(200);    // Go forward
            backward(200);   // Go backward
            left(400);       // Turn left
            coast(200);      // Coast ahead for 200 ms
            right(400);      // Turn right
            coast(200);      // Coast ahead for 200 ms
            disableMotors(); // Turn the motors back off to conserve power
            run = false;     // This stops the loop
        }
    }
}

void warmup()
{
    enableMotors();
    forward(500);
    backward(500);
    left(100);
    right(200);
    left(100);
    forward(500);
    backward(500);
    disableMotors();
}

void initializeMotors()
{
    pinMode(MOTOR_A_EN, OUTPUT);
    pinMode(MOTOR_B_EN, OUTPUT);
    pinMode(PIN_A1, OUTPUT);
    pinMode(PIN_A2, OUTPUT);
    pinMode(PIN_B1, OUTPUT);
    pinMode(PIN_B2, OUTPUT);
}