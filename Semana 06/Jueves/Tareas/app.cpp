#include <iostream>
#include "app.h"
#include "tareaMenu.h"

using namespace std;

App::App()
: _menu(nullptr){
	setCantidadItems(1);
}

void App::mostrarOpciones(){ /// <--- polimorfico (virtual)
   cout << "----- MENU PRINCIPAL -------" << endl;
   cout << "1- TREAS"<<endl;
   cout << "0- Salir"<<endl;
   cout << "----------------------------" << endl;
}

void App::ejecutarOpcion(int opcion){ /// virual
   cout << "Opcion: " << opcion << endl;
   switch(opcion){
   case 1:
      mostrarMenu(new TareaMenu);
      break;
   case 0:
      cout << "Saliendo de la aplicacion..." << endl;
      break;
   }
}

void App::mostrarMenu(Menu* menu){
   if(_menu != nullptr){
      delete _menu;
   }
   
   _menu = menu;
   _menu->run();
}
