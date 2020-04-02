// Estructuras_Proyecto1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Diccionario.h"
#include "ArbolJugador.h"
#include "ColaLetras.h"
#include "FichasJugador.h"
#include "Jugador.h"
#include "ListaPuntajesJugador.h"
#include "ListaTopJugadores.h"
#include "NodoCola.h"
#include "NodoDiccionario.h"
#include "NodoMatriz.h"
#include "NodoPuntaje.h"
#include "Tablero.h"

using namespace std;


Diccionario* nuevoDiccionario = new Diccionario();

int main()
{
    int opcion;

    do
    {
        menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            //Diccinario
            

        }break;

        }
    } while (opcion!=6);
}

void menu() {
    std::cout << "Menu\n";
    std::cout << "1. Probar Diccionario\n";
    std::cout << "2. Cola Letras\n";
    std::cout << "3. Matriz Dispersa\n";
    std::cout << "4. Arbol Binario\n";
    std::cout << "5. Juego\n";
    std::cout << "6. Salir\n";
}
void MenuDiccionario() {
    std::cout << "Menu Diccionrio\n";
    std::cout << "1. Agregar\n";
    std::cout << "2. Buscar\n";
    std::cout << "3. Graficar\n";
    std::cout << "4. Regresar\n";
}
void diccionario() {
    int opcion;
    do
    {
        switch (opcion)
        {
        case 1:
        {
            string palabra;
            cout << "Escriba su palabra a para agregar: ";
            cin >> palabra;
            nuevoDiccionario->insertar(palabra);
        }break;
        }
    } while (opcion!=4);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
