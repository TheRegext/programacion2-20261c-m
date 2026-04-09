#pragma once
#include <string>
#include "mascota.h"

class Pez: public Mascota {
public:
   Pez();
   Pez(int tipoAgua,
       std::string nombre, 
       std::string duenio,
       int edad, 
       float peso);
   
   int getTipoAgua();
   void setTipoAgua(int tipoAgua);
   std::string getTipoAguaNombre();
   
   void nadar();
private:
   int _tipoAgua;
};

