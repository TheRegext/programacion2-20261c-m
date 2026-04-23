#include <iostream>

#include "tareaManager.h"
#include "tarea.h"
#include "utils.h"

using namespace std;

TareaManager::TareaManager()
:_repoTarea(){
   
}

Tarea TareaManager::cargarTarea(){
   int id = _repoTarea.getNuevoId();
   string titulo;
   Fecha fechaCreacion;
   fechaCreacion.setCurrentDate();
   
   cout << "Numero de Tarea: #" << id << endl;
   cout << "Ingrese Titulo: ";
   titulo = cargarCadena();
   
   return Tarea(id, titulo, 1, fechaCreacion); /// crea un objeto anonimo
}

void TareaManager::guardar(){
   Tarea reg = cargarTarea();
   if(_repoTarea.guardar(reg)){
      cout << "Tarea guardada correctamente" << endl;
   }
   else{
      cout << "Ocurrio un error al guardar la tarea." << endl;
   }
}

void TareaManager::listarTodos(){
   int cantidad = _repoTarea.getCantidadRegistros();
   
   for(int i=0; i<cantidad; i++){
      Tarea reg = _repoTarea.leer(i);
      cout << "-----------------------"<<endl;
      cout << "ID #" << reg.getId() << endl;
      cout << "Tarea: " << reg.getTitulo() << endl;  
      cout << "Creacion: " << reg.getFechaCreacion().getDia() 
         << "/" << reg.getFechaCreacion().getMes() 
         << "/" << reg.getFechaCreacion().getAnio() << endl;
   }
}

