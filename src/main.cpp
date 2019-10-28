#include <Arduino.h> // Arduino core libraries
#include <printf.h>

#include <settings.h> // pin definitions
#include <errors.h>   // error handling

#include <horn.h>   // horn control
#include <car.h>    // main car functions
#include <lights.h> // headlights and tailights

#include <sensors.h>        // sensor handler
#include <radio.h>          // radio handler
#include <controlPackage.h> // radio payload

void handleControlPackage()
{
  if (pkg.speed)
  {
    if (pkg.speed < 0)
    {
      reverse();
    }
    else if (pkg.speed > 0)
    {
      drive();
    }
    else
    {
      brake();
    }
  }

  if (pkg.bearing)
  {
    if (pkg.bearing < 0)
    {
      turnLeft();
    }
    else
    {
      turnRight();
    }
  }

  if (pkg.honk)
  {
    honk();
  }

  if (pkg.headlights == 1)
  {
    if (lightLevel < 50 && headlightsActive)
    {
      headlightsOff();
      highbeamsOn();
    }

    if (lightLevel >= 50 && highbeamsActive)
    {
      highbeamsOff();
      headlightsOn();
    }
  }
  else
  {
    headlightsOff();
    highbeamsOff();
  }
}

// MAIN
void setup()
{
  Serial.begin(baudrate);
  printf_begin();

  Serial.println();
  Serial.println("Protobot initializing....");

  pinMode(DEBUG_PIN, INPUT);
  debugMode = digitalRead(DEBUG_PIN) == LOW;
  if (debugMode)
  {
    Serial.println("Debugging mode is on");
  }

  initializeSensors();
  configureRadio();
  initializeCar();

  Serial.println();
  if (!hasError)
  {
    Serial.println("Protobot started successfully");
  }
  else
  {
    Serial.println("Protobot failed to start...");
    while (hasError)
    {
      alarm();
    }
  }
}

void loop()
{
  getSensorData();
  if (Serial.available())
  {
    char c = Serial.read();
    if (c == 's')
    {
      logSensorData();
    }
  }

  if (alarmActive)
  {
    alarm();
  }

  pongBack();
  handleControlPackage();
}
