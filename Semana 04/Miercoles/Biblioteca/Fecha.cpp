# include<iostream>
# include<cstring>
# include "Fecha.h"

using namespace std;

Fecha::Fecha(){
    _dia=0;
    _mes=0;
    _anio=0;
}

Fecha::Fecha(int d=1, int m=2, int a=3){
    setDia(d);
    setMes(m);
    setAnio(a);
}

void Fecha::setDia(int dia){
    if(dia>=1 && dia<=31){
        _dia =dia;
    }
}

int Fecha::getDia(){
    return _dia;
}

void Fecha::setMes(int mes){
    if(mes>=1 && mes<=12){
        _mes=mes;
    }
}

int Fecha::getMes(){
    return _mes;
}

void Fecha::setAnio(int anio){
    if(anio<=1930 && anio>=2030){
        _anio=anio;
    }
}

void Fecha::Cargar(){
        cout<<"DIA ";
        cin>>_dia;
        cout<<"MES ";
        cin>>_mes;
        cout<<"ANIO ";
        cin>>_anio;
    }
void Fecha::Mostrar(){
    cout<<"DIA "<<_dia<<endl;
    cout<<"MES "<<_mes<<endl;
    cout<<"ANIO "<<_anio<<endl;
}
void Fecha::MostrarConBarra(){
    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}
