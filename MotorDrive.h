#ifndef MOTORDRIVE_H
#define MOTORDRIVE_H
#include "Arduino.h"

//Definição da classe
class MotorDrive
{
  public:
	//Métodos e atributos público

	//Construtor da classe
	MotorDrive(
		unsigned char _pinA,
		unsigned char _pinB,
		unsigned char _speedPin);
	//Inicializador
	void begin();
	//Gira o motor no sentido horário, com partida suave
	void runClockwise(unsigned char speed, bool softStarter);
	//Gira o motor no sentido horário, sem partida suave
	void runClockwise(unsigned char speed);
	//Gira o motor no sentido anti horário
	void runAntiClockwise(unsigned char speed);
	//Gira o motor no sentido anti horário, com partida suave
	void runAntiClockwise(unsigned char speed, bool softStarter);

	//Para o motor
	void stop();
	void pause();
	void resume();
	unsigned char getCurrentSpeed();

  private:
	//Métodos e atributos privados
	unsigned char pinA;
	unsigned char pinB;
	unsigned char speedPin;
	bool direction[2];
	unsigned char currentSpeed;
	//Altera
	void setDirection(unsigned char statePinA, unsigned char statePinB);
	//altera a velocidade do motor
	void setSpeed(unsigned char speed, bool softStarter);
};
#endif
