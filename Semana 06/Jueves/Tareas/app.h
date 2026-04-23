#pragma once
#include "menu.h"

class App: public Menu {
public:
   App();
   
private:
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);
   
   void mostrarMenu(Menu* menu);
   
   Menu* _menu;
};

