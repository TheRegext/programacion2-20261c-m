#include "Archivo.h"

Archivo::Archivo()
{
  //ctor
}

int Archivo::getCantidadRegistros()
{
  FILE *p = fopen(_ruta.c_str(), "rb");

  if (p == NULL)
  {
    return 0;
  }

  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);

  return bytes / getRegistroSize();
}

bool Archivo::guardar(Registro &reg)
{
  FILE *p = fopen(_ruta.c_str(), "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&reg, getRegistroSize(), 1, p);
  fclose(p);
  return pudoEscribir;
}

bool Archivo::guardar(Registro& reg, int posicionAReemplazar)
{
  FILE *p = fopen(_ruta.c_str(), "rb+");

  if (p == NULL)
  {
    return false;
  }

  fseek(p, posicionAReemplazar * getRegistroSize(), SEEK_SET);
  bool pudoEscribir = fwrite(&reg, getRegistroSize(), 1, p);
  fclose(p);
  return pudoEscribir;
}


bool Archivo::guardar(Registro *vec, int cantidadRegistrosAEscribir)
{
  FILE *p = fopen(_ruta.c_str(), "ab");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, getRegistroSize(), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

void Archivo::leer(Registro &reg, int nroRegistro)
{
  FILE *p = fopen(_ruta.c_str(), "rb");
  if (p == NULL)
  {
    return;
  }

  fseek(p, nroRegistro * getRegistroSize(), SEEK_SET);
  fread(&reg, getRegistroSize(), 1, p);
  fclose(p);
}

void Archivo::leer(Registro *vec, int cantidadRegistrosALeer)
{
  FILE *p = fopen(_ruta.c_str(), "rb");
  if (p == NULL)
  {
    return ;
  }

  fread(vec, getRegistroSize(), cantidadRegistrosALeer, p);
  fclose(p);
}


int Archivo::buscar(Registro& reg, int id)
{
  int cant = 0;
  FILE *p = fopen(_ruta.c_str(), "rb");
  if (p == NULL)
  {
    return -1;
  }

  while(fread(&reg, getRegistroSize(), 1, p))
  {
    if(reg.getID() == id)
    {
      fclose(p);
      return cant;
    }
    cant++;
  }
  fclose(p);

  return -1;
}

void Archivo::vaciar(){
  FILE *p = fopen(_ruta.c_str(), "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}






