#include "mantis.hpp"

Mantis::Mantis(){}

const void Mantis::scan(){
    for (int i{}; i < 5; ++i){
        distanceCheck = analogRead(sensorPin);
        collectDistance[i] = distanceCheck;
        distance += collectDistance[i];
    }

    distance = distance/5;
    delay(20);
    
}

const void Mantis::moveForward(){
    for (int f{}; f < 39; ++f){
        frontRightUp++;
        backLeftForward--;
        frontServo.write(frontRightUp);
        rearServo.write(backLeftForward);
        delay(10);  
    }

    for (int r{}; r < 39; ++r){
        frontRightUp--;
        backLeftForward++;
        frontServo.write(frontRightUp);
        rearServo.write(backLeftForward);
        delay(10);
    }
}

const void Mantis::moveBackRight(){
    frontServo.write(frontRightUp);
    rearServo.write(backRightForward - 6);
    delay(150);
    frontServo.write(centerPos);
    rearServo.write(centerPos-6);
    delay(120);
    frontServo.write(frontLeftUp+9);
    rearServo.write(backLeftForward-6);
    delay(150);
    frontServo.write(centerPos);
    rearServo.write(centerPos);
    delay(120);
}

const void Mantis::moveTurnLeft(){
    frontServo.write(frontTurnRightUp);
    rearServo.write(backTurnLeftForward);
    delay(150);
    frontServo.write(centerTurnPos);
    rearServo.write(centerTurnPos);
    delay(120);
    frontServo.write(frontTurnLeftUp);
    rearServo.write(backTurnRightForward);
    delay(150);
    frontServo.write(centerTurnPos);
    rearServo.write(centerTurnPos);

    delay(120);

}

const void Mantis::led(){
    for (int l{}; l <= 5; ++l){
        digitalWrite(13, HIGH);
        delay(50);
        digitalWrite(13, LOW);
        delay(100);
    }
}

const void Mantis::configure(){
    frontServo.attach(2);
    rearServo.attach(4);
    pinMode(sensorPin, INPUT);
    frontServo.write(centerPos);
    rearServo.write(centerPos);
    
}

const int Mantis::getDistance(){
    return distance;
}

