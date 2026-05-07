///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>


using namespace std;

class Cadena{
private:
    char *p;
    int tam;
public:
    Cadena(const char *valor);///en constructor pide memoria para armar la cadena
    ~Cadena();
    void Mostrar(){
        cout<<p<<endl;
    }
    bool operator==(Cadena aux);

};

Cadena::Cadena(const char *valor){
    tam=strlen(valor)+1;
    p=new char[tam];
    if(p==nullptr)exit(1);
    strcpy(p,valor);
}

Cadena::~Cadena(){
    delete []p;
}

bool Cadena::operator==(Cadena aux){
    if(strcmp(p,aux.p)==0)return true;
    return false;
}

int main(){
    Cadena palabra("hola"), otra("hola");
    palabra.Mostrar();
    otra.Mostrar();
    if(palabra==otra){
        cout<<"SON IGUALES "<<endl;
    }
    else{
        cout<<"SON DISTINTAS"<<endl;
    }
	system("pause");
	return 0;
}
