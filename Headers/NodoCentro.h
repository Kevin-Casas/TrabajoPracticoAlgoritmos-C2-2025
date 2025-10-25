#include "Centro.h"

struct NodoCentro
{
  Centro datos;
  NodoCentro *izquierdo;
  NodoCentro *derecho;

  //Constructor 
  NodoCentro(const Centro &nuevoCentro)
      : datos(nuevoCentro) {}
};