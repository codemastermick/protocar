#include <settings.h>
#include <horn.h>
#include <lights.h>
#include <motorControl.h>
#include <sensors.h>

bool alarmActive = false;

int cmdLength = 1;

void alarm()
{
    beep(5, 150);
    beep(5, 150);
    beep(5, 250);
    beep(5, 250);
    toggleHighbeams();
    toggleTaillights();
    delay(50);
    beep(5, 150);
    beep(5, 150);
    beep(5, 250);
    beep(5, 250);
    toggleHighbeams();
    toggleTaillights();
    delay(50);
}

void deactivateAlarm()
{
    alarmActive = false;
}

void reverse()
{
    taillightsOn();
    backward(cmdLength);
    taillightsOff();
}

void drive()
{
    getSensorData();
    if (distance > 5)
    {
        forward(cmdLength);
    }
    else
    {
        alarm();
        reverse();
        reverse();
        reverse();
    }
}

void brake()
{
    taillightsOn();
    brake(cmdLength);
}

void turnLeft()
{
    // left turn signal
    left(cmdLength);
}

void turnRight()
{
    // right turn signal
    right(cmdLength);
}

/* has a 500ms delay to create the space between honks
* TODO: remove delay and replace with non blocking code
*/
void honk()
{
    beep(5, 150);
    beep(5, 150);
    delay(250);
    beep(5, 150);
    beep(5, 150);
    delay(250);
}

void initializeCar()
{
    initializeLights();
    initializeHorn();
    initializeMotors();
}
