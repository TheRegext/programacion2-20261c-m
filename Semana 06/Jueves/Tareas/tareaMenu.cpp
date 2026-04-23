#include <iostream>
#include "tareaMenu.h"
#include <cstdio>

using namespace std;

TareaMenu::TareaMenu()
:_managerTarea(){
   setCantidadItems(4);
}

void TareaMenu::mostrarOpciones(){ /// <--- polimorfico (virtual)
   cout << "------- TAREA MENU ---------" << endl;
   cout << "1- CREAR TREA"<<endl;
   cout << "2- MODIFICAR TREA"<<endl;
   cout << "3- ELIMINAR TREA"<<endl;
   cout << "4- LISTAR TREAS"<<endl;
   cout << "0- Salir"<<endl;
   cout << "----------------------------" << endl;
}

void TareaMenu::ejecutarOpcion(int opcion){ /// virual
   switch(opcion){
   case 1:
      _managerTarea.guardar();
      break;
   case 2:
      //_managerTarea.modificar();
      break;
   case 3:
      //_managerTarea.eliminar();
      break;
   case 4:
      _managerTarea.listarTodos();
      break;
   case 0:
      cout << "Saliendo del menu..." << endl;
      break;
   }
}
