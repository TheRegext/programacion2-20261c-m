///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring>

using namespace std;


class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(int d=0,int m=0, int a=0);
    void Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }
    void Mostrar();
    void cambiarDia(int d){
        if(d>=1 && d<=31) dia=d;
        else dia=0;
        }
    void setMes(const int m){mes=m;}
    void setAnio(const int a){anio=a;}
    int getDia()const {return dia;};
    int getMes(){return mes;}
    int getAnio(){return anio;}
    ///sobrecargas
    bool operator==(const Fecha &aux);
    bool operator==(const char *m);
    void operator+=(int cantDias);
    friend void soyAmiga(Fecha &aux);
    friend istream & operator>>(istream &entrada, Fecha &aux);
    friend ostream & operator<<(ostream &salida, Fecha &aux);
};


void soyAmiga(Fecha &aux){
    aux.dia=29;
    aux.mes=4;
    aux.anio=2026;
}

///MUTABILIDAD: CAPACIDAD DE CAMBIAR
///sobrecargas

istream & operator>>(istream &entrada, Fecha &aux){
    cout<<"DIA ";
    entrada>>aux.dia;
    cout<<"MES ";
    entrada>>aux.mes;
    cout<<"ANIO ";
    entrada>>aux.anio;
    return entrada;
}

ostream & operator<<(ostream &salida, Fecha &aux){
    cout<<"DIA ";
    salida<<aux.dia<<endl;
    cout<<"MES ";
    salida<<aux.mes<<endl;
    cout<<"ANIO ";
    salida<<aux.anio<<endl;
    return salida;
}

bool Fecha::operator==(const Fecha &aux){
   /// cout<<"VALOR DE this "<<this<<endl;
   /// cout<<"DIRECCION DE aux "<<&aux<<endl;
   /// system("pause");
    if(dia!=aux.dia) return false;
    if(mes!=aux.mes) return false;
    if(anio!=aux.anio) return false;
    return true;
}


bool Fecha::operator==(const char *m){
    char meses[3][11]={"ENERO", "FEBRERO", "MARZO"};
    if(strcmp(m,meses[mes-1])==0) return true;
    return false;
}

void Fecha::operator+=(int cantDias){
    ///convierten las fechas en un valor númerico entero (número de serie). 1->1 de enero de 1900, 365 1/1/1901
    int diasMeses[12]={31,28,31,30};
    ///ver si el año es bisiesto para cambiar el 28 por el 29 diasMeses[1]=29
    dia+=cantDias;
}

void Fecha::Mostrar(){
        cout<<"DIA "<<dia<<endl;
        cout<<"MES "<<mes<<endl;
        cout<<"ANIO "<<anio<<endl;
}




Fecha::Fecha(int d,int m, int a){
    dia=d;
    mes=m;
    anio=a;
}


int main(){
    Fecha obj1(28,2,2026), obj2;
    ///obj1.Cargar();
   ///cout<<"obj1 "<<&obj1<<endl;
   ///cout<<"obj2 "<<&obj2<<endl<<endl;
    ///if(obj1.operator==(obj2)){
    /*if(obj1==obj2){
            cout<<"LAS FECHAS SON IGUALES "<<endl;
    }
    else{
        cout<<"LAS FECHAS SON DISTINTAS"<<endl;
    }*/
/*	if(obj1=="ENERO"){
        cout<<"LA FECHA ES DEL MES DE ENERO "<<endl;
	}
	else{
        cout<<"LA FECHA NO ES DEL MES DE ENERO "<<endl;
	}
	obj1+=2;///quiero que la fecha se incrementa 2 días*/
	//soyAmiga(obj1);
	//obj1.Mostrar();
	cin>>obj1;
	cout<<obj1<<endl;
	system("pause");
	return 0;

}


///Sobrecargar el operador > de manera tal que sea verdadero cuando la fecha que llama es mas actual que la que
///se recibe como parámetro

///Sobrecargar el operador != para que sea verdadero cuando las fechas son distintas

///Sobrecargar el operador == para que compare un objeto Fecha con la fechar de nacimiento de un objeto Alumno
