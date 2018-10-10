#include "MotorDrive.h"

MotorDrive::MotorDrive(
    unsigned char _pinA,
    unsigned char _pinB,
    unsigned char _speedPin)
{
#warning "Compilando aqui"
  pinA = _pinA;
  pinB = _pinB;
  speedPin = _speedPin;
}

void MotorDrive::begin()
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(speedPin, OUTPUT);
  direction[0] = LOW;
  direction[1] = LOW;
  currentSpeed = 0;
  setDirection(direction[0], direction[1]);
  setSpeed(currentSpeed, false);
}

void MotorDrive::setDirection(unsigned char statePinA, unsigned char statePinB)
{
  digitalWrite(pinA, statePinA);
  digitalWrite(pinB, statePinB);
}

void MotorDrive::setSpeed(unsigned char speed, bool softStarter)
{
  char speedDiference = currentSpeed - speed;
  unsigned char i;

  if(!softStarter){
	  currentSpeed = speed;	
	  analogWrite(speedPin, currentSpeed);
	  return;
  }
  //acelera o motor até a nova velocidade
  if (speedDiference != 0)
  {
    for (i = 0; i < abs(speedDiference); i++)
    {
      if (speedDiference < 0) //acelerando
      {
        currentSpeed++;
      }
      else
      {
        currentSpeed--;
      }
      analogWrite(speedPin, currentSpeed);
      delay(4);
    }
  }
}

void MotorDrive::runClockwise(unsigned char speed, bool softStarter)
{
  direction[0] = HIGH;
  direction[1] = LOW;
  setDirection(direction[0], direction[1]);
  setSpeed(speed, softStarter);
}

void MotorDrive::runClockwise(unsigned char speed)
{
  this->runClockwise(speed, false);
}

void MotorDrive::runAntiClockwise(unsigned char speed, bool softStarter)
{
  direction[0] = LOW;
  direction[1] = HIGH;
  setDirection(direction[0], direction[1]);
  setSpeed(speed, softStarter);
}

void MotorDrive::runAntiClockwise(unsigned char speed)
{
  this->runAntiClockwise(speed, false);
}

void MotorDrive::stop()
{
  setSpeed(0, false);
  direction[0] = LOW;
  direction[1] = LOW;
  setDirection(direction[0], direction[1]);
}

void MotorDrive::pause()
{
	setDirection(LOW, LOW);
}

void MotorDrive::resume()
{
  setDirection(direction[0], direction[1]);
}

unsigned char MotorDrive::getCurrentSpeed()
{
  return currentSpeed;
}
