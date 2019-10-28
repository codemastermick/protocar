#ifndef SONAR_H /* include guards */
#define SONAR_H

// Returns the echo distance in cm, or -1 if the sensor was not ready
long pingSonar();
// Runs a quick test and logs to serial
bool testSonar();
// Do some logging and run the test function
void initializePing();

#endif /* SONAR_H */