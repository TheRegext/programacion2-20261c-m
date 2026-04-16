#include <iostream>
#include <ctime>

#include "figura.h"
#include "cuadrado.h"
#include "circulo.h"
using namespace std;

/// polimorfismo estatico
/// sobrecarga de funciones

/**
   Los objetos se suelen enviar por referencia...
*/

void mostrarArea(const Figura &obj){
   cout << "El area del "<<obj.getTipo()<<" es: " << obj.calcularArea() << endl;
}
/*
void mostrarArea(const Cuadrado &obj){
   cout << "El area del "<<obj.getTipo()<<" es: " << obj.calcularArea() << endl;
}
   
void mostrarArea(const Circulo &obj){
   cout << "El area del "<<obj.getTipo()<<" es: " << obj.calcularArea() << endl;
}
*/

   
int main(){
   srand(time(0));
      
   Figura *figuras[10]{};
   
   for(int i=0; i<10; i++){
      switch(rand()%2){
      case 0:
         figuras[i] = new Circulo(10);
         break;
      case 1:
         figuras[i] = new Cuadrado(10);
         break;
      }
   }
   
   for(int i=0; i<10; i++){
      cout << "La figura es un: " << figuras[i]->getTipo() << endl;
      cout << "El area es: " << figuras[i]->calcularArea() << endl;
   }
   
   for(int i=0; i<10; i++){
      if(figuras[i] != nullptr){
         delete figuras[i];   
      }
   }
   
   
   /*
   Cuadrado cuadrado(10);
   Circulo circulo(5);
   
   Figura &figura = circulo;
   
   mostrarArea(figura);
   */
   /*
   
   
   
   mostrarArea(figura);
   mostrarArea(cuadrado);
   mostrarArea(circulo);*/
   return 0;
}
