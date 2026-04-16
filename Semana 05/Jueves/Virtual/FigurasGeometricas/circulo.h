#pragma once
#include <string>
#include "figura.h"

class Circulo: public Figura {
public:
   Circulo();
   Circulo(float radio);
   
   void setRadio(float radio);
   float getRadio() const;
      
   float calcularArea() const;
   
 
private:
   float _radio;
};


