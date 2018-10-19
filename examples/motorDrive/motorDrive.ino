#include "MotorDrive.h"

MotorDrive motor(8, 9, 10);

void setup()
{ // put your setup code here, to run once:
  motor.begin();
  Serial.begin(9600);
}

void loop()
{ // put your main code here, to run repeatedly:
  unsigned char vel;
  boolean soft;
  if (Serial.available())
  {
    switch (Serial.read())
    {
      case 'A':
        motor.pause();
        break;
      case 'B':
        motor.resume();
        break;
      case 'C':
        motor.stop();
        break;
      case 'D':
        vel = Serial.parseInt();
        soft = Serial.parseInt();
        motor.runClockwise(vel, soft);
        break;
      case 'E':
        vel = Serial.parseInt();
        soft = Serial.parseInt();
        motor.runCounterClockwise(vel, soft);
        break;
    }
    Serial.println(motor.getCurrentSpeed());
  }
}