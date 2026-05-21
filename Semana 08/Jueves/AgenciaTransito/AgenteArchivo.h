#pragma once

#include "Agente.h"
#include "Archivo.h"
#include <string>

class AgenteArchivo: public Archivo
{
public:
  Agente leer(int nroRegistro);
  int buscar(int ID);
  
  AgenteArchivo();
  AgenteArchivo(std::string ruta);
protected:
  int getRegistroSize() override;
};
