#include "C:\Users\Kevin\Documents\Unahur\Algoritmos\TP\TrabajoPracticoAlgoritmosC2-2025\Headers\Centro.h"

#pragma once

struct NodoCentro
{
  Centro datos;
  NodoCentro *izquierdo;
  NodoCentro *derecho;

  //Constructor 
  NodoCentro(const Centro &nuevoCentro)
      : datos(nuevoCentro) {}
};