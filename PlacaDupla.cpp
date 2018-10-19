#include "PlacaDupla.h"

void PlacaDupla::begin(unsigned char _in1,
                       unsigned char _in2,
                       unsigned char _in3,
                       unsigned char _in4,
                       unsigned char _in5,
                       unsigned char _in6,
                       unsigned char _in7,
                       unsigned char _in8,
                       unsigned char _enA,
                       unsigned char _enB,
                       unsigned char _enC,
                       unsigned char _enD)
{
    this->motorA = new MotorDrive(_in1, _in2, _enA);
    this->motorA->begin();
    this->motorB = new MotorDrive(_in3, _in4, _enB);
    this->motorB->begin();
    this->motorC = new MotorDrive(_in5, _in6, _enC);
    this->motorC->begin();
    this->motorD = new MotorDrive(_in7, _in8, _enD);
    this->motorD->begin();
}