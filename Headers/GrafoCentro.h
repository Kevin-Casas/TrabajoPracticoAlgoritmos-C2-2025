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

  vector<int> caminoMinimo(const string& codigoOrigen, const string& codigoDestino) {

    int cantidadDeCentros = centros.size();
    int centroOrigenClave = claves[codigoOrigen];
    int centroDestinoClave = claves[codigoDestino];

    vector<int> distancias(cantidadDeCentros, 9999);
    vector<int> centrosVisitados(cantidadDeCentros, -1);

    distancias[centroOrigenClave] = 0;


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> colaDePrioridad;

    colaDePrioridad.push({0, centroOrigenClave});

    while(!colaDePrioridad.empty()) {

      auto colaTop = colaDePrioridad.top();

      int distanciaActual = colaTop.first;
      int centroActual = colaTop.second;
      colaDePrioridad.pop();

      if (centroActual == centroDestinoClave) {
        break;
      }

      if(distanciaActual > distancias[centroActual]) {
        continue;
      }

      for (const auto& par : matrizDeAdyacencias[centroActual]) {

        int centroAdyacente = par.first;
        int distanciaConexion = par.second;

        if (distancias[centroActual] + distanciaConexion < distancias[centroAdyacente]) {

          distancias[centroAdyacente] = distancias[centroActual] + distanciaConexion;
          centrosVisitados[centroAdyacente] = centroActual;
          colaDePrioridad.push({distancias[centroAdyacente], centroAdyacente});
        }
      }
    }

    vector<int> caminoMinimo;
    if(distancias[centroDestinoClave] == 9999) {
      return caminoMinimo;
    }

    //Se guarda el recorrido hasta el centro origen en formato de pila y se lo da vuelta para devolver en orden de recorrido
    for (int nodo = centroDestinoClave; nodo != -1; nodo = centrosVisitados[nodo]) {
      caminoMinimo.push_back(nodo);
    }
    reverse(caminoMinimo.begin(), caminoMinimo.end());
    return caminoMinimo;
  }

  void mostrarCaminoMinimo(const string& codigoOrigen, const string& codigoDestino) {
    vector<int> caminoADestino = caminoMinimo(codigoOrigen, codigoDestino);

    if (caminoADestino.empty()) {
      cout << "No hay conexion entre los centros seleccionados" << endl;
      return;
    } else {
      cout << "Camino minimo desde " << codigoOrigen << " " << "hasta " << codigoDestino << endl;

      for (int i = 0; i < caminoADestino.size(); i++) {
        cout << centros[caminoADestino[i]].codigo << endl;
      }
    }
  }
};
