// TrabajoPracticoAlgoritmosC2-2025.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include "./Headers/TablaDeHashing.h"
#include "./Headers/Centro.h"
#include "./Headers/Envio.h"
#include "./Headers/Conexion.h"
#include "./Headers/GrafoCentro.h"
#include "./Headers/ArbolCentro.h"
#include "./Headers/NodoCentro.h"
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
    TablaDeHashing tablaHash;
    GrafoCentro grafo;



    // Ingreso de centros desde el archivo centros.txt
    fstream archivoCentros;
    archivoCentros.open("centros.txt", ios::in);
    if (archivoCentros.is_open())
    {
        string codigo, nombre, ciudad;
        int capacidad, paquetes_diarios, empleados;
        while (archivoCentros >> codigo >> nombre >> ciudad >> capacidad >> paquetes_diarios >> empleados)
        {
            Centro centro(codigo, nombre, ciudad, capacidad, paquetes_diarios, empleados);
            arbolCapacidad.insertarPorCapacidad(centro);
            arbolEmpleados.insertarPorEmpleados(centro);
            arbolPaquetes.insertarPorPaquetes(centro);
            tablaHash.insertarCentro(centro);
            grafo.agregarCentro(centro);
        }
        archivoCentros.close();
    }

    // Ingreso de envios desde el archivo envios.txt
    fstream archivoEnvios;
    archivoEnvios.open("envios.txt", ios::in);
    if (archivoEnvios.is_open())
    {
        string linea;
        while (getline(archivoEnvios, linea))
        {
            // Ignora lineas vacias
            if (linea.empty())
                continue;

            stringstream ss(linea);

            string codigo_centro, paquete_id, cliente_id, fecha_dia, peso;

            getline(ss, codigo_centro, ' ');
            getline(ss, paquete_id, ' ');
            getline(ss, cliente_id, ' ');
            getline(ss, fecha_dia, ' ');
            getline(ss, peso, ' ');

            int paquete_idNum = stoi(paquete_id);
            int cliente_idNum = stoi(cliente_id);
            int fecha_diaNum = stoi(fecha_dia);
            float pesoNum = stoi(peso);

            Envio envio(codigo_centro, paquete_idNum, cliente_idNum, fecha_diaNum, pesoNum);
        }
        archivoEnvios.close();
    }

    // Ingreso de conexiones desde el archivo envios.txt
    fstream archivoConexiones;
    archivoConexiones.open("conexiones.txt", ios::in);
    if (archivoConexiones.is_open())
    {
        string centro_origen, centro_destino;
        int distancia;
        while (archivoConexiones >> centro_origen >> centro_destino >> distancia)
        {
            Conexion conexion(centro_origen, centro_destino, distancia);
            grafo.agregarConexion(conexion);
        }
        archivoConexiones.close();
    }

    int opcion = 10;

    while (opcion != 0)
    {

        cout << "Opcion 1 para mostrar centro especifico" << endl;
        cout << "Opcion 2 para agregar un centro nuevo" << endl;
        cout << "Opcion 3 para eliminar un centro" << endl;
        cout << "Opcion 4 para mostrar todos los centros por capacidad" << endl;
        cout << "Opcion 5 para mostrar todos los centros por empleados" << endl;
        cout << "Opcion 6 para mostrar todos los centros por paquetes" << endl;
        cout << "Opcion 7 para mostrar el camino minimo de un centro a otro" << endl;
        cout << "Opcion 0 para terminar el programa" << endl;
        cin >> opcion;
        cin.ignore();

        string codigo, nombre, ciudad;
        int capacidad, paquetes_diarios, empleados;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese codigo de centro" << endl;
            cin >> codigo;
            tablaHash.mostrarCentro(codigo);
            break;
        case 2:
        {
            cout << "Ingrese el codigo del centro nuevo" << endl;
            cin >> codigo;
            cout << "Ingrese el nombre del centro nuevo" << endl;
            cin >> nombre;
            cout << "Ingrese la ciudad del centro nuevo" << endl;
            cin >> ciudad;
            cout << "Ingrese la capacidad del centro nuevo" << endl;
            cin >> capacidad;
            cout << "Ingrese los paquetes diarios del centro" << endl;
            cin >> paquetes_diarios;
            cout << "Ingrese los empleados del centro" << endl;
            cin >> empleados;
            Centro centro(codigo, nombre, ciudad, capacidad, paquetes_diarios, empleados);
            tablaHash.insertarCentro(centro);
            tablaHash.mostrarCentro(codigo);
            break;
        }
        case 3:
            cout << "Ingrese el codigo del centro a eliminar" << endl;
            cin >> codigo;
            tablaHash.eliminarCentro(codigo);
            break;
        case 4:
            arbolCapacidad.mostrarInordenCapacidad(arbolCapacidad.raiz);
            break;
        case 5:
            arbolEmpleados.mostrarInordenEmpleados(arbolEmpleados.raiz);
            break;
        case 6:
            arbolPaquetes.mostrarInordenPaquetes(arbolPaquetes.raiz);
            break;
        case 7:
        {
            string codigoDestino;
            cout << "Ingrese el codigo del centro origen" << endl;
            cin >> codigo;
            cout << "Ingrese el codigo del centro destino" << endl;
            cin >> codigoDestino;
            grafo.mostrarCaminoMinimo(codigo, codigoDestino);
            break;
        }
        case 0:
            arbolCapacidad.eliminarArbol(arbolCapacidad.raiz);
            arbolEmpleados.eliminarArbol(arbolEmpleados.raiz);
            arbolPaquetes.eliminarArbol(arbolPaquetes.raiz);
            break;
        default:
            cout << "Opcion incorrecta" << endl;
        }
    }

   // cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
