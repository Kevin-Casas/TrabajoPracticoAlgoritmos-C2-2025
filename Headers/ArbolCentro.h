#include "C:\Users\Kevin\Documents\Unahur\Algoritmos\TP\TrabajoPracticoAlgoritmosC2-2025\Headers\NodoCentro.h"
using namespace std;

class ArbolCentro
{
private:
  NodoCentro* raiz;

  void insertarNodoCapacidad(NodoCentro *&nodo, const Centro &centro);
  void insertarNodoEmpleados(NodoCentro *&nodo, const Centro &centro);
  void insertarNodoPaquetes(NodoCentro *&nodo, const Centro &centro);
  void mostrarInorden(NodoCentro *nodo) const;
  void eliminarArbol(NodoCentro *nodo);

public:
  void mostrarInorden() const;
  
  ~ArbolCentro();
};