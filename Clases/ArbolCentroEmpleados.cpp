#include "ArbolCentroEmpleados.h"
#include <iostream>

using namespace std;

// Ingresa nodo al arbol de acuerdo a su cantidad de empleados
void ArbolCentroEmpleados::insertarNodo(NodoCentro *&nodo, const Centro &centroAInsertar)
{

  if (nodo == nullptr)
  {
    nodo = new NodoCentro(centroAInsertar);

    // Si la capacidad es menor o igual se guarda el centro en el nodo izquierdo
  }
  else if (centroAInsertar.empleados <= nodo->datos.empleados)
  {
    insertarNodo(nodo->izquierdo, centroAInsertar);
    // Caso contrario se guarda en el nodo derecho
  }
  else
  {
    insertarNodo(nodo->derecho, centroAInsertar);
  }
}

void ArbolCentroEmpleados::mostrarInorden(NodoCentro *nodo) const
{

  if (nodo == nullptr)
  {
    return;
  }

  mostrarInorden(nodo->izquierdo);
  cout << nodo->datos.codigo << " " << nodo->datos.nombre << " " << nodo->datos.ciudad << " " << nodo->datos.empleados << endl;
  mostrarInorden(nodo->derecho);
}

ArbolCentroEmpleados::~ArbolCentroEmpleados() {
  eliminarArbol(raiz);
}

//Eliminamos el arbol para liberar la memoria
void ArbolCentroEmpleados::eliminarArbol(NodoCentro* nodo) {
  if (nodo == nullptr) {
    return;
  }
  eliminarArbol(nodo->izquierdo);
  eliminarArbol(nodo->derecho);
  delete nodo;
}
