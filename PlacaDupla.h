#ifndef PLACADUPLA_H
#define PLACADUPLA_H
#include "MotorDrive.h"

class PlacaDupla
{

public:
  //Métodos e atributos público
  MotorDrive *motorA;
  MotorDrive *motorB;
  MotorDrive *motorC;
  MotorDrive *motorD;

  void begin(unsigned char _in1,
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
             unsigned char _enD);
};
#endif
