#include "pez.h"
#include <iostream>

using namespace std;

Pez::Pez()
   :_tipoAgua(1), Mascota(){
   setEspecie("Pez");
}

Pez::Pez(int tipoAgua,
    std::string nombre, 
    std::string duenio,
    int edad, 
    float peso)
:Mascota(nombre, duenio, edad, peso, "Pez"){
   setTipoAgua(tipoAgua);
}

int Pez::getTipoAgua(){
   return _tipoAgua;
}

void Pez::setTipoAgua(int tipoAgua){
   if(tipoAgua == 1 || tipoAgua == 2){
      _tipoAgua = tipoAgua;
   }
   else{
      _tipoAgua = 1;
   }
}

std::string Pez::getTipoAguaNombre(){
   switch(_tipoAgua){
   case 1:
      return "Dulce";
      break;
   case 2:
      return "Salada";
      break;
   }
   
   return "Sin Espesificar";
}


void Pez::nadar(){
   cout << "El pez "<< _nombre <<" nadando en el agua " << getTipoAguaNombre() << endl;

}
