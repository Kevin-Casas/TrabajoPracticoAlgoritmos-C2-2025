#pragma once
#include "C:\Users\Kevin\Documents\Unahur\Algoritmos\TP\TrabajoPracticoAlgoritmosC2-2025\Headers\Centro.h"
using namespace std;
class Conexion
{
public:
	Centro centro_origen;
	Centro centro_destino;
	int distancia;

	Conexion(Centro centro_origen, Centro centro_destino)
		: centro_origen(centro_origen), centro_destino(centro_destino) {}
};

