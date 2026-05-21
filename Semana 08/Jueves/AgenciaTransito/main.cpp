#include <iostream>
#include <limits>
#include "AgenteManager.h"
#include "MultaManager.h"

using namespace std;

int main(){
  AgenteManager agenteManager;
  MultaManager multaManager;
  int opcion;

  do {
    cout << "\n==============================\n";
    cout << "  MENU AGENCIA DE TRANSITO\n";
    cout << "==============================\n";
    cout << "1) Alta de agente\n";
    cout << "2) Busqueda por ID\n";
    cout << "3) Listado de agentes\n";
    cout << "==============================\n";
    cout << "4) Buscar multa por ID\n";
    cout << "5) Listar multas\n";
    cout << "==============================\n";
    cout << "0) Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      opcion = -1;
    }

    switch (opcion) {
      case 1:
        agenteManager.Cargar();
        break;
      case 2:
        agenteManager.ListarXId();
        break;
      case 3:
        agenteManager.ListarTodos();
        break;
      case 4:
        multaManager.ListarXId();
        break;
      case 5:
        multaManager.ListarTodos();
        break;
      case 0:
        cout << "Saliendo...\n";
        break;
      default:
        cout << "Opcion invalida.\n";
        break;
    }

  } while (opcion != 0);

  return 0;
}
