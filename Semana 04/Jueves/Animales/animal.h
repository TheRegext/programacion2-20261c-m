#pragma once
#include <string>

class Animal {
public:
   Animal();
   Animal(int edad, float peso, std::string especie);
   
   int getEdad();
   void setEdad(int edad);
   
   float getPeso();
   void setPeso(float peso);
   
   void mostrarInfoBiologica();
   void comer();
   
protected:
   std::string getEspecie();
   void setEspecie(std::string especie);
   
private:
   int _edad;
   std::string _especie;
   float _peso;
};


