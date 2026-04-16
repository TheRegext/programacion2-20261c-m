#pragma once
#include <string>

class Tarea {
public:
	Tarea();
   Tarea(int id, std::string titulo, bool realizado);
   
   int getId() const;
   void setId(int id);
   
   bool getRealizado() const;
   void setRealizado(bool realizado);
   
   std::string getTitulo() const;
   void setTitulo(std::string titulo);
   
   
private:
   int _id;
   bool _realizado;
   char _titulo[100];
};



