#include "LugarEnTabla.h"
#include <iostream>
#include <vector>

using namespace std;

class TablaDeHashing
{

private:
  vector<LugarEnTabla> tablaDeHash;

  // Se asume que ZZZ es el valor de clave maximo y por lo tanto el factor de carga 0.8 seria 338
  int tamanoDeTabla = 338;

  int lugaresOcupados = 0;

  int crearCodigo(const string &codigoDeCentro) const
  {

    // Convertimos el codigo a ascii y sumamos
    int sumaDeCaracteres = 0;

    for (char codigo : codigoDeCentro)
    {
      sumaDeCaracteres += static_cast<int>(codigo);
    }

    return sumaDeCaracteres % tamanoDeTabla;
  }

public:
  void insertarCentro(const Centro &centro)
  {

    int codigoHash = crearCodigo(centro.codigo);

    for (int i = 0; i < tamanoDeTabla; i++)
    {

      //Funcion de colision cuadratica
      int posicion = (codigoHash + 1 * i + 1 * i * i) % tamanoDeTabla;

      if (!tablaDeHash[posicion].estaOcupado || tablaDeHash[posicion].fueBorrado)
      {
        tablaDeHash[posicion].centro = centro;
        tablaDeHash[posicion].estaOcupado = true;
        tablaDeHash[posicion].fueBorrado = false;
        lugaresOcupados++;

        cout << "Centro insertado" << endl;
      }
    }
  };
};