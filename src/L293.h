/*
 * L293.h - L293 library for Wiring/Arduino - Version 1.0.0
 *
 * Original library        (1.0.0)   by Rodney Osodo.
 *
 * The moded the L293 motor driver can run are listed below:
 *
 *    x_OUT x_OUT    Mode
 *      0     0      Coast/Fast decay
 *      0     1      Reverse
 *      1     0      Forward
 *      1     1      X
 */

#ifndef SRC_L293_H_
#define SRC_L293_H_
#include <Arduino.h>
#if defined(ESP32) 
  #include <analogWrite.h>
#endif

#define COAST 1
#define BRAKE 0
#define CLOCKWISE 1
#define COUNTERCLOCKWISE 0

class L293
{
private:
    // The maximum value for an analogWrite(pin, value). This varies from board to board
    int max_speed = 255;

    // motor pin numbers
    int _IN1;
    int _IN2;
    int _ENA;

public:
    /** Creates a L293(H-bridge motor controller) control interface to drive 1 motor
     *
     * @param IN1 A GPIO pin, tied to the IN1 Logic input and controls state of OUT1
     * @param IN2 A GPIO pin, tied to the IN2 Logic input and controls state of OUT2
     * @param ENA A PWM enabled pin, tied to the ENA Logic input and controls speed of the motor
     *
     */
    L293(int IN1, int IN2, int ENA);

    /** Set the maximum speed the motor can run
     *
     * @param max_speed The maximum speed value for an analogWrite(value);
     */
    void setMaxSpeed(int max_speed);

    /** Set the speed of the motor
     *
     * @param motor_speed The speed of the motor as a normalised value between 0 and max_speed
     */
    void setSpeed(int motor_speed, int direction);

    /** Brake the H-bridge coast or brake.
     *
     * Defaults to coast.
     *
     */
    void brake(int mode);
};

#endif // SRC_L293_H_
