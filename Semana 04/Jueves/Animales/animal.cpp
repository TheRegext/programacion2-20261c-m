#include <iostream>
#include "animal.h"

using namespace std;

/// Lista de inicializacion
/// Cuando quieren llamar a un constructor de una composicion
Animal::Animal()
: _edad(0), _peso(0), _especie("Sin definir"){}

Animal::Animal(int edad, float peso, string especie){
   setEdad(edad);
   setPeso(peso);
   setEspecie(especie);
}

int Animal::getEdad(){
   return _edad;
}

void Animal::setEdad(int edad){
   if(edad >= 0){
      _edad = edad;
   }
   else{
      _edad = 0;
   }
}

float Animal::getPeso(){
   return _peso;
}

void Animal::setPeso(float peso){
   if(peso >= 0){
      _peso = peso;
   }
   else{
      /// en los set no se ponene cout
      /// excepcion
      _peso = 0;
   }
}

string Animal::getEspecie(){
   return _especie;   
}

void Animal::setEspecie(string especie){
   _especie = especie;
}

void Animal::mostrarInfoBiologica(){
   cout << "Especie: " << _especie << " | Peso: " << _peso << " kg | Edad: " << _edad << " anios"  << endl;
}

void Animal::comer(){
   cout << "El animal esta comiendo para sobrevivir." << endl;
}
