// Servo Library 
#include "mantis.hpp"

Mantis mantis;

void setup()
{
  mantis.configure();

}
// that's the loop. This is repeatedly called as long as the robot is powered on
void loop()
{
  mantis.scan();
  if (mantis.distance > 1){
    if (mantis.distance > mantis.dangerDistance){
      mantis.led();
      for (int y=0; y <= 3; y++){
        mantis.moveBackRight();
        delay(mantis.walkSpeed);
      }

      for (int z=0; z <= 3; z++){
        mantis.moveTurnLeft();
        delay(mantis.walkSpeed);
      }
      
    }else{
      mantis.moveForward();
      delay(mantis.walkSpeed / 100);
    }
  }
}
