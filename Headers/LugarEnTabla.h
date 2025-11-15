#include "Centro.h"
#include <string>

using namespace std;

struct LugarEnTabla {
  Centro centro;
  bool estaOcupado = false;
  bool fueBorrado = false;

  LugarEnTabla(Centro centro, bool estaOcupado, bool fueBorrado)
    : centro(centro), estaOcupado(estaOcupado), fueBorrado(fueBorrado) {}

  //Constructor especial para inicializar la tabla
  LugarEnTabla() : centro("", "", "", 0, 0, 0), estaOcupado(false), fueBorrado(false) {}
};