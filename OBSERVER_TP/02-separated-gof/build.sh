#!/bin/bash

## Borro el directorio bin si ya existiera
if [ -d "./bin" ];
	then rm -r ./bin;
fi

## Creo los directorios para el Binario
mkdir ./bin/

## Compilo el Binario
g++ -Wall -std=c++11 -c ./src/AnalogClock.cpp 
g++ -Wall -std=c++11 -c ./src/ClockTimer.cpp
g++ -Wall -std=c++11 -c ./src/DigitalClock.cpp
g++ -Wall -std=c++11 -c ./src/Subject.cpp
g++ -Wall -std=c++11 -c main.cpp 
g++ AnalogClock.o ClockTimer.o DigitalClock.o Subject.o main.o  -o ./bin/main.bin

## Limpio los códigos objeto
rm ./*.o
