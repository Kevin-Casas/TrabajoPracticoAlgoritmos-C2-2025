#pragma once
#include <string>
using namespace std;
class Envio
{
public: 
	string codigo_centro;
	int paquete_id;
	int cliente_id;
	int fecha_dia;
	float peso;

	Envio(string codigo_centro, int paquete_id, int cliente_id, int fecha_dia, float peso) 
		: codigo_centro(codigo_centro), paquete_id(paquete_id), cliente_id(cliente_id), fecha_dia(fecha_dia), peso(peso) {}
};

