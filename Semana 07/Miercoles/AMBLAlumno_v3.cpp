///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring>

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
    void Mostrar();///prototipo del método
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
    char _nombre[30], _apellido[30];
    int _legajo;
    Fecha _fechaInscripcion;
    Fecha _fechaNacimiento;
    bool _estado;
public:
    int getLegajo();
    bool getEstado();

    void setLegajo(int legajo);
    void setEstado(bool estado);
    void setNombre(const char *nombre){
        strcpy(_nombre,nombre);
    }
    void Cargar();
    void Mostrar();
};


void Alumno::setLegajo(int legajo){
        if(legajo>0){
            _legajo=legajo;
        }
    }

int Alumno::getLegajo(){
        return _legajo;
    }

void Alumno::setEstado(bool estado){
    _estado=estado;
}

bool Alumno::getEstado(){
    return _estado;
}

void Alumno::Cargar(){
    int auxLegajo;
    cout<<"NOMBRE: ";
    cin>>_nombre;
    cout<<"APELLIDO: ";
    cin>>_apellido;
    cout<<"LEGAJO: ";
    cin>>auxLegajo;
    setLegajo(auxLegajo);
    cout<<"FECHA DE NACIMIENTO: ";
    _fechaNacimiento.Cargar();
    cout<<"FECHA DE INSCRIPCION: ";
    _fechaInscripcion.Cargar();
    _estado=true;
}

void Alumno::Mostrar(){
    cout<<_nombre<<" "<<_apellido<<endl;
    cout<<"LEGAJO "<<_legajo<<endl;
    cout<<"FECHA DE NACIMIENTO ";
    _fechaNacimiento.MostrarConBarra();
    cout<<"FECHA DE INSCRIPCION ";
    _fechaInscripcion.MostrarConBarra();
    cout<<"ESTADO: "<<_estado<<endl;
}

///Fin clase Alumno



class archivoAlumno{
private:
    char _nombre[30];
public:
    //CONSTRUCTOR
    archivoAlumno(const char* nombre="alumnos.dat", bool vacio=false);

    //METODOS
    bool grabarRegistro(Alumno obj);
    bool bajaLogicaRegistro(int legajo);
    int buscarLegajo(int legajo);
    Alumno leerRegistro(int pos);
    bool sobreEscribirRegistro(Alumno reg, int pos);
    void listarActivos();
    void listar();
    int contarRegistros();
};

archivoAlumno::archivoAlumno(const char* nombre, bool vacio){
    strcpy(_nombre,nombre);
    if(vacio){
        FILE *p=fopen(nombre, "wb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            exit(1);
        }
        fclose(p);
    }
}


bool archivoAlumno::grabarRegistro(Alumno obj){
    FILE *pAlu;

    pAlu=fopen(_nombre,"ab");

    if(pAlu==nullptr){

        return false;
    }

    bool escribio=fwrite(&obj, sizeof obj, 1,pAlu);

    fclose(pAlu);

    return escribio;

}

bool archivoAlumno::sobreEscribirRegistro(Alumno reg, int pos){
    FILE *pAlu=fopen(_nombre, "rb+");///+ le agrega al modo lo que le falta

    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return false;
    }

    fseek(pAlu,pos*sizeof reg,0);

    bool escribio=fwrite(&reg, sizeof reg, 1, pAlu);

    fclose(pAlu);

    return escribio;
}


int archivoAlumno::buscarLegajo(int legajo){
    Alumno reg;
    int posicion=0;
    FILE *pAlu=fopen(_nombre, "rb");

    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return -1;
    }

    while(fread(&reg, sizeof reg, 1, pAlu)==1){
        if(legajo==reg.getLegajo()){
            fclose(pAlu);
            return posicion;
        }
        posicion++;
    }

    fclose(pAlu);

    return -1;
}


Alumno archivoAlumno::leerRegistro(int pos){
    Alumno reg;

    FILE *pAlu=fopen(_nombre, "rb");

    if(pAlu==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        //reg.setLegajo(-2);
        return reg;
    }

    fseek(pAlu,pos*sizeof reg,0); ///SEEK_SET->0 PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL; SEEK_END->2 FINAL DEL ARCHIVO

    fread(&reg, sizeof reg, 1, pAlu);

    fclose(pAlu);

    return reg;
}

bool archivoAlumno::bajaLogicaRegistro(int legajo){
    Alumno reg;

    int pos=buscarLegajo(legajo);

    if(pos==-1){
        cout<<"EL LEGAJO NO EXISTE "<<endl;
        system("pause");
        return false;
    }

    reg=leerRegistro(pos);

    reg.setEstado(false);

    return sobreEscribirRegistro(reg, pos);
}



void archivoAlumno::listar(){
    Alumno obj;
    FILE *pAlu;

    pAlu=fopen(_nombre,"rb");

    if(pAlu==nullptr){
        //cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, sizeof obj, 1,pAlu)!=0){
        obj.Mostrar();
        cout<<endl;
    }

    fclose(pAlu);
}

void archivoAlumno::listarActivos(){
    Alumno obj;
    FILE *pAlu;

    pAlu=fopen(_nombre,"rb");

    if(pAlu==nullptr){
        //cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, sizeof obj, 1,pAlu)!=0){
        if(obj.getEstado()){
            obj.Mostrar();
        }
        cout<<endl;
    }

    fclose(pAlu);
}

int archivoAlumno::contarRegistros(){
    FILE *p;
    p=fopen(_nombre,"rb");
    if(p==nullptr) return -1;
    fseek(p,0,2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof(Alumno);
}

///funciones globales prototipos
void agregarRegistro();
void eliminarRegistro();
void modificarNombre();
void modificarApellido(){}
//void listarRegistros();
void menuModificarRegistro();
void menuListados();
void listarSecuencial();
void listarPorApellido();
///fin globales prototipos
void tengoValoresPorOmision(int x=10, int y=20){
    cout<<"x "<<x<<endl;
    cout<<"y "<<y<<endl;
}

int main(){
  //  archivoAlumno archi("alumnos.dat", true);
/*    tengoValoresPorOmision();
    cout<<endl;
    tengoValoresPorOmision(1,2);
    return 0;*/
    int opc;
    while(true){
        system("cls");
        cout<<"****MENU ALUMNOS****"<<endl;
        cout<<"1. ALTA"<<endl;
        cout<<"2. BAJA"<<endl;
        cout<<"3. MODIFICACION"<<endl;
        cout<<"4. LISTADO"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"********************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistro();
                    break;
            case 2: eliminarRegistro();
                    break;
            case 3: menuModificarRegistro();
                break;
            case 4: menuListados();
                    break;
            case 0: return 0;
                    break;
            default:cout<<"OPCION INCORRECTA"<<endl;
                    break;

        }
        system("pause");

    }

    return 0;
}


void agregarRegistro(){
    Alumno reg;
    archivoAlumno archiAlu;
    reg.Cargar();///OJO!!! QUE NO HAY VALIDACIONES
    if(archiAlu.grabarRegistro(reg)==true) cout<<"REGISTRO AGREGADO";
    else cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    cout<<endl;
}

void eliminarRegistro(){
    archivoAlumno archiAlu;
    Alumno reg;
    int legajo;
    cout<<"INGRESAR EL LEGAJO DEL REGISTRO A BORRAR ";
    cin>>legajo;
    int pos=archiAlu.buscarLegajo(legajo);
    if(pos==-1){
        cout<<"NO EXISTEN REGISTROS CON ESE LEGAJO"<<endl;
        return;
    }
    reg=archiAlu.leerRegistro(pos);
    reg.setEstado(false);
    if(archiAlu.sobreEscribirRegistro(reg,pos)) cout<<"REGISTRO BORRADO";
    else cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
    cout<<endl;
}
void modificarNombre(){
    archivoAlumno archiAlu;
    Alumno reg;
    int legajo;
    cout<<"INGRESAR EL LEGAJO DEL REGISTRO A MODIFICAR ";
    cin>>legajo;
    int pos=archiAlu.buscarLegajo(legajo);
    if(pos==-1){
        cout<<"NO EXISTEN REGISTROS CON ESE LEGAJO"<<endl;
        return;
    }
    reg=archiAlu.leerRegistro(pos);
    char nombre[30];
    cout<<"INGRESAR EL NOMBRE NUEVO ";
    cin>>nombre;
    reg.setNombre(nombre);
    if(archiAlu.sobreEscribirRegistro(reg,pos)) cout<<"REGISTRO MODIFICADO";
    else cout<<"NO SE PUDO BORRAR EL REGISTRO";

    cout<<endl;

}

void listarSecuencial(){
    archivoAlumno archiAlu;
    archiAlu.listarActivos();
}

void menuModificarRegistro(){
    int opc;
    while(true){
        system("cls");
        cout<<"****MENU MODIFICACION****"<<endl;
        cout<<"1. MODIFICAR NOMBRE"<<endl;
        cout<<"2. MODIFICAR APELLIDO"<<endl;
        cout<<"0. VOLVER AL MENU ANTERIOR"<<endl;
        cout<<"********************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: modificarNombre();
                    break;
            case 2: modificarApellido();
                    break;
            case 0: return;
                    break;
            default:cout<<"OPCION INCORRECTA"<<endl;
                    break;

        }
        system("pause");

    }
}

void menuListados(){
    int opc;
    while(true){
        system("cls");
        cout<<"****MENU LISTADOS****"<<endl;
        cout<<"1. LISTADO SECUENCIAL"<<endl;
        cout<<"2. LISTADO ORDENADO POR APELLIDO"<<endl;
        cout<<"0. VOLVER AL MENU ANTERIOR"<<endl;
        cout<<"********************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: listarSecuencial();
                    break;
            case 2: listarPorApellido();
                    break;
            case 0: return;
                    break;
            default:cout<<"OPCION INCORRECTA"<<endl;
                    break;

        }
        system("pause");

    }
}

void listarPorApellido(){
    Alumno *pAlumno;
    archivoAlumno archiAlu;
    int cantReg=archiAlu.contarRegistros();
    if(cantReg<=0){
        cout<<"EL ARCHIVO NO TIENE REGISTROS "<<endl;
        return;
    }
    pAlumno=new Alumno[cantReg];
    if(pAlumno==nullptr){
        cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
        return;
    }
    int i;
    for(i=0;i<cantReg;i++){
        pAlumno[i]=archiAlu.leerRegistro(i);
    }

    ///ordenarVectorAlumnos(pAlumno, cantReg);
    for(i=0;i<cantReg;i++){
        pAlumno[i].Mostrar();
        cout<<endl;
    }
    delete []pAlumno;
}

///Hacer la función que ordene el vector de alumnos

///Agregar en el menú de modificaciones una opción para modificar la fecha de nacimiento
///Agregar en el menú de listados una opción para listar los alumnos que se inscribieron en un año
/// que se ingresa por teclado
