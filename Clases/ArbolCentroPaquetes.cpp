#include "C:\Users\Kevin\Documents\Unahur\Algoritmos\TP\TrabajoPracticoAlgoritmosC2-2025\Headers\ArbolCentroPaquetes.h"
#include <iostream>

using namespace std;

// Ingresa nodo al arbol de acuerdo a la cantidad de paquetes diarios
void ArbolCentroPaquetes::insertarNodo(NodoCentro *&nodo, const Centro &centroAInsertar)
{

  if (nodo == nullptr)
  {
    nodo = new NodoCentro(centroAInsertar);

    // Si la capacidad es menor o igual se guarda el centro en el nodo izquierdo
  }
  else if (centroAInsertar.paquetes_diarios <= nodo->datos.paquetes_diarios)
  {
    insertarNodo(nodo->izquierdo, centroAInsertar);
    // Caso contrario se guarda en el nodo derecho
  }
  else
  {
    insertarNodo(nodo->derecho, centroAInsertar);
  }
}

void ArbolCentroPaquetes::mostrarInorden(NodoCentro *nodo) const
{

  if (nodo == nullptr)
  {
    return;
  }

  mostrarInorden(nodo->izquierdo);
  cout << nodo->datos.codigo << " " << nodo->datos.nombre << " " << nodo->datos.ciudad << " " << nodo->datos.paquetes_diarios << endl;
  mostrarInorden(nodo->derecho);
}

ArbolCentroPaquetes::~ArbolCentroPaquetes() {
  eliminarArbol(raiz);
}

//Eliminamos el arbol para liberar la memoria
void ArbolCentroPaquetes::eliminarArbol(NodoCentro* nodo) {
  if (nodo == nullptr) {
    return;
  }
  eliminarArbol(nodo->izquierdo);
  eliminarArbol(nodo->derecho);
  delete nodo;
}
