#include <Arduino.h>
#include <settings.h>

void beep(uint8_t delayms, uint8_t frequency = HIGH)
{
  for (int i = 0; i < 20; i++)
  {
    analogWrite(SPEAKER_PIN, frequency);
    delay(delayms);
    analogWrite(SPEAKER_PIN, LOW);
    delay(delayms);
  }
}

void solidTone(uint8_t length, uint8_t frequency = HIGH)
{
  analogWrite(SPEAKER_PIN, frequency);
  delay(length);
  analogWrite(SPEAKER_PIN, LOW);
}

void initializeHorn()
{
  if (debugMode)
  {
    Serial.println();
    Serial.println("Initializing horn...");
  }
  pinMode(SPEAKER_PIN, OUTPUT);
  if (debugMode)
  {
    Serial.print("Testing\t\t\t");
    beep(10,200);
    Serial.println("OK");
  }
}