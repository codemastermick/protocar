# Protobot experiment

This is a simple robot car that uses an RF controller to drive around.

It also will include support for automatic control at a later date.

## Pinout

* MOTOR_A_EN A0
* MOTOR_B_EN A1
* LDR_PIN A5
* PIN_A1 0
* PIN_A2 1
* DEBUG_PIN 2
* TAILIGHT_PIN 3
* PIN_B1 4
* HEADLIGHT_PIN 5
* SPEAKER_PIN 6
* PIN_B2 7
* TRIGGER_PIN 8  
* ECHO_PIN 8

## Sensors

* HC-SR04 (distance sensor)
* GL5528 (light sensor)

## Features

* Headlights
* Highbeams
* Taillights
* Horn
* Car alarm

## Notes

By pulling pin 2 to ground the car is set to debugging mode. This will run tests on startup as well as provide serial console output.

The radio is set to channel 43 with a transmission rate of 250KBPS
