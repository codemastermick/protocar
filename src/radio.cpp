#include <settings.h>
#include <controlPackage.h>
#include <SPI.h>
#include "RF24.h"

byte addresses[][6] = {"cntlr", "robot"};

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 1;
RF24 radio(CE_PIN, CSN_PIN); // CE, CSN
/**********************************************************/

void configureRadio()
{
    radio.begin();

    // Set the PA Level low to prevent power supply related issues since this is a
    // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
    radio.setPALevel(RF24_PA_MIN);
    radio.setDataRate(RF24_250KBPS);

    // Open a writing and reading pipe on each radio, with opposite addresses
    if (radioNumber)
    {
        radio.openWritingPipe(addresses[0]);
        radio.openReadingPipe(0, addresses[1]);
    }
    else
    {
        radio.openWritingPipe(addresses[1]);
        radio.openReadingPipe(1, addresses[0]);
    }

    // Start the radio listening for data
    radio.startListening();
    if (debugMode)
    {
        radio.printDetails();
    }
}

void pongBack()
{
    if (radio.available())
    {                                  // While there is data ready
        radio.read(&pkg, sizeof(pkg)); // Get the payload

        radio.stopListening();          // First, stop listening so we can talk
        radio.write(&pkg, sizeof(pkg)); // Send the final one back.
        radio.startListening();         // Now, resume listening so we catch the next packets.
    }
    if (debugMode)
    {
        printPackage();
    }
}