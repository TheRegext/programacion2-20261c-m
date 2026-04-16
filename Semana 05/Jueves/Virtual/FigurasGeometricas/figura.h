#pragma once
#include <string>

class Figura {
public:
   std::string getTipo() const;
   virtual float calcularArea() const = 0; /// un metodo polimorfico puro
   
protected:
   void setTipo(std::string tipo);
   
private:
   std::string _tipo;
};

