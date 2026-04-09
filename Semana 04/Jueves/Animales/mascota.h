#pragma once
#include <string>
#include "animal.h"

class Mascota : public Animal {
public:
   Mascota();
   
   Mascota(std::string nombre, 
           std::string duenio, 
           int edad, 
           float peso, 
           std::string especie);
   
   std::string getNombre();
   void setNombre(std::string nombre);
   
   std::string getDuenio();
   void setDuenio(std::string duenio);
   
   void mostrarInfoMascota();
   
protected:
   std::string _nombre;
   std::string _duenio;
};


