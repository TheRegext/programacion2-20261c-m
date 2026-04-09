#include <iostream>
#include "mascota.h"

using namespace std;

Mascota::Mascota()
: _nombre("Sin Nombre"), _duenio("Sin duenio"), Animal(){}

Mascota::Mascota(string nombre, 
        std::string duenio, 
        int edad, 
        float peso, 
        string especie)
: Animal(edad, peso, especie){
   setNombre(nombre);
   setDuenio(duenio);
}

string Mascota::getNombre(){
   return _nombre;
}

void Mascota::setNombre(std::string nombre){
   _nombre = nombre;
}

std::string Mascota::getDuenio(){
   return _duenio;
}

void Mascota::setDuenio(std::string duenio){
   _duenio = duenio;
}

void Mascota::mostrarInfoMascota() {
   cout << "Mascota: " << _nombre << " | Duenio: " << _duenio << endl;
}

