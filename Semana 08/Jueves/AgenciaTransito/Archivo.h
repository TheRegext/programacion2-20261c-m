#pragma once
#include <string>
#include "Registro.h"

class Archivo
{
  public:
    Archivo();
    int getCantidadRegistros();
    
    bool guardar(Registro& reg);
    bool guardar(Registro& reg, int posicionAReemplazar);
    bool guardar(Registro *vec, int cantidadRegistrosAEscribir);
    
    void leer(Registro &reg, int nroRegistro);
    void leer(Registro *vec, int cantidadRegistrosALeer);
    int buscar(Registro& reg, int id);
    void vaciar();


  protected:
    virtual int getRegistroSize() = 0; /// interface
    std::string _ruta;
};
