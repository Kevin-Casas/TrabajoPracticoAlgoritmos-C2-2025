#pragma once
#include "Centro.h"
#include <string>
using namespace std;
class Conexion
{
public:
	string centro_origen;
	string centro_destino;
	int distancia;

	Conexion(string centro_origen, string centro_destino, int distancia)
		: centro_origen(centro_origen), centro_destino(centro_destino), distancia(distancia) {}
};

