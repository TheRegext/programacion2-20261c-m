# include<iostream>
# include<cstring>
# include "Libro.h"

using namespace std;

    //CONSTRUCTOR
    Libro::Libro(){
        _isbn=0;
        _cantEjemplares=0;
        strcpy(_nombreLibro, "nada");
        strcpy(_nombreAutor, "nada");
        _fechaPublicacion=Fecha(0,0,0);

    }
    Libro::Libro(int isbn, int cantEjemplares, char* nombreLibro, char* nombreAutor, Fecha fechaPub){
        setIsbn(isbn);
        setCantEjemp(cantEjemplares);
        setNombreLibro(nombreLibro);
        setNombreAutor(nombreAutor);
        setFechaPub(fechaPub);
    }

    //SETTERS Y GETTERS
    int Libro::getIsbn(){
        return _isbn;
    }
    int Libro::getCantEjemp(){
        return _cantEjemplares;
    }
    char* Libro::getNombreLibro(){
        return _nombreLibro;
    }
    char* Libro::getNombreAutor(){
        return _nombreAutor;
    }
    Fecha Libro::getFechaPub(){
        return _fechaPublicacion;
    }

    void Libro::setIsbn(int isbn){
        _isbn=isbn;
    }
    void Libro::setCantEjemp(int cantEjemp){
        _cantEjemplares=cantEjemp;
    }
    void Libro::setNombreLibro(char* nombreLibro){
        strcpy(_nombreLibro,nombreLibro);
    }
    void Libro::setNombreAutor(char* nombreAutor){
        strcpy(_nombreAutor, nombreAutor);
    }
    void Libro::setFechaPub(Fecha fechaPub){
        _fechaPublicacion=fechaPub;
    }

    //METODOS

    void Libro::Cargar(){
    }
    void Libro::Mostrar(){
    }
