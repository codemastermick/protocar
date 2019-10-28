#ifndef LIGHTS_H /* include guards */
#define LIGHTS_H

extern bool headlightsActive; // True if the lowbeams are active
extern bool highbeamsActive;  // True if the highbeams are active
extern bool taillightsActive; // True if the taillights are active

void highbeamsOff();
void highbeamsOn();
void toggleHighbeams();
void headlightsOn();
void headlightsOff();
void toggleHeadlights();
void taillightsOff();
void taillightsOn();
void toggleTaillights();
void blinkHeadlights(int duration);
void blinkTailights(int duration);
void blinkHighbeams(int duration);
void initializeLights();
void testLights();
#endif /* LIGHTS_H */