#include "Centro.h"

#pragma once

struct NodoCentro
{
  Centro datos;
  NodoCentro* izquierdo;
  NodoCentro* derecho;

  //Constructor 
  NodoCentro(const Centro &nuevoCentro)
      : datos(nuevoCentro), izquierdo(nullptr), derecho(nullptr) {}
};