#include<iostream>
#include "animal.h"
#include "mascota.h"
#include "pez.h"

using namespace std;


int main () {
   Pez a(1, "Dori", "Mateo", 25, 30);
 
   //a.setEspecie("Perro");   
   
   a.mostrarInfoBiologica();     
   
   a.comer();
   
   a.mostrarInfoMascota();
   
   a.nadar();
   
	
	return 0;
}

