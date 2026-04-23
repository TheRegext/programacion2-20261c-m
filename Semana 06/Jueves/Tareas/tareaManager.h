#pragma once
#include "tareaArchivo.h"
#include "tarea.h"

class TareaManager {
public:
	TareaManager();
   
   void guardar();
   void listarTodos();
   
private:
   Tarea cargarTarea();
   TareaArchivo _repoTarea;
};
