#ifndef HORN_H /* include guards */
#define HORN_H

#include <Arduino.h>

void beep(uint8_t delayms, uint8_t frequency = HIGH);
void solidTone(uint8_t length, uint8_t frequency = HIGH);
void initializeHorn();

#endif /* HORN_H */