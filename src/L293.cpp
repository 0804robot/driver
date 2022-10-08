#include "L293.h"
#include "Arduino.h"

L293::L293(int IN1, int IN2, int ENA)
{
    this->_IN1 = IN1;
    this->_IN2 = IN2;
    this->_ENA = ENA;    
    pinMode(this->_IN1, OUTPUT);
    pinMode(this->_IN2, OUTPUT);   
    pinMode(this->_ENA, OUTPUT);   
}
void L293::setMaxSpeed(int max_speed)
{
    this->max_speed = max_speed;
}
void L293::setSpeed(int motor_speed, int direction)
{
    switch (direction)
    {
    case CLOCKWISE:
        digitalWrite(this->_IN1, HIGH);
        digitalWrite(this->_IN2, LOW);
        analogWrite(this->_ENA, motor_speed);
        break;
    case COUNTERCLOCKWISE:
        analogWrite(this->_IN1, LOW);
        analogWrite(this->_IN2, HIGH);
        analogWrite(this->_ENA, motor_speed);
        break;
    default:
        break;
    }
}
void L293::brake(int mode)
{
    if (mode == COAST)
    {
        digitalWrite(this->_IN1, LOW);
        digitalWrite(this->_IN2, LOW);
    }
    else if (mode == BRAKE)
    {
        digitalWrite(this->_IN1, HIGH);
        digitalWrite(this->_IN2, HIGH);
    }
}