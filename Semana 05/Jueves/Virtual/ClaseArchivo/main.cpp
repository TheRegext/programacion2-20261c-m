#include<iostream>
#include "tarea.h"
#include "tareasArchivo.h"

using namespace std;

int main () {
   TareasArchivo ta;
   Tarea t;
   string titulo;
   int id = ta.getNuevoId();
   
   cout << "Tarea #" << id << endl;
   cout << "Ingrese nombre de la tarea: ";
   getline(cin, titulo);
   
   t.setId(id);
   t.setTitulo(titulo);
   
   ta.guardar(t);
   
   
   
   int cantidad = ta.getCantidadRegistros();

   for(int i=0; i<cantidad; i++){
      Tarea t2 = ta.leer(i);   
      cout << "Titulo: " << t2.getTitulo() << endl;
   }
   
   
   
	   
   /// cout << << endl;
	return 0;
}

