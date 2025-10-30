#pragma once
#include <string>
using namespace std;
class Centro
{
public:
	string codigo;
	string nombre;
	string ciudad;
	int capacidad;
	int paquetes_diarios;
	int empleados;

	Centro(string codigo, string nombre, string ciudad, int capacidad, int paquetes_diarios, int empleados) 
		: codigo(codigo), nombre(nombre), ciudad(ciudad), capacidad(capacidad), paquetes_diarios(), empleados() {}
};

