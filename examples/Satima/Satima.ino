#include "Satima.h"

Satima driver(5, 6);

void setup()
{
    driver.setMaxSpeed(255);
}

void loop()
{
    driver.setSpeed(200, CLOCKWISE);
    delay(2000);
    driver.setSpeed(200, COUNTERCLOCKWISE);
    delay(2000);
}
