#ifndef MANTIS_HPP
#define MANTIS_HPP

#include "Arduino.h"
#include "Servo.h" // Servo library

class Mantis{
    // Mantis' servos
    Servo frontServo;
    Servo rearServo;

    //Average distance value
    int distanceCheck = 0;

    //Servo angles for walking pattern
    int frontRightUp = 70;
    int frontLeftUp = 110;
    int backRightForward = 70;
    int backLeftForward = 110;

    //Center servos
    int centerPos = 90;

    //Another center position
    int centerTurnPos = 81;

    //Servo angles for walking pattern
    int frontTurnRightUp = 70;
    int frontTurnLeftUp = 110;
    int backTurnRightForward = 70;
    int backTurnLeftForward = 110;

    //Array to handle distance values
    int collectDistance[5];
    //Assign analog pin A1
    int sensorPin = A1;

    public:
        Mantis();
        int distance = 0;
        //Distance value for danger close. Bigger values are greater distance and smaller values are lower distance
        int dangerDistance = 350;
        //Time delay between steps
        int walkSpeed = 600;
        
        const void scan();
        const void moveForward();
        const void moveBackRight();
        const void moveTurnLeft();
        const void led();
        const void configure();
        const int getDistance();
}; 

#endif