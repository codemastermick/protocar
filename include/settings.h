#define LDR_PIN A5      // Connected to a light sensor
#define DEBUG_PIN 2     // Pull to ground to put the car into debug mode
#define TAILIGHT_PIN 3  // Tailights are attached to this pin - PWM or Analog
#define HEADLIGHT_PIN 5 // Headlights are attached to this pin - PWM or Analog
#define SPEAKER_PIN 6   // PWM pin attached to buzzer - PWM or Analog
#define TRIGGER_PIN 8   // Trigger pin on ping sensor.
#define ECHO_PIN 8      // Echo pin on ping sensor.
#define CE_PIN 9        // Pin connected to CE pin of RF module
#define CSN_PIN 10      // Pin connected to CSN pin of RF module

#define MOTOR_A_EN A0 // Motor A enable pin
#define PIN_A1 0         // Motor A pin 1
#define PIN_A2 1         // Motor A pin 2
#define MOTOR_B_EN A1 // Motor B enable pin
#define PIN_B1 4         // Motor B pin 1
#define PIN_B2 7         // Motor B pin 2

extern bool debugMode;   // True if the car should log to serial
extern bool hasError;    // True when there is a problem
extern bool useMetric;   // True by default. Set to false to use Imperial values
extern long baudrate;    // Speed at which the serial port operates
extern int maxDistance;  // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
extern int pingInterval; // How often the distance sensor should ping out