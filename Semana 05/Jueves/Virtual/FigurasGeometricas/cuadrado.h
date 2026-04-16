#pragma once
#include <string>
#include "figura.h"


class Cuadrado: public Figura {
public:
   Cuadrado();
   Cuadrado(float lado);
   
   float getLado1() const;
   void setLado1(float lado);
   
   /// polimorfismo estatico (sobrecarga)
   float calcularArea() const;  /// polimorfismo dinamico (sobreescritura)
 
private:
   float _lado1;
};

