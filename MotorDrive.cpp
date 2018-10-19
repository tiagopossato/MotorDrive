#include "MotorDrive.h"
MotorDrive::MotorDrive(unsigned char _pinA, unsigned char _pinB, unsigned char _speedPin)
{
  pinA = _pinA;
  pinB = _pinB;
  speedPin = _speedPin;
}

void MotorDrive::begin()
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(speedPin, OUTPUT);
  currentSpeed = 0;
  currentDirection = Direction::PAUSE;
  run(currentSpeed, false, currentDirection);
}

void MotorDrive::run(unsigned char speed, bool softStarter, Direction direction)
{
  int speedDiference;
  unsigned char i;
  isPaused = false;

  switch (direction)
  {
  case Direction::CW:
    if (currentDirection == Direction::CCW)
    {
      currentSpeed = 0;
      analogWrite(speedPin, 0);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      delay(500);
    }
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    break;
  case Direction::CCW:
    if (currentDirection == Direction::CW)
    {
      currentSpeed = 0;
      analogWrite(speedPin, 0);
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      delay(500);
    }
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    break;
  case Direction::PAUSE:
    analogWrite(speedPin, 0);
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    return;
    break;
  case Direction::STOP:
    currentSpeed = 0;
    analogWrite(speedPin, 0);
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    delay(500);
    return;
    break;
  }

  currentDirection = direction;
  speedDiference = currentSpeed - speed;

  if (!softStarter)
  {
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
  run(speed, softStarter, Direction::CW);
}

void MotorDrive::runClockwise(unsigned char speed)
{
  this->runClockwise(speed, false);
}

void MotorDrive::runCounterClockwise(unsigned char speed, bool softStarter)
{
  run(speed, softStarter, Direction::CCW);
}

void MotorDrive::runCounterClockwise(unsigned char speed)
{
  this->runCounterClockwise(speed, false);
}

void MotorDrive::stop()
{
  run(0, false, Direction::STOP);
}

void MotorDrive::pause()
{
  unsigned char tmp = currentSpeed;
  Direction dirTmp = currentDirection;
  run(0, false, Direction::PAUSE);
  currentDirection = dirTmp;
  currentSpeed = tmp;
  isPaused = true;
}

void MotorDrive::resume()
{
  if (isPaused)
  {
    unsigned char tmp = currentSpeed;
    currentSpeed = 0;
    run(tmp, true, currentDirection);
    currentSpeed = tmp;
  }
}

unsigned char MotorDrive::getCurrentSpeed()
{
  if (isPaused)
    return 0;
  return currentSpeed;
}
