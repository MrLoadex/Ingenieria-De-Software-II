:: Borro el directorio de binarios si ya existiera
IF EXIST .\bin RMDIR /S /Q .\bin

:: Creo los directorios para el binario y las bibliotecas
MD .\bin

:: Compilo el Binario
g++ -Wall -std=c++11 -c .\src\AnalogClock.cpp 
g++ -Wall -std=c++11 -c .\src\ClockTimer.cpp
g++ -Wall -std=c++11 -c .\src\DigitalClock.cpp
g++ -Wall -std=c++11 -c .\src\Subject.cpp
g++ -Wall -std=c++11 -c main.cpp 
g++ AnalogClock.o ClockTimer.o DigitalClock.o Subject.o main.o  -o .\bin\main.exe

:: Limpio los códigos objeto
DEL .\*.o
