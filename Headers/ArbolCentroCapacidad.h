#include "NodoCentro.h"
using namespace std;

class ArbolCentroCapacidad
{
private:
  NodoCentro* raiz;

  void insertarNodo(NodoCentro *&nodo, const Centro &centro);
  void mostrarInorden(NodoCentro *nodo) const;
  void eliminarArbol(NodoCentro *nodo);

public:
  void mostrarInorden() const;
};