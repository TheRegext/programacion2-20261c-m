#include <iostream>
#include <limits>
#include <string>

#include "AgenteManager.h"

using namespace std;

void AgenteManager::Cargar() {
  int idAgente;
  string apellidos;
  string nombres;
  int anioIngreso;
  int categoria;
  float sueldo;

  cout << "\n=== ALTA DE AGENTE ===\n";

  cout << "ID Agente: ";
  cin >> idAgente;

  if (ExisteId(idAgente)) {
    cout << "Ya existe un agente con ese ID." << endl;
    return;
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Apellidos: ";
  getline(cin, apellidos);

  cout << "Nombres: ";
  getline(cin, nombres);

  cout << "Anio de ingreso: ";
  cin >> anioIngreso;

  cout << "Categoria: ";
  cin >> categoria;

  cout << "Sueldo: ";
  cin >> sueldo;

  Agente nuevo(idAgente, apellidos, nombres, anioIngreso, categoria, sueldo);

  if (_archivo.guardar(nuevo)) {
    cout << "Agente guardado correctamente." << endl;
  }
  else {
    cout << "No se pudo guardar el agente." << endl;
  }
}

void AgenteManager::ListarTodos() {
  cout << "\n=== LISTADO DE AGENTES ===\n";

  int cantidadRegistros = _archivo.getCantidadRegistros();
  if (cantidadRegistros == 0) {
    cout << "No hay agentes cargados." << endl;
    return;
  }

  for (int i = 0; i < cantidadRegistros; i++) {
    Agente reg = _archivo.leer(i);
    cout << "------------------------------"<<endl;
    Listar(reg);
  }
}

void AgenteManager::ListarXId() {
  int id;

  cout << "\n=== BUSQUEDA POR ID ===\n";
  cout << "Ingrese ID: ";
  cin >> id;

  int posicion = _archivo.buscar(id);
  if (posicion >= 0) {
    Agente reg = _archivo.leer(posicion);
    Listar(reg);
  }
  else {
    cout << "No existe agente con ID #" << id << endl;
  }
}

void AgenteManager::Listar(Agente agente) {
  cout << "ID: " << agente.getIdAgente() << endl
       << "Apellido y Nombre: " << agente.getApellidos() << ", " << agente.getNombres() <<  endl
       << "Anio Ingreso: " << agente.getAnioIngreso() <<  endl
       << "Categoria: " << agente.getCategoria() <<  endl
       << "Sueldo: " << agente.getSueldo() << endl;
}

bool AgenteManager::ExisteId(int id) {
  return _archivo.buscar(id) >= 0;
}
