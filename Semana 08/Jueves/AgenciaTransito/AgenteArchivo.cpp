#include "AgenteArchivo.h"
#include <cstdio>

AgenteArchivo::AgenteArchivo()
{
  _ruta = "agentes.dat";
}

AgenteArchivo::AgenteArchivo(std::string ruta)
{
  _ruta = ruta;
}

int AgenteArchivo::getRegistroSize(){
  return sizeof(Agente);
}

Agente AgenteArchivo::leer(int nroRegistro)
{
  Agente aux;
  Archivo::leer(aux, nroRegistro);
  return aux;
}

int AgenteArchivo::buscar(int id)
{
  Agente aux;
  return Archivo::buscar(aux, id);
}
