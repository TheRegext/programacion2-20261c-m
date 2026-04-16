# include<iostream>
# include<cstring>
# include "Socio.h"

using namespace std;

//CONSTRUCTOR
Socio::Socio(){
    strcpy(_dni,"nada");
    strcpy(_nombre, "nada");
    strcpy(_apellido, "nada");
    strcpy (_telefono, "nada");
    strcpy(_email, "nada");
    _fechaNac=Fecha(0,0,0);
}
Socio::Socio(char* dni, char* nombre, char* apellido, char* telefono, char* email, Fecha fechaNac){
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setFechaNac(fechaNac);

//    strcpy(_dni,dni);
//    strcpy(_nombre, nombre);
//    strcpy(_apellido, apellido);
//    strcpy (_telefono, telefono);
//    strcpy(_email, email);
//    _fechaNac=fechaNac;
}

//GETTERS Y SETTERS
char* Socio::getDni(){
}
char* Socio::getNombre(){
}
char* Socio::getApellido(){
}
char* Socio::getTelefono(){
}
char* Socio::getEmail(){
}
Fecha Socio::getFechaNac(){
}
void Socio::setDni(char* dni){
}
void Socio::setNombre(char* nombre){
}
void Socio::setApellido(char* apellido){
}
void Socio::setTelefono(char* telefono){
}
void Socio::setEmail(char* email){
}
void Socio::setFechaNac(Fecha fechaNac){
}

//METODOS

void Socio::Cargar(){

}
void Socio::Mostrar(){
    cout<<"Dni: "<<_dni<<endl;
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Apellido: "<<_apellido<<endl;
    cout<<"Telefono: "<<_telefono<<endl;
    cout<<"Email: "<<_email<<endl;
    cout<<"Fecha Nacimiento: "<<endl;
    _fechaNac.Mostrar();
}
