#include <cstring>
#include "tarea.h"


Tarea::Tarea()
: _id(0), _titulo(""), _realizado(false){}

Tarea::Tarea(int id, std::string titulo, bool realizado){
   setId(id);
   setTitulo(titulo);
   setRealizado(realizado);
}

int Tarea::getId() const{
   return _id;
}

void Tarea::setId(int id){
   _id = id;
}

bool Tarea::getRealizado() const{
   return _realizado;
}

void Tarea::setRealizado(bool realizado){
   _realizado = realizado;
}

std::string Tarea::getTitulo() const{
   /// return _titulo; /// conversion implicita
   return std::string(_titulo);
}

void Tarea::setTitulo(std::string titulo){
   if(titulo.size() < 100){
      strcpy(_titulo, titulo.c_str());   
   }
   else{
      /// dispare un excepcion
      strcpy(_titulo, "Texto fuera de rango");   
   }
}
