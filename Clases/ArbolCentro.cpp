#include "C:\Users\Kevin\Documents\Unahur\Algoritmos\TP\TrabajoPracticoAlgoritmosC2-2025\Headers\ArbolCentro.h"
#include <iostream>

using namespace std;

// Ingresa nodo al arbol de acuerdo a su capacidad
void ArbolCentro::insertarNodoCapacidad(NodoCentro *&nodo, const Centro &centroAInsertar)
{

  if (nodo == nullptr)
  {
    nodo = new NodoCentro(centroAInsertar);

    // Si la capacidad es menor o igual se guarda el centro en el nodo izquierdo
  }
  else if (centroAInsertar.capacidad <= nodo->datos.capacidad)
  {
    insertarNodoCapacidad(nodo->izquierdo, centroAInsertar);
    // Caso contrario se guarda en el nodo derecho
  }
  else
  {
    insertarNodoCapacidad(nodo->derecho, centroAInsertar);
  }
}

// Ingresa nodo al arbol de acuerdo a la cantidad de empleados
void ArbolCentro::insertarNodoEmpleados(NodoCentro *&nodo, const Centro &centroAInsertar)
{

  if (nodo == nullptr)
  {
    nodo = new NodoCentro(centroAInsertar);

    // Si la capacidad es menor o igual se guarda el centro en el nodo izquierdo
  }
  else if (centroAInsertar.empleados <= nodo->datos.empleados)
  {
    insertarNodoCapacidad(nodo->izquierdo, centroAInsertar);
    // Caso contrario se guarda en el nodo derecho
  }
  else
  {
    insertarNodoCapacidad(nodo->derecho, centroAInsertar);
  }
}

// Ingresa nodo al arbol de acuerdo a la cantidad de paquetes del centro
void ArbolCentro::insertarNodoPaquetes(NodoCentro *&nodo, const Centro &centroAInsertar)
{

  if (nodo == nullptr)
  {
    nodo = new NodoCentro(centroAInsertar);

    // Si la capacidad es menor o igual se guarda el centro en el nodo izquierdo
  }
  else if (centroAInsertar.paquetes_diarios <= nodo->datos.paquetes_diarios)
  {
    insertarNodoCapacidad(nodo->izquierdo, centroAInsertar);
    // Caso contrario se guarda en el nodo derecho
  }
  else
  {
    insertarNodoCapacidad(nodo->derecho, centroAInsertar);
  }
}

void ArbolCentro::mostrarInordenCapacidad(NodoCentro *nodo) const
{

  if (nodo == nullptr)
  {
    return;
  }

  mostrarInordenCapacidad(nodo->izquierdo);
  cout << nodo->datos.codigo << " " << nodo->datos.nombre << " " << nodo->datos.ciudad << " " << nodo->datos.capacidad << endl;
  mostrarInordenCapacidad(nodo->derecho);
}

void ArbolCentro::mostrarInordenEmpleados(NodoCentro *nodo) const
{

  if (nodo == nullptr)
  {
    return;
  }

  mostrarInordenEmpleados(nodo->izquierdo);
  cout << nodo->datos.codigo << " " << nodo->datos.nombre << " " << nodo->datos.ciudad << " " << nodo->datos.empleados << endl;
  mostrarInordenEmpleados(nodo->derecho);
}

void ArbolCentro::mostrarInordenPaquetes(NodoCentro *nodo) const
{

  if (nodo == nullptr)
  {
    return;
  }

  mostrarInordenPaquetes(nodo->izquierdo);
  cout << nodo->datos.codigo << " " << nodo->datos.nombre << " " << nodo->datos.ciudad << " " << nodo->datos.paquetes_diarios << endl;
  mostrarInordenPaquetes(nodo->derecho);
}

ArbolCentro::~ArbolCentro() {
  eliminarArbol(raiz);
}

//Eliminamos el arbol para liberar la memoria
void ArbolCentro::eliminarArbol(NodoCentro* nodo) {
  if (nodo == nullptr) {
    return;
  }
  eliminarArbol(nodo->izquierdo);
  eliminarArbol(nodo->derecho);
  delete nodo;
}
