#pragma once

class Menu {
public:
   void run();
   
protected:
   void setCantidadItems(int cantidad);
   int getCantidadItems();
   
private:
   virtual void mostrarOpciones() = 0;
   virtual void ejecutarOpcion(int opcion) = 0;

   int seleccinarOpcion();
   int _cantidadItems;
};



