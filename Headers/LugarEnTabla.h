#include "Centro.h"
#include <string>

using namespace std;

struct LugarEnTabla {
  Centro centro;
  bool estaOcupado = false;
  bool fueBorrado = false;

  LugarEnTabla(Centro centro, bool estaOcupado, bool fueBorrado)
    : centro(centro), estaOcupado(estaOcupado), fueBorrado(fueBorrado) {}
};