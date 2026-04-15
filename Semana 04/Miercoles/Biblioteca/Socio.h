#pragma once
# include "Fecha.h"


///Por cada uno de los socios registra el DNI, el nombre, el apellido, un número de teléfono, un email y la fecha de nacimiento.


class Socio{

private:
    char _dni [8];
    char _nombre [30];
    char _apellido[30];
    char _telefono[14];
    char _email[50];
    Fecha _fechaNac;

public:
    //CONSTRUCTOR
    Socio();
    Socio(char* dni, char* nombre, char* apellido, char* telefono, char* email, Fecha fechaNac);

    //GETTERS Y SETTERS
    char* getDni();
    char* getNombre();
    char* getApellido();
    char* getTelefono();
    char* getEmail();
    Fecha getFechaNac();

    void setDni(char* dni);
    void setNombre(char* nombre);
    void setApellido(char* apellido);
    void setTelefono(char* telefono);
    void setEmail(char* email);
    void setFechaNac(Fecha fechaNac);

    //METODOS

    void Cargar();
    void Mostrar();
};
