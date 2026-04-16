#pragma once
#include "Fecha.h"
//Para cada libro se registra el número ISBN, el nombre del libro, el nombre del autor, la fecha de publicación, y la cantidad de ejemplares de ese libro que tiene la biblioteca.
//El número ISBN (International Standard Book Number) es un código numérico que identifica de forma única a cada libro publicado.

class Libro{
private:
    int _isbn, _cantEjemplares;
    char _nombreLibro[30], _nombreAutor[30];
    Fecha _fechaPublicacion;
public:
    //CONSTRUCTOR
    Libro();
    Libro(int isbn, int cantEjemplares, char* nombreLibro, char* nombreAutor, Fecha fechaPub);   //GETTERS Y SETTERS

    //SETTERS Y GETTERS
    int getIsbn();
    int getCantEjemp();
    char* getNombreLibro();
    char* getNombreAutor();
    Fecha getFechaPub();

    void setIsbn(int isbn);
    void setCantEjemp(int cantEjemp);
    void setNombreLibro(char* nombreLibro);
    void setNombreAutor(char* nombreAutor);
    void setFechaPub(Fecha fechaPub);

    //METODOS

    void Cargar();
    void Mostrar();
};

