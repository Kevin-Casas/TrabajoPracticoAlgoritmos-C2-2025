// TrabajoPracticoAlgoritmosC2-2025.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include "C:\Users\Kevin\Documents\Unahur\Algoritmos\TP\TrabajoPracticoAlgoritmosC2-2025\Headers\ArbolCentro.h"
#include "C:\Users\Kevin\Documents\Unahur\Algoritmos\TP\TrabajoPracticoAlgoritmosC2-2025\Headers\TablaDeHashing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    
    ArbolCentro arbolCapacidad;
    ArbolCentro arbolEmpleados;
    ArbolCentro arbolPaquetes;
    
    //Ingreso de centros desde el archivo centros.txt
    fstream archivoCentros;
    archivoCentros.open("centros.txt", ios::in);
    if(archivoCentros.is_open()) {
        string linea;
        while (getline(archivoCentros, linea))
        {
            //Ignora lineas vacias
            if(linea.empty()) continue;

            stringstream ss(linea);

            //Toma los valores int como string para evitar errores
            string codigo, nombre, ciudad, capacidad, paquetes_diarios, empleados;

            getline(ss, codigo, ' ');
            getline(ss, nombre, ' ');
            getline(ss, ciudad, ' ');
            getline(ss, capacidad, ' ');
            getline(ss, paquetes_diarios, ' ');
            getline(ss, empleados, ' ');

            //Convierte a int para constructor
            int capacidadInt = stoi(capacidad);
            int paquetes_diariosInt = stoi(paquetes_diarios);
            int empleadosInt = stoi(empleados);

            Centro centro(codigo, nombre, ciudad, capacidadInt, paquetes_diariosInt, empleadosInt);

        }
        archivoCentros.close();
    }

    //Ingreso de envios desde el archivo envios.txt
    fstream archivoEnvios;
    archivoEnvios.open("envios.txt", ios::in);
    if(archivoEnvios.is_open()) {
        string linea;
        while (getline(archivoEnvios, linea))
        {
            /* code */
        }
        archivoEnvios.close();
    }

    //Ingreso de conexiones desde el archivo envios.txt
    fstream archivoConexiones;
    archivoConexiones.open("conexiones.txt", ios::in);
    if(archivoConexiones.is_open()) {
        string linea;
        while (getline(archivoConexiones, linea))
        {
            /* code */
        }
        archivoConexiones.close();
    }



    cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
