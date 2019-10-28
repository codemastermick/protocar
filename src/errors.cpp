#include <Arduino.h>
#include <errors.h>

char *erroredSystem;
char *errorMessage;

void loadError(char *system, char *msg)
{
    erroredSystem = system;
    errorMessage = msg;
}

void throwError(char *system, char *msg)
{
    loadError(system, msg);
    Serial.print("[");
    Serial.print(erroredSystem);
    Serial.print("] ");
    Serial.print(errorMessage);
}

void printError()
{
    Serial.print("[");
    Serial.print(erroredSystem);
    Serial.print("] ");
    Serial.print(errorMessage);
}