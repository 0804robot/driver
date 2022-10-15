#include "FCH.h"
#include <Servo.h>
#include "Arduino.h"

FCH::FCH(int motor)
{
    this->_motor_pin = motor;
    _motor.attach(this->_motor_pin);  
}

void FCH::setSpeed(int motor_speed)
{
    _motor.write(motor_speed);
}
void FCH::brake(int mode)
{
    _motor.write(90);
}