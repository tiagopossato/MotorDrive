#ifndef MOTORDRIVE_H
#define MOTORDRIVE_H
#include "Arduino.h"

typedef enum Direction
{
	CW = 0,
	CCW,
	PAUSE,
	STOP
} Direction;

//Definição da classe
class MotorDrive
{

  public:
	//Métodos e atributos públicos
	MotorDrive(
		unsigned char _pinA,
		unsigned char _pinB,
		unsigned char _speedPin);
	void begin();
	//Gira o motor no sentido horário, com partida suave
	void runClockwise(unsigned char speed, bool softStarter);
	//Gira o motor no sentido horário, sem partida suave
	void runClockwise(unsigned char speed);
	//Gira o motor no sentido anti horário
	void runCounterClockwise(unsigned char speed);
	//Gira o motor no sentido anti horário, com partida suave
	void runCounterClockwise(unsigned char speed, bool softStarter);
	//Para o motor
	void stop();
	//Pausa o motor
	void pause();
	//Retoma o funcionamento do motor após uma pausa
	void resume();
	//Retorna a velocidade atual do motor
	unsigned char getCurrentSpeed();

  private:
	//Métodos e atributos privados
	unsigned char pinA;
	unsigned char pinB;
	unsigned char speedPin;
	unsigned char currentSpeed;
	boolean isPaused;
	Direction currentDirection;
	void run(unsigned char speed, bool softStarter, Direction direction);
};
#endif
