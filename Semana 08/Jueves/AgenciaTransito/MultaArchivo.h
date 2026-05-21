#pragma once
#include "Archivo.h"
#include "Multa.h"
#include <string>

class MultaArchivo: public Archivo
{
public:
    
  Multa leer(int nroRegistro);
  void leer(Multa *vec, int cantidad);
  int buscar(int ID);
  
  MultaArchivo();
  MultaArchivo(std::string ruta);
protected:
  int getRegistroSize() override;
  
};
