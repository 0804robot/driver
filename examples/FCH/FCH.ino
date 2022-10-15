#include "FCH.h"
#define RIGHT_MOTOR_SPEED 104
#define LEFT_MOTOR_SPEED 80
#define LEFT_90_TURN_DURATION 640
#define RIGHT_90_TURN_DURATION 500
#define OFFSET_TURN_DURATION 1000
#define OFFSET_STRAIGHT_TURN_DURATION 1000

FCH right(6);
FCH left(5);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    // avoid_obstacle();
    // drive_F(1000);
    // right_turn(RIGHT_90_TURN_DURATION);
    // left_turn(LEFT_90_TURN_DURATION);
    // delay(2000);
}

// To stop, call drive_F(0);
void drive_F(int drive_time)
{
    // Keep drive speed between 0 and 180. 90 being 0 rpm
    right.setSpeed(RIGHT_MOTOR_SPEED);
    left.setSpeed(LEFT_MOTOR_SPEED);
    delay(drive_time);
}

void right_turn(int turn_time)
{                    // Right turn at maximum speed - 0 is maximum speed, 90 is no speed
    right.setSpeed(80); // Both below 90 or below 1500 for microseconds
    left.setSpeed(90);
    delay(turn_time);
    right.setSpeed(90);
    left.setSpeed(90);
}

void left_turn(int turn_time)
{                     // Left turn at maximum speed - 0 is maximum speed, 90 is no speed
    right.setSpeed(90); // Both above 90 or above 1500 for microseconds
    left.setSpeed(100);
    delay(turn_time);
    right.setSpeed(90);
    left.setSpeed(90);
}

void avoid_obstacle()
{
    // Manouvre the first obstacle
    // Turn Left, then trun right, then turn right and back to straight
    left_turn(LEFT_90_TURN_DURATION);
    drive_F(OFFSET_TURN_DURATION);
    right_turn(RIGHT_90_TURN_DURATION);
    drive_F(OFFSET_STRAIGHT_TURN_DURATION);
    right_turn(RIGHT_90_TURN_DURATION);
    drive_F(OFFSET_TURN_DURATION);
    left_turn(LEFT_90_TURN_DURATION);
    drive_F(OFFSET_STRAIGHT_TURN_DURATION);

    // Turn right, then trun left, then turn left and back to straight
    right_turn(RIGHT_90_TURN_DURATION);
    drive_F(OFFSET_TURN_DURATION);
    left_turn(LEFT_90_TURN_DURATION);
    drive_F(OFFSET_STRAIGHT_TURN_DURATION);
    left_turn(LEFT_90_TURN_DURATION);
    drive_F(OFFSET_TURN_DURATION);
    right_turn(RIGHT_90_TURN_DURATION);
    drive_F(OFFSET_STRAIGHT_TURN_DURATION);

    // Turn Left, then trun right, then turn right and back to straight
    left_turn(LEFT_90_TURN_DURATION);
    drive_F(OFFSET_TURN_DURATION);
    right_turn(RIGHT_90_TURN_DURATION);
    drive_F(OFFSET_STRAIGHT_TURN_DURATION);
    right_turn(RIGHT_90_TURN_DURATION);
    drive_F(OFFSET_TURN_DURATION);
    left_turn(LEFT_90_TURN_DURATION);
    drive_F(OFFSET_STRAIGHT_TURN_DURATION);
}
