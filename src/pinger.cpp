#include <settings.h> // pin definitions
#include <NewPing.h>  // Sonar unit library
#include <errors.h>

//Tell the Arduino where the sensor is hooked up
NewPing sonar(TRIGGER_PIN, ECHO_PIN, maxDistance);

long lastPing = -50;

long pingSonar()
{
    unsigned long currentMillis = millis();
    long dist = -1;

    if (currentMillis - lastPing >= pingInterval)
    {
        lastPing = currentMillis;
        dist = useMetric ? sonar.ping_cm() : sonar.ping_in();
    }

    return dist;
}

bool testSonar()
{
    long dist = pingSonar();
    return dist != -1;
}

void initializePing()
{
    if (debugMode)
    {
        Serial.println();
        Serial.println("Initializing sonar...");
    }

    if (debugMode)
    {
        Serial.print("Testing\t\t\t");
    }
    if (testSonar())
    {
        if (debugMode)
        {
            Serial.println("OK");
        }
    }
    else
    {
        hasError = true;
        throwError("sonar", "sonar.ping did not return a value");
        if (debugMode)
        {
            Serial.println("Sonar unit failed to start");
        }
    }
}
