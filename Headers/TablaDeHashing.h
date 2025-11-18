#include "LugarEnTabla.h"
#include <iostream>
#include <vector>

using namespace std;

class TablaDeHashing
{

private:

  // Se asume que ZZZ es el valor de clave maximo y por lo tanto el factor de carga 0.8 seria 338
  int tamanoDeTabla = 338;
  int lugaresOcupados = 0;

  //Se agregan valores por defecto
  vector<LugarEnTabla> tablaDeHash;

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

  TablaDeHashing() : tablaDeHash(tamanoDeTabla) {}

  void insertarCentro(const Centro &centro)
  {

    int codigoHash = crearCodigo(centro.codigo);

    for (int i = 0; i < tamanoDeTabla; i++)
    {

      // Funcion de colision cuadratica
      // Se eligio la funcion cuadratica por simplicidad y mejor dispersion comparada con la lineal
      int posicion = ((codigoHash + (i * i)) % tamanoDeTabla);

      if (!tablaDeHash[posicion].estaOcupado || tablaDeHash[posicion].fueBorrado)
      {
        tablaDeHash[posicion].centro = centro;
        tablaDeHash[posicion].estaOcupado = true;
        tablaDeHash[posicion].fueBorrado = false;
        lugaresOcupados++;

        cout << "Centro insertado" << endl;
        return;
      }
    }
  };

  void mostrarCentro(const string &codigo)
  {

    int codigoHash = crearCodigo(codigo);

    for (int i = 0; i < tamanoDeTabla; i++)
    {

      int posicion = ((codigoHash + (i * i)) % tamanoDeTabla);
      if (!tablaDeHash[posicion].estaOcupado && tablaDeHash[posicion].fueBorrado)
      {
        continue;
      }
      else if (tablaDeHash[posicion].estaOcupado && tablaDeHash[posicion].centro.codigo == codigo)
      {
        cout << "Nombre " << tablaDeHash[posicion].centro.nombre << endl;
        cout << "Ciudad " << tablaDeHash[posicion].centro.ciudad << endl;
        cout << "Capacidad " << tablaDeHash[posicion].centro.capacidad << endl;
        cout << "Paquetes diarios " << tablaDeHash[posicion].centro.paquetes_diarios << endl;
        cout << "Empleados " << tablaDeHash[posicion].centro.empleados << endl;
        return;
      };
    }; 
    cout << "Centro no encontrado" << endl;
  };

  void eliminarCentro(const string &codigo) {

    int codigoHash = crearCodigo(codigo);

    for(int i = 0; i < tamanoDeTabla; i++) {
      
      int posicion = ((codigoHash + (i * i)) % tamanoDeTabla);

      if(tablaDeHash[posicion].estaOcupado && tablaDeHash[posicion].centro.codigo == codigo) {
        tablaDeHash[posicion].estaOcupado = false;
        tablaDeHash[posicion].fueBorrado = true;
        lugaresOcupados--;
        cout << "Centro eliminado" << endl;
        return;
      }
    }
    cout << "Centro no encontrado" << endl;
  };
};