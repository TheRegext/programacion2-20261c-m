#pragma once
#include <string>
#include "tarea.h"

class TareasArchivo {
public:
	TareasArchivo(std::string nombreArchivo = "tareas.dat");
   
   bool guardar(const Tarea &reg);
   Tarea leer(int pos);
   int getCantidadRegistros();
   int getNuevoId();
   
private:
   std::string _nombreArchivo;
};

