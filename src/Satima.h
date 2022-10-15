/*
 * Satima.h - Satima library for Wiring/Arduino - Version 1.0.0
 *
 * Original library        (1.0.0)   by Rodney Osodo.
 *
 * The moded the satima motor driver can run are listed below:
 *
 *    x_PWM1 x_PWM2    Mode
 *      0      0       Coast/Fast decay
 *      0      1       Reverse
 *      1      0       Forward
 *      1      1       Brake/slow decay
 */

#ifndef SRC_SATIMA_H_
#define SRC_SATIMA_H_

#if defined(ESP32) 
  #include <analogWrite.h>
#else 
  #include <Arduino.h>
#endif

#define COAST 1
#define BRAKE 0
#define CLOCKWISE 1
#define COUNTERCLOCKWISE 0

class Satima
{
private:
    // The maximum value for an analogWrite(pin, value). This varies from board to board
    int max_speed = 255;

    // motor pin numbers
    int _motor_pin_1;
    int _motor_pin_2;

public:
    /** Creates a Satima(H-bridge motor controller) control interface to drive 1 motor
     *
     * @param motor_pin_1 A PWM enabled pin, tied to the IN1 Logic input and controls state of OUT1
     * @param motor_pin_2 A PWM enabled pin, tied to the IN2 Logic input and controls state of OUT2
     *
     */
    Satima(int motor_pin_1, int motor_pin_2);

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
     * @param mode - Braking mode.COAST(default)or BRAKE.
     *
     */
    void brake(int mode);
};

#endif // SRC_SATIMA_H_
