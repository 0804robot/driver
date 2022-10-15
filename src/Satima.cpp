#include "Satima.h"

Satima::Satima(int motor_pin_1, int motor_pin_2)
{
    this->_motor_pin_1 = motor_pin_1;
    this->_motor_pin_2 = motor_pin_2; 
    pinMode(this->_motor_pin_1, OUTPUT);
    pinMode(this->_motor_pin_2, OUTPUT);   
}
void Satima::setMaxSpeed(int max_speed)
{
    this->max_speed = max_speed;
}
void Satima::setSpeed(int motor_speed, int direction)
{
    switch (direction)
    {
    case CLOCKWISE:
        analogWrite(this->_motor_pin_1, motor_speed);
        analogWrite(this->_motor_pin_2, 0);
        break;
    case COUNTERCLOCKWISE:
        analogWrite(this->_motor_pin_1, 0);
        analogWrite(this->_motor_pin_2, motor_speed);
        break;
    default:
        break;
    }
}
void Satima::brake(int mode)
{
    if (mode == COAST)
    {
        digitalWrite(_motor_pin_1, LOW);
        digitalWrite(_motor_pin_2, LOW);
    }
    else if (mode == BRAKE)
    {
        digitalWrite(_motor_pin_1, HIGH);
        digitalWrite(_motor_pin_2, HIGH);
    }
}