///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

void mostrarVectorOrdenado(int *v, int tam);

int main(){
    char letra1='a';
    char letra2='z';

    cout<<letra2-letra1<<endl;

    cout<<(int)letra1<<endl;
    cout<<(int)letra2<<endl;
    if(letra1==97){
        cout<<"VALOR ASCII DE a"<<97<<endl;
    }
	for(int i=97;i<=122;i++){
        cout<<(char)i<<endl;
	}
	system("pause");
	return 0;

}

bool mostrarVectorOrdenado(int *v, int tam){
    int *vecAux;
    vecAux=new int[tam];
    if(vecAux==nullptr){return false;}
    copiarVector(vecAux,v,tam);
    ordenarVector(vecAux,tam);
    mostrarVector(vecAux,tam);
}
