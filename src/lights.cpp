#include <Arduino.h>
#include <settings.h>

bool headlightsActive = false;
bool highbeamsActive = false;
bool taillightsActive = false;

void highbeamsOn()
{
    highbeamsActive = true;
    digitalWrite(HEADLIGHT_PIN, HIGH);
}

void highbeamsOff()
{
    highbeamsActive = false;
    digitalWrite(HEADLIGHT_PIN, LOW);
}

void toggleHighbeams()
{
    digitalWrite(HEADLIGHT_PIN, !digitalRead(HEADLIGHT_PIN));
    highbeamsActive = digitalRead(HEADLIGHT_PIN);
}

void headlightsOn()
{
    headlightsActive = true;
    analogWrite(HEADLIGHT_PIN, 32);
}

void headlightsOff()
{
    headlightsActive = true;
    analogWrite(HEADLIGHT_PIN, LOW);
}

void toggleHeadlights()
{
    headlightsActive = !headlightsActive;
    analogWrite(HEADLIGHT_PIN, headlightsActive ? 32 : 0);
}

void taillightsOn()
{
    taillightsActive = true;
    digitalWrite(TAILIGHT_PIN, HIGH);
}

void taillightsOff()
{
    taillightsActive = false;
    digitalWrite(TAILIGHT_PIN, LOW);
}

void toggleTaillights()
{
    digitalWrite(TAILIGHT_PIN, !digitalRead(TAILIGHT_PIN));
    taillightsActive = digitalRead(TAILIGHT_PIN);
}

void blinkHeadlights(int duration)
{
    toggleHeadlights();
    delay(duration);
    toggleHeadlights();
}

void blinkTailights(int duration)
{
    toggleTaillights();
    delay(duration);
    toggleTaillights();
}

void blinkHighbeams(int duration)
{
    toggleHighbeams();
    delay(duration);
    toggleHighbeams();
}

void testLights()
{
    blinkHeadlights(1000);
    blinkHighbeams(1000);
    blinkTailights(1000);
}

void initializeLights()
{
    if (debugMode)
    {
        Serial.println();
        Serial.println("Initializing lights...");
    }
    pinMode(HEADLIGHT_PIN, OUTPUT);
    pinMode(TAILIGHT_PIN, OUTPUT);

    if (debugMode)
    {
        Serial.print("Testing\t\t\t");
        testLights();
        Serial.println("OK");
    }
}
