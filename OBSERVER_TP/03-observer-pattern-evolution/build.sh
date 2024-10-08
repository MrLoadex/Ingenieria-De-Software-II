#!/bin/bash

## Borro el directorio bin si ya existiera
if [ -d "./bin" ];
	then rm -r ./bin;
fi

## Creo los directorios para el Binario
mkdir ./bin/

## Compilo el Binario
g++ -Wall -std=c++11 -c ./src/Timer.cpp
g++ -Wall -std=c++11 -c ./src/ChangeManager.cpp
g++ -Wall -std=c++11 -c ./src/AnalogClock.cpp 
g++ -Wall -std=c++11 -c ./src/DigitalClock.cpp
g++ -Wall -std=c++11 -c main.cpp 

g++ Timer.o ChangeManager.o AnalogClock.o DigitalClock.o main.o  -o ./bin/main.bin

## Limpio los códigos objeto
rm ./*.o
