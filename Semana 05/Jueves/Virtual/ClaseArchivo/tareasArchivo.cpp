#include <stdio.h>
#include "tareasArchivo.h"

TareasArchivo::TareasArchivo(std::string nombreArchivo)
:_nombreArchivo(nombreArchivo){}

bool TareasArchivo::guardar(const Tarea &reg){
   FILE *pFile;
   int cant;
   
   pFile = fopen(_nombreArchivo.c_str(), "ab");
   
   if(pFile == nullptr){
      return false;
   }
   
   cant = fwrite(&reg, sizeof (Tarea), 1, pFile);
   
   fclose(pFile);
   
   return cant;
}


Tarea TareasArchivo::leer(int pos){
   Tarea reg;
   FILE *pFile;
   
   pFile = fopen(_nombreArchivo.c_str(), "rb");
   reg.setId(-1);
   
   if(pFile == nullptr){
      return reg;
   }
   
   fseek(pFile, pos * sizeof (Tarea), SEEK_SET);
   
   fread(&reg, sizeof (Tarea), 1, pFile);
   
   fclose(pFile);
   
   return reg;
}

int TareasArchivo::getCantidadRegistros(){
   FILE *pFile;
   int tamTotal;
   
   pFile = fopen(_nombreArchivo.c_str(), "rb");
   
   if(pFile == nullptr){
      return 0;
   }
   
   fseek(pFile, 0, SEEK_END);
   
   tamTotal = ftell(pFile) / sizeof(Tarea);
   
   fclose(pFile);
   
   return tamTotal;
}

int TareasArchivo::getNuevoId(){
   return getCantidadRegistros() + 1;
}


