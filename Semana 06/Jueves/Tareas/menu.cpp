#include <iostream>
#include <cstdio>
#include "menu.h"
using namespace std;

void Menu::run(){
   int opcion;
   do{
      system("cls");
      mostrarOpciones();
      opcion = seleccinarOpcion();
      system("cls");
      ejecutarOpcion(opcion);
      system("pause");
   }while(opcion != 0);
}

int Menu::seleccinarOpcion(){
   int opcion;
   do{
      cout << "Opcion: ";
      cin >> opcion;
      
      if(opcion < 0 || opcion > getCantidadItems()){
         cout << " > Opcion incorrecta!" << endl;
      }
   }while(opcion < 0 || opcion > getCantidadItems());
   
   return opcion;
}

void Menu::setCantidadItems(int cantidad){
   _cantidadItems = cantidad;
}

int  Menu::getCantidadItems(){
   return _cantidadItems;
}


