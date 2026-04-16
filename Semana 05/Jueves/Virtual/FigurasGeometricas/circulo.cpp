#define _USE_MATH_DEFINES

#include "circulo.h"
#include <cmath>

Circulo::Circulo()
: _radio(0){
   setTipo("circulo");
}

Circulo::Circulo(float radio)
: Circulo(){
   setRadio(radio);
}

void Circulo::setRadio(float radio){
   _radio = radio;
}

float Circulo::getRadio() const{
   return _radio;
}
   
float Circulo::calcularArea() const{
   return M_PI * _radio * _radio;
}

