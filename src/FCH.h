/*
 * FCH.h - FCH library for Wiring/Arduino - Version 1.0.0
 *
 * Original library        (1.0.0)   by Rodney Osodo.
 *
 * The moded the FCH motor driver can run are listed below:
 *      Servo       Mode
 *        90        Stop /Break
 *        0         Maximum forward speed
 *        180       Maximum reverse speed
 *
 */

#ifndef SRC_FCH_H_
#define SRC_FCH_H_
#if defined(ESP32) 
  #include <ESP32Servo.h>
#else 
  #include <Servo.h>
#endif
class FCH
{
private:
    // motor pin numbers
    int _motor_pin;
    Servo _motor;

public:
    /** Creates a FCH(motor controller) control interface to drive 1 motor
     *
     * @param motor A GPIO pin, tied to the individual motor
     *
     */
    FCH(int motor);

    /** Set the speed of the motor
     *
     * @param motor_speed The speed of the motor as a normalised value between 0 and 180 with 90 being zero speed
     */
    void setSpeed(int motor_speed);

    /** Brake the H-bridge coast or brake.
     *
     * Defaults to coast.
     *
     */
    void brake();
};

#endif // SRC_FCH_H_
