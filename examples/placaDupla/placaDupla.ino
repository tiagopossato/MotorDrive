#include "PlacaDupla.h"

PlacaDupla placa;

void setup(){
    placa.begin(2,3,4,5,6,7,8,9,10,11,12,13);
}

void loop(){
    placa.motorA->runClockwise(255);
}