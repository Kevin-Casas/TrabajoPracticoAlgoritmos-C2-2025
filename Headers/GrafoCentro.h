#include "Centro.h"
#include "Conexion.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class GrafoCentro {

  private:

  vector<Centro> centros;
  //Para usar el codigo de los centros como indices
  unordered_map<string, int> claves;
  vector<vector<pair<int,int>>> matrizDeAdyacencias;

  public:
  
  void agregarCentro(const Centro& centro) {
    claves[centro.codigo] = centros.size();
    centros.push_back(centro);
    matrizDeAdyacencias.push_back({});
  }

  void agregarConexion(const Conexion& conexion) {

    int centroOrigenClave = claves[conexion.centro_origen];
    int centroDestinoClave = claves[conexion.centro_destino];

    matrizDeAdyacencias[centroOrigenClave].push_back({centroDestinoClave, conexion.distancia});
  }

  vector<int> caminoMinimo(const string& codigo) {

    int cantidadDeCentros = centros.size();
    int centroInicialClave = claves[codigo];

    vector<int> distancias(cantidadDeCentros, 9999);
    distancias[centroInicialClave] = 0;


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> colaDePrioridad;

    colaDePrioridad.push({0, centroInicialClave});

    while(!colaDePrioridad.empty()) {

      auto colaTop = colaDePrioridad.top();
      int distanciaActual = colaTop.first;
      int centroActual = colaTop.second;
      colaDePrioridad.pop();

      if(distanciaActual > distancias[centroActual]) {
        continue;
      }

      for (const auto& par : matrizDeAdyacencias[centroActual]) {

        int centroAdyacente = par.first;
        int distanciaConexion = par.second;

        if (distancias[centroActual] + distanciaConexion < distancias[centroAdyacente]) {

          distancias[centroAdyacente] = distancias[centroActual] + distanciaConexion;
          colaDePrioridad.push({distancias[centroAdyacente], centroAdyacente});
        }
      }
    }
    return distancias;
  }

  void mostrarCaminoMinimo(const string& codigo) {
    vector<int> distancias = caminoMinimo(codigo);

    for(int i = 0; i < distancias.size(); i++) {

      if (distancias[i] == 9999) {
        cout << "No hay conexion a centro" << " " << centros[i].codigo << endl;
      } else {
        cout << centros[i].codigo << " " << distancias[i] << endl;
      }
    }
  }

};
