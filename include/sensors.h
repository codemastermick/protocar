#ifndef SENSORS_H /* include guards */
#define SENSORS_H

extern long distance;
extern int lightLevel;

int getLightLevel();
void getSensorData();
void logSensorData();
void initializeSensors();

#endif /* SENSORS_H */