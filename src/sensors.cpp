#include <Arduino.h>  // Arduino core libraries
#include <settings.h> // pin definitions
#include <pinger.h>   // distance sensor

long distance;
int lightLevel;

int getLightLevel()
{
  return map(analogRead(LDR_PIN), 0, 1024, 0, 100);
}

void getSensorData()
{
  distance = pingSonar();
  if (distance == -1)
  {
    distance = pingSonar();
  }

  lightLevel = getLightLevel();
}

void logSensorData()
{
  Serial.print("Distance:\t");
  Serial.print(distance);
  Serial.println(useMetric ? "cm" : "in");

  Serial.print("Light level:\t");
  Serial.print(lightLevel);
  Serial.println("%");
}

void initializeSensors()
{
  if (debugMode)
  {
    Serial.println("Starting up sensors....");
  }

  pinMode(LDR_PIN, INPUT);
  initializePing();

  if (debugMode)
  {
    Serial.println("Sensors ready");
  }
}