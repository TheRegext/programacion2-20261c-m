#include "cuadrado.h"

Cuadrado::Cuadrado()
: _lado1(0){
   setTipo("cuadrado");
}

Cuadrado::Cuadrado(float lado)
:Cuadrado(){
   setLado1(lado);
}

float Cuadrado::getLado1() const{
   return _lado1;
}

void Cuadrado::setLado1(float lado){
   _lado1 = lado;
}

float Cuadrado::calcularArea() const{
   return _lado1 * _lado1;
}

