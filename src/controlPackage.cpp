#include <Arduino.h>
#include <controlPackage.h>

controlStruct pkg;

void printPackage()
{    
  Serial.print("Direction: ");
  Serial.print(pkg.speed);
  Serial.print(" | Bearing: ");
  Serial.print(pkg.bearing);
  Serial.print(" | Honk: ");
  Serial.print(pkg.honk);
  Serial.print(" | Lights: ");
  Serial.println(pkg.headlights);
}