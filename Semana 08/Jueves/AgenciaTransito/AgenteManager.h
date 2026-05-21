#ifndef AGENTEMANAGER_H
#define AGENTEMANAGER_H

#include "Agente.h"
#include "AgenteArchivo.h"

class AgenteManager {
public:
  void Cargar();
  void ListarTodos();
  void ListarXId();
  void Listar(Agente agente);

private:
  AgenteArchivo _archivo;

  bool ExisteId(int id);
};

#endif
