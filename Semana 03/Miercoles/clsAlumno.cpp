///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;
///clase Fecha
class Fecha{
private:///variables de la clase
    int dia, mes, anio;
public:
    Fecha(int d, int m, int a);
    void setDia(int _dia){
        if(_dia>=1 && _dia<=31)dia=_dia;
    }
    int getDia(){return dia;}
    void Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }
    void Mostrar();///prototipo del m�todo
    void MostrarConBarra();
};

Fecha::Fecha(int d=1, int m=2, int a=3){
    dia=d;
    mes=m;
    anio=a;
}

void Fecha::Mostrar(){
    cout<<"DIA "<<dia<<endl;
    cout<<"MES "<<mes<<endl;
    cout<<"ANIO "<<anio<<endl;
}
void Fecha::MostrarConBarra(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
///Fin clase Fecha

///Clase Alumno
class Alumno{
private:///propiedades
    char nombre[30], apellido[30];
    int legajo;
    Fecha fechaInscripcion;
    Fecha fechaNacimiento;
public:
    void Cargar();
    void Mostrar();
};

void Alumno::Cargar(){
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"LEGAJO ";
    cin>>legajo;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Cargar();
    cout<<"FECHA DE INSCRIPCION ";
    fechaInscripcion.Cargar();
}

void Alumno::Mostrar(){
    cout<<nombre<<" "<<apellido<<endl;
    cout<<"LEGAJO "<<legajo<<endl;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.MostrarConBarra();
    cout<<"FECHA DE INSCRIPCION ";
    fechaInscripcion.MostrarConBarra();
}

///Fin clase Alumno

//ACTIVIDAD PARA QUE HAGAN USTEDES

///Transformar el fuente actual en un proyecto de Codeblock
///en el que cada clase tenga un archivo h para su definición,
///y en un cpp el desarrollo de los métodos

///Para cada clase desarrollar todos los gets() y los sets()

///Luego hacer un programa con el menú;
///1. Cargar alumnos
///2. Mostrar alumnos
///3. Salir del programa

///Desarrollarlo de 2 maneras:
///1. Suponiendo que el curso tiene 10 alumnos
///2. Solicitando al usuario que indique la cantidad de alumnos del curso

///El proyecto puede tener todos los h y cpp que se consideren necesarios


int main(){
    Alumno obj;
    obj.Cargar();
    cout<<endl;
    obj.Mostrar();


	system("pause");
	return 0;

}
