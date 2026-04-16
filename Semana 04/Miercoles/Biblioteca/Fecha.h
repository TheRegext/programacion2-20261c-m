#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
private:///variables de la clase
    int _dia, _mes, _anio;
public:
    //CONSTRUCTOR
    Fecha();
    Fecha(int d, int m, int a);

    //SETTERS Y GETTERS
    void setDia(int dia);
    int getDia();
    void setMes(int mes);
    int getMes();
    void setAnio(int anio);
    int getAnio();

    //METODOS
    void Cargar();
    void Mostrar();///prototipo del metodo
    void MostrarConBarra();
};

#endif // FECHA_H_INCLUDED
