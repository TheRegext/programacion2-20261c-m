#include <iostream>

using namespace std;

int main()
{
  int codigoProducto, numeroSucursal, cantidadVendida;
  int cantidades[5][20] = {};
  
  cout << "Ingrese codigo de producto: ";
  cin >> codigoProducto;

  while(codigoProducto != 0)
  {
    cout << "Ingrese numero de sucursal: ";
    cin >> numeroSucursal;

    cout << "Ingrese cantidad vendida: ";
    cin >> cantidadVendida;
    
    cantidades[numeroSucursal-1][codigoProducto-1] += cantidadVendida;

    cout << "Ingrese codigo de producto: ";
    cin >> codigoProducto;
  }
  
  
  for(int i=0; i<5; i++){ /// recorremos las sucursales
    cout << "Sucursal #" << i + 1 << endl;
    
    int maxi = 0;
    for(int j=1; j<20; j++){ /// recorrer los productos
      if(cantidades[i][j] > cantidades[i][maxi]){
        maxi = j;      
      }    
    }
    
    if(cantidades[i][maxi] > 0){
      cout << "El producto mas vendido es: " << maxi + 1 << " con cantidad " << cantidades[i][maxi]  << endl;
    }
    else{
      cout << "No hay ventas para esta sucursarl." << endl;
    }
    
    cout << endl;
    
  }

  return 0;
}
