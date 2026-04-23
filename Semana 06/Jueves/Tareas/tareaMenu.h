#pragma once
#include "tareaManager.h"
#include "menu.h"

class TareaMenu: public Menu {
public:
	TareaMenu();
  
private:
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);
   
   TareaManager _managerTarea;
};

