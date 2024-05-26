#!/bin/bash
#Preparo directorios y recursos
mkdir ./build
mkdir ./build/lib

cp ./test/libtest/readme.txt ./build/lib
cp ./test/libtest/libtest.sh ./build/lib
cp -r ./resources/lang/ ./build/

##Compilo las librerías
g++ -Wall -std=c++11 -fPIC -I./include/ -c ./src/LangReader.cpp
g++ -Wall -std=c++11 -fPIC -I./include/ -c ./src/LanguageManagerModule.cpp
g++ -shared -Wall -std=c++11 -fPIC -I./include/ LangReader.o LanguageManagerModule.o -o ./build/lib/LanguageManagerModule.so

## Compilo el Binario
g++ -Wall -std=c++11 -ldl -I./include -I./include/vendors/cppset/ main.cpp -o ./build/app.bin 

## Borro código objeto
rm ./*.o

## Permisos de Ejecución para el binario
chmod +x ./build/app.bin

## Ejecuto el binario:
cd build/
./app.bin