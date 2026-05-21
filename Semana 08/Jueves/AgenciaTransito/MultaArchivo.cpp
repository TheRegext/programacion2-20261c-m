#include "MultaArchivo.h"
#include <cstdio>

MultaArchivo::MultaArchivo()
{
  _ruta = "multas.dat";
}

MultaArchivo::MultaArchivo(std::string ruta)
{
  _ruta = ruta;
}

Multa MultaArchivo::leer(int nroRegistro)
{
  Multa aux;
  Archivo::leer(aux, nroRegistro);
  return aux;
}

int MultaArchivo::buscar(int id)
{
  Multa aux;
  return Archivo::buscar(aux, id);
}

void MultaArchivo::leer(Multa *vec, int cantidad){
  Archivo::leer(vec, cantidad);
}

int MultaArchivo::getRegistroSize(){
  return sizeof(Multa);
}
