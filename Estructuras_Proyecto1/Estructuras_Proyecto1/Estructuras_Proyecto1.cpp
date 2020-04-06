// Estructuras_Proyecto1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
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
#include "json.hpp"
#include <typeinfo>
using json = nlohmann::json;
using namespace std;

int dimensiones = 0;
Diccionario* nuevoDiccionario = new Diccionario();
ColaLetras* nuevaCola = new ColaLetras();
ArbolJugador* arbolJugadores = new ArbolJugador();
ListaTopJugadores* listTop = new ListaTopJugadores();
Tablero* tablero = new Tablero();
FichasJugador* fichas1 = new FichasJugador();
FichasJugador* fichas2 = new FichasJugador();
bool turnoInicial = true;

int turnoJugador(int puntaje_jugador1, FichasJugador* fj1) {
    int x = 0;
    int y = 0;
    int recorrido = 0;
    string palabra = "";
    cout << "\nIngrese la Palabra: ";
    cin >> palabra;
    int puntaje_temporal = 0;
    NodoDiccionario* buscarPalabra = nuevoDiccionario->buscar(palabra);
    if (buscarPalabra != NULL)
    {
        cout << "\nIngrese la Posicion Inicial en Fila: ";
        cin >> x;
        cout << "\nIngrese la Posicion Inicial en Columna: ";
        cin >> y;
        cout << "\nHacia donde quiere que vaya la palabra(1. Vertical 2. Horizontal): ";
        cin >> recorrido;
        if (recorrido == 1)
        {
            if (turnoInicial)
            {
                bool valido = false;
                puntaje_temporal = puntaje_jugador1;

                for (int i = 0; i < palabra.length(); i++)
                {
                    NodoCola* buscarMano = fj1->buscar(palabra[i]);
                    if ((x - i) >= 0 && (x-i)<=(dimensiones-1))
                    {
                        cout << palabra[i];
                        NodoMatriz* nodo = tablero->tieneNodo(x - i, y);
                        if (nodo != NULL)
                        {

                            if (nodo->getNodo() != NULL)
                            {

                                if (nodo->getNodo()->getCaracter() == palabra[i])
                                {
                                    if (nodo->getEstado() == "X2")
                                    {
                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 2);
                                        valido = true;
                                    }
                                    else if (nodo->getEstado() == "X3")
                                    {
                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 3);
                                        valido = true;
                                    }
                                    else {
                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 1);
                                        valido = true;
                                    }
                                }
                                else {
                                    cout << "Jugada Invalidad: La ficha que se encuentra en el tablero no corresponde en la palabra \nPierde su turno\n";
                                    valido = false;
                                    break;
                                }
                            }
                            else {
                                if (buscarMano != NULL)
                                {
                                    if (nodo->getEstado() == "X2")
                                    {
                                        puntaje_temporal = puntaje_temporal + (buscarMano->getPunteo() * 2);
                                    }
                                    else if (nodo->getEstado() == "X3")
                                    {
                                        puntaje_temporal = puntaje_temporal + (buscarMano->getPunteo() * 3);
                                    }
                                    valido = true;
                                }
                                else {
                                    cout << "Jugada Invalidad: La Ficha no se encuentra en su mano \nPierde su turno\n";
                                    valido = false;
                                    break;
                                }

                            }
                        }
                        else {
                            if (buscarMano != NULL)
                            {

                                puntaje_temporal = puntaje_temporal + buscarMano->getPunteo();
                                valido = true;
                            }
                            else {

                                cout << "Jugada Invalidad: La Ficha no se encuentra en su mano \nPierde su turno\n";
                                system("pause");
                   
                                valido = false;
                                break;
                            }
                        }
                    }
                    else {
                        cout << "Jugada Invalidad: posicion del tablero no existe \nPierde su turno\n";
                        valido = false;
                        break;
                    }
                }
                if (valido)
                {

                    turnoInicial = false;
                    puntaje_jugador1 = puntaje_temporal;
                    for (int i = 0; i < palabra.length(); i++)
                    {
                        NodoCola* buscarMano = fj1->buscar(palabra[i]);
                        if ((x - i) >= 0 && (x - i) <= (dimensiones - 1))
                        {
                            NodoMatriz* nodo = tablero->tieneNodo(x - i, y);
                            if (nodo != NULL)
                            {
                                if (nodo->getNodo() != NULL)
                                {
                                    if (nodo->getNodo()->getCaracter() == palabra[i])
                                    {
                                        tablero->agregarFicha(x - i, y, nodo->getNodo());
                                    }
                                }
                                else {
                                    tablero->agregarFicha(x - i, y, buscarMano);
                                    fj1->borrar(buscarMano);
                                }
                            }
                            else {
                                tablero->agregarFicha(x - i, y, buscarMano);
                                fj1->borrar(buscarMano);
                            }
                        }
                    }

                    cout << "Jugada Valida\n";
                    tablero->graficar();
                }
            }
            else {
                bool valido = false;
                puntaje_temporal = puntaje_jugador1;
                int valido2 = 0;
                int valido3 = 0;
                for (int i = 0; i < palabra.length(); i++)
                {
                    NodoCola* buscarMano = fj1->buscar(palabra[i]);
                    if ((x - i) >= 0 && (x - i) <= (dimensiones - 1))
                    {
                        NodoMatriz* nodo = tablero->tieneNodo(x - i, y);
                        if (nodo != NULL)
                        {
                            if (nodo->getNodo() != NULL)
                            {
                                if (nodo->getNodo()->getCaracter() == palabra[i])
                                {
                                    valido2++;
                                    if (nodo->getEstado() == "X2")
                                    {
                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 2);
                                        valido = true;
                                    }
                                    else if (nodo->getEstado() == "X3")
                                    {
                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 3);
                                        valido = true;
                                    }
                                    else {

                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 1);
                                        valido = true;
                                    }
                                    valido = true;
                                }
                                else {
                                    cout << "Jugada Invalidad: La Ficha que esta en el tablero no corresponde a la palabra \nPierde su turno\n";
                                    valido = false;
                                    break;
                                }
                            }
                            else {
                                if (buscarMano != NULL)
                                {
                                    valido3++;
                                    if (nodo->getEstado() == "X2")
                                    {
                                        puntaje_temporal = puntaje_temporal + (buscarMano->getPunteo() * 2);
                                    }
                                    else if (nodo->getEstado() == "X3")
                                    {
                                        puntaje_temporal = puntaje_temporal + (buscarMano->getPunteo() * 3);
                                    }
                                    else {
                                        puntaje_temporal = puntaje_temporal + (buscarMano->getPunteo() * 1);
                                    }
                                    valido = true;
                                }
                                else {
                                    cout << "Jugada Invalidad: La Ficha no se encuentra en su mano \nPierde su turno\n";
                                    valido = false;
                                    break;
                                }
                            }
                        }
                        else {
                            if (buscarMano != NULL)
                            {
                                valido3++;
                                puntaje_temporal = puntaje_temporal + buscarMano->getPunteo();
                                valido = true;
                            }
                            else {
                                cout << "Jugada Invalidad: La Ficha no se encuentra en su mano \nPierde su turno\n";
                                valido = false;
                                break;
                            }
                        }
                    }
                    else {
                        cout << "Jugada Invalidad: La posicion donde quiere colocar su ficha no se encuntra en el tablero \nPierde su turno\n";
                        valido = false;
                        break;
                    }
                }
                if (valido && (valido2 > 0) && (valido3>0))
                {

                    turnoInicial = false;
                    puntaje_jugador1 = puntaje_temporal;
                    for (int i = 0; i < palabra.length(); i++)
                    {
                        NodoCola* buscarMano = fj1->buscar(palabra[i]);
                        bool sy = tablero->existeColumna(y);
                        bool sx = tablero->existeFila(x - i);
                        if ((x - i) >= 0)
                        {
                            NodoMatriz* nodo = tablero->tieneNodo(x - i, y);
                            if (nodo != NULL)
                            {
                                if (nodo->getNodo() != NULL)
                                {
                                    if (nodo->getNodo()->getCaracter() == palabra[i])
                                    {
                                        tablero->agregarFicha(x - i, y, nodo->getNodo());
                                    }
                                }
                                else {
                                    tablero->agregarFicha(x - i, y, buscarMano);
                                    fj1->borrar(buscarMano);
                                }
                            }
                            else {
                                tablero->agregarFicha(x - i, y, buscarMano);
                                fj1->borrar(buscarMano);
                            }
                        }
                    }

                    cout << "Jugada Valida\n";
                    tablero->graficar();
                }
                else {
                    if (valido)
                    {
                        cout << "Jugada Invalida:True Valido2:"<<valido2<<" Valido3: "<<valido3<<"\n";
                        tablero->graficar();
                    }
                    else {
                        cout << "Jugada Invalida:False Valido2:" << valido2 << " Valido3: " << valido3 << "\n";
                        tablero->graficar();
                    }
                }
            }
        }
        else if (recorrido == 2) {
            if (turnoInicial)
            {
                bool valido = false;
                puntaje_temporal = puntaje_jugador1;

                for (int i = 0; i < palabra.length(); i++)
                {
                    NodoCola* buscarMano = fj1->buscar(palabra[i]);
                    if (((y + i) >= 0) && ((y+i)<=(dimensiones+1)))
                    {
                        NodoMatriz* nodo = tablero->tieneNodo(x, y + i);
                        if (nodo != NULL)
                        {
                            if (nodo->getNodo() != NULL)
                            {
                                if (nodo->getNodo()->getCaracter() == palabra[i])
                                {
                                    if (nodo->getEstado() == "X2")
                                    {
                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 2);
                                        valido = true;
                                    }
                                    else if (nodo->getEstado() == "X3")
                                    {
                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 3);
                                        valido = true;
                                    }
                                    else {
                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 1);
                                        valido = true;
                                    }
                                    valido = true;
                                }
                                else {
                                    cout << "Jugada Invalidad: La Ficha no corresponde a la que esta en el tablero \nPierde su turno\n";
                                    valido = false;
                                    break;
                                }
                            }
                            else {
                                if (buscarMano != NULL)
                                {
                                    if (nodo->getEstado() == "X2")
                                    {
                                        puntaje_temporal = puntaje_temporal + (buscarMano->getPunteo() * 2);
                                    }
                                    else if (nodo->getEstado() == "X3")
                                    {
                                        puntaje_temporal = puntaje_temporal + (buscarMano->getPunteo() * 3);
                                    }
                                    else {
                                        puntaje_temporal = puntaje_temporal + buscarMano->getPunteo();
                                    }
                                    valido = true;
                                }
                                else {
                                    cout << "Jugada Invalidad: La Ficha no se encuentra en su mano \nPierde su turno\n";
                                    valido = false;
                                    break;
                                }

                            }
                        }
                        else {
                            if (buscarMano != NULL)
                            {

                                puntaje_temporal = puntaje_temporal + buscarMano->getPunteo();
                                valido = true;
                            }
                            else {
                                cout << "Jugada Invalidad: La Ficha no se encuentra en su mano \nPierde su turno\n";
                                valido = false;
                                break;
                            }
                        }
                    }
                    else {
                        cout << "Jugada Invalidad: La posicion no esta en el tablero \nPierde su turno\n";
                        valido = false;
                        break;
                    }
                }
                if (valido)
                {
                    turnoInicial = false;
                    puntaje_jugador1 = puntaje_temporal;
                    for (int i = 0; i < palabra.length(); i++)
                    {
                        NodoCola* buscarMano = fj1->buscar(palabra[i]);
                        if ((y + i) >= 0)
                        {
                            NodoMatriz* nodo = tablero->tieneNodo(x, y + i);
                            if (nodo != NULL)
                            {
                                if (nodo->getNodo() != NULL)
                                {
                                    if (nodo->getNodo()->getCaracter() == palabra[i])
                                    {
                                        tablero->agregarFicha(x, y + i, nodo->getNodo());
                                    }
                                }
                                else {
                                    tablero->agregarFicha(x, y + i, buscarMano);
                                    fj1->borrar(buscarMano);
                                }
                            }
                            else {
                                tablero->agregarFicha(x, y + i, buscarMano);
                                fj1->borrar(buscarMano);
                            }
                        }
                    }
                    cout << "Jugada Valida\n";
                    tablero->graficar();
                }
            }
            else {
                bool valido = false;
                puntaje_temporal = puntaje_jugador1;
                int valido2 = 0;
                int valido3 = 0;
                for (int i = 0; i < palabra.length(); i++)
                {
                    NodoCola* buscarMano = fj1->buscar(palabra[i]);
                    if ((y + i) >= 0 && (y+i)<= (dimensiones-1))
                    {
                        NodoMatriz* nodo = tablero->tieneNodo(x, y + i);
                        if (nodo != NULL)
                        {
                            if (nodo->getNodo() != NULL)
                            {
                                if (nodo->getNodo()->getCaracter() == palabra[i])
                                {
                                    valido2++;
                                    if (nodo->getEstado() == "X2")
                                    {
                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 2);
                                        valido = true;
                                    }
                                    else if (nodo->getEstado() == "X3")
                                    {
                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 3);
                                        valido = true;
                                    }
                                    else {
                                        puntaje_temporal = puntaje_temporal + (nodo->getNodo()->getPunteo() * 1);
                                        valido = true;
                                    }
                                    valido = true;
                                }
                                else {
                                    cout << "Jugada Invalidad: La Ficha no se correspnde al tablero \nPierde su turno\n";
                                    valido = false;
                                    break;
                                }
                            }
                            else {
                                if (buscarMano != NULL)
                                {
                                    valido3++;
                                    if (nodo->getEstado() == "X2")
                                    {
                                        puntaje_temporal = puntaje_temporal + (buscarMano->getPunteo() * 2);
                                    }
                                    else if (nodo->getEstado() == "X3")
                                    {
                                        puntaje_temporal = puntaje_temporal + (buscarMano->getPunteo() * 3);
                                    }
                                    else {
                                        puntaje_temporal = puntaje_temporal + (buscarMano->getPunteo() * 3);
                                    }
                                    valido = true;
                                }
                                else {
                                    cout << "Jugada Invalidad: La Ficha no se encuentra en su mano \nPierde su turno\n";
                                    valido = false;
                                    break;
                                }

                            }
                        }
                        else {
                            if (buscarMano != NULL)
                            {
                                valido3++;
                                puntaje_temporal = puntaje_temporal + buscarMano->getPunteo();
                                valido = true;
                            }
                            else {
                                cout << "Jugada Invalidad: La Ficha no se encuentra en su mano \nPierde su turno\n";
                                valido = false;
                                break;
                            }
                        }
                    }
                    else {
                        cout << "Jugada Invalidad: La posicion no se encuentra \nPierde su turno\n";
                        valido = false;
                        break;
                    }
                }
                if (valido && valido2 > 0 && valido3>0)
                {

                    turnoInicial = false;
                    puntaje_jugador1 = puntaje_temporal;
                    for (int i = 0; i < palabra.length(); i++)
                    {
                        NodoCola* buscarMano = fj1->buscar(palabra[i]);
                        if ((y + i) >= 0)
                        {
                            NodoMatriz* nodo = tablero->tieneNodo(x, y + i);
                            if (nodo != NULL)
                            {
                                if (nodo->getNodo() != NULL)
                                {
                                    if (nodo->getNodo()->getCaracter() == palabra[i])
                                    {

                                        tablero->agregarFicha(x, y + i, nodo->getNodo());
                                    }
                                }
                                else {
                                    tablero->agregarFicha(x, y + i, buscarMano);
                                    fj1->borrar(buscarMano);
                                }
                            }
                            else {
                                tablero->agregarFicha(x, y + i, buscarMano);
                                fj1->borrar(buscarMano);
                            }
                        }
                    }
                    cout << "Jugada Valida\n";
                    tablero->graficar();
                }
                else {
                    if (valido)
                    {
                        cout << "Jugada Invalida:True Valido2:" << valido2 << " Valido3: " << valido3 << "\n";
                        tablero->graficar();
                    }
                    else {
                        cout << "Jugada Invalida:False Valido2:" << valido2 << " Valido3: " << valido3 << "\n";
                        tablero->graficar();
                    }
                }
            }
        }
    }
    else {
        cout << "\nLa Palabra No es Valida en el Diccionario\nPierde su turno\n";
    }
    return puntaje_jugador1;
}

void menu() {
    std::cout << "\nMenu\n";
    std::cout << "1. Probar Diccionario\n";
    std::cout << "2. Cola Letras\n";
    std::cout << "3. Matriz Dispersa\n";
    std::cout << "4. Arbol Binario\n";
    std::cout << "5. Juego\n";
    std::cout << "6. Top Jugadores\n";
    std::cout << "7. Puntaje a Jugador\n";
    std::cout << "8. Fichas de Jugador\n";
    std::cout << "9. Archivo Json\n";
    std::cout << "10. Salir\n";
}
void MenuDiccionario() {
    std::cout << "\nMenu Diccionrio\n";
    std::cout << "1. Agregar\n";
    std::cout << "2. Buscar\n";
    std::cout << "3. Graficar\n";
    std::cout << "4. Regresar\n";
}
void MenuCola() {
    std::cout << "\nMenu Cola\n";
    std::cout << "1. Revolver\n";
    std::cout << "2. Graficar\n";
    std::cout << "3. Desencolar\n";
    std::cout << "4. Regresar\n";
}
void MenuArbol() {
    std::cout << "\nMenu Arbol\n";
    std::cout << "1. Agregar\n";
    std::cout << "2. Graficar\n";
    std::cout << "3. Graficar Inorden\n";
    std::cout << "4. Graficar Preorden\n";
    std::cout << "5. Graficar Postorden\n";
    std::cout << "6. Regresar\n";
}
void MenuJuego() {
    std::cout << "\nMenu Juego\n";
    std::cout << "1. Cambiar Mano\n";
    std::cout << "2. Ingresar Palabra\n";
    std::cout << "3. Ver Mano\n";
    std::cout << "4. Graficar Tablero\n";
    std::cout << "5. Cola\n";
    std::cout << "6. Salir del Juego\n";
}
void MenuTablero() {
    std::cout << "Menu Tablero\n";
    std::cout << "1. Dimensiones\n";
    std::cout << "2. Dobles\n";
    std::cout << "3. Triples\n";
    std::cout << "4. Agregar Letra\n";
    std::cout << "5. Graficar\n";
    std::cout << "6. Regresar\n";
}
void MenuTop() {
    std::cout << "Menu Top\n";
    std::cout << "1. Llenar Lista\n";
    std::cout << "2. Graficar\n";
    std::cout << "3. Regresar\n";
}
void MenuPuntajes() {
    std::cout << "Menu Puntajes\n";
    std::cout << "1. Agregar Puntaje\n";
    std::cout << "2. Graficar\n";
    std::cout << "3. Regresar\n";
}
void MenuFichas() {
    std::cout << "Menu Fichas\n";
    std::cout << "1. Iniciar Manos\n";
    std::cout << "2. Graficar Manos\n";
    std::cout << "3. Regresar\n";
}
void diccionario() {
    int opcion = 0;
    do
    {
        MenuDiccionario();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            string palabra;
            cout << "Escriba su palabra a para agregar: \n";
            cin >> palabra;
            nuevoDiccionario->insertar(palabra);
        }break;
        case 2:
        {
            string palabra;
            cout << "Escriba su palabra a para buscar: \n";
            cin >> palabra;
            NodoDiccionario* encontrada = nuevoDiccionario->buscar(palabra);
            cout << "La palabra es: " << encontrada->getPalabra() << "\n";
        }break;
        case 3:
        {
            nuevoDiccionario->grficar();
        }break;
        }
    } while (opcion != 4);
}
void colaLetras() {
    int opcion = 0;
    do
    {
        MenuCola();
        cin >> opcion;
        switch (opcion)
        {
        case 1: {
            nuevaCola->revolver();
        }break;
        case 2: {
            nuevaCola->graficarCola();
        }break;
        case 3: {
            NodoCola* desencolo = nuevaCola->desencolar();
            cout << desencolo->getCaracter() << " - " << desencolo->getPunteo() << "\n";
        }break;
        }
    } while (opcion != 4);
}
void opcionesArbol() {
    int opcion = 0;
    do
    {
        MenuArbol();
        cin >> opcion;
        switch (opcion)
        {
        case 1: {
            string nombre;
            cout << "Nombre del ugadores: ";
            cin >> nombre;
            arbolJugadores->crearJugador(nombre);
        }break;
        case 2: {
            arbolJugadores->iniciarGrafica();
        }break;
        case 3: {
            arbolJugadores->iniciarInorden();
        }break;
        case 4: {
            arbolJugadores->iniciarPreorden();
        }break;
        case 5: {
            arbolJugadores->iniciarPostorden();
        }break;
        }
    } while (opcion != 6);
}

void opcionesTablero() {
    int opcion = 0;
    do
    {
        MenuTablero();
        cin >> opcion;
        switch (opcion)
        {
        case 1: {
            int dimensiones = 0;
            cout << "Dimensiones del tablero: ";
            cin >> dimensiones;
            tablero->iniciartablero();
            tablero->generarTablero(dimensiones);
        }break;
        case 2: {
            int x, y;
            cout << "Posicion x: ";
            cin >> x;
            cout << "\nPosicion y: ";
            cin >> y;
            tablero->generarDobles(x, y);
        }break;
        case 3: {
            int x, y;
            cout << "Posicion x: ";
            cin >> x;
            cout << "\nPosicion y: ";
            cin >> y;
            tablero->generarTriples(x, y);
        }break;
        case 4: {
            int x, y;
            cout << "Posicion x: ";
            cin >> x;
            cout << "\nPosicion y: ";
            cin >> y;
            tablero->agregarFicha(x, y, nuevaCola->desencolar());
        }break;
        case 5: {
            tablero->graficar();
        }break;
        }
    } while (opcion != 6);
}

void llenarTop(Jugador* raiz) {
    if (raiz->getNodoPuntaje() != NULL)
    {
        listTop->insertar(raiz->getUsuario(), raiz->getNodoPuntaje()->getPuntaje());
    }
    if (raiz->getIzquierda() != NULL)
    {
        llenarTop(raiz->getIzquierda());
    }
    if (raiz->getDerecha() != NULL)
    {
        llenarTop(raiz->getDerecha());
    }
}
void opcionesTop() {
    int opcion = 0;
    do
    {
        MenuTop();
        cin >> opcion;
        switch (opcion)
        {
        case 1: {
            Jugador* aux = arbolJugadores->devolverRaiz();
            if (aux!=NULL)
            {
                llenarTop(aux);
            }
        }break;
        case 2: {
            listTop->graficar();
        }break;
        }
    } while (opcion != 3);
}
void opcionesPuntajes() {
    int opcion = 0;
    do
    {
        MenuPuntajes();
        cin >> opcion;
        switch (opcion)
        {
        case 1: {

            ListaPuntajeJugador* actual = new ListaPuntajeJugador();
            string nombre = "";
            cout << "\nNombre del Jugador: ";
            cin >> nombre;
            Jugador* jugadorBusqueda = arbolJugadores->iniciarBusqueda(nombre);
            
            if (jugadorBusqueda!=NULL)
            {
                int puntaje = 0;
                cout << "\nPuntaje: ";
                cin >> puntaje;
                actual->iniciarLista(jugadorBusqueda->getNodoPuntaje());
                actual->insertar(nombre, puntaje);
                jugadorBusqueda->setNodoPuntaje(actual->retornrPrimero());        
                cout << "\nSe agrego Puntaje";
            }
            else {
                cout << "\nJugador Inexistente";
                system("pause");
            }
        }break;
        case 2: {

            ListaPuntajeJugador* actual = new ListaPuntajeJugador();
            string nombre = "";
            cout << "\nNombre del Jugador: ";
            cin >> nombre;
            Jugador* jugadorBusqueda = arbolJugadores->iniciarBusqueda(nombre);
            if (jugadorBusqueda != NULL)
            {
                if (jugadorBusqueda->getNodoPuntaje()!=NULL)
                {
                    actual->iniciarLista(jugadorBusqueda->getNodoPuntaje());
                    actual->graficar(nombre);
                }
            }
            else {
                cout << "\nJugador Inexistente";
                system("pause");
            }
        }break;
        }
    } while (opcion != 3);
}
void opcionesManos() {
    int opcion = 0;
    do
    {
        MenuFichas();
        cin >> opcion;
        switch (opcion)
        {
        case 1: {
            if (nuevaCola!=NULL)
            {
                for (int i = 0; i < 7; i++)
                {
                    fichas1->insertar(nuevaCola->desencolar());
                    fichas2->insertar(nuevaCola->desencolar());
                }
                cout << "Manos Llenas\n";
            }
           
        }break;
        case 2: {
            fichas1->graficar();
            fichas2->graficar();
        }break;
        }
    } while (opcion != 3);
}
void iniciarJuego() {
    int puntaje_temporal = 0;
    cout << "-----------------Scrable Iniciado-----------------------\n";
    nuevaCola->revolver();
    Jugador* jugador1 = new Jugador();
    string nombre1 = "";
    cout << "Seleccine Jugador1: ";
    cin >> nombre1;
    jugador1 = arbolJugadores->iniciarBusqueda(nombre1);
    while (jugador1==NULL)
    {
        cout << "\nUsuario no existe\nSeleccione Jugador1: ";
        cin >> nombre1;
        jugador1 = arbolJugadores->iniciarBusqueda(nombre1);
    }

    Jugador* jugador2 = new Jugador();
    string nombre2 = "";
    cout << "\nSeleccine Jugador2: ";
    cin >> nombre2;
    jugador2 = arbolJugadores->iniciarBusqueda(nombre2);
    while (jugador2 == NULL)
    {
        cout << "\nUsuario no existe\nSeleccione Jugador2: ";
        cin >> nombre2;
        jugador2 = arbolJugadores->iniciarBusqueda(nombre2);
    }
    int puntaje_jugador1 = 0;
    int puntaje_jugador2 = 0;
    turnoInicial = true;
    srand(time(NULL));
    int turno = rand()%2+1;
    int opcion = 0;
    fichas1 = new FichasJugador();
    fichas2 = new FichasJugador();

    if (nuevaCola!=NULL)
    {
        for (int i = 0; i < 7; i++)
        {
            fichas1->insertar(nuevaCola->desencolar());
            fichas2->insertar(nuevaCola->desencolar());
        }
        do {
            
            if (turno == 1)
            {
                cout << "\nTurno Jugador1 - " + jugador1->getUsuario()+" - "+to_string(puntaje_jugador1)+"\n";
                MenuJuego();
                cin >> opcion;
                switch (opcion)
                {
                case 1: {
                   
                    for (int i = 0; i < 7; i++)
                    {
                        NodoCola* cambiar = fichas1->cambiar();
                        if (cambiar!=NULL)
                        {
                            nuevaCola->encolar(cambiar->getCaracter(),cambiar->getPunteo());
                        }
                    }
                    for (int i = 0; i < 7; i++)
                    {
                        fichas1->insertar(nuevaCola->desencolar());
                    }
                    cout << "\nMirar Reporte de su Mano\n";
                    fichas1->graficar();
                }break;
                case 2: {
                    puntaje_jugador1 = turnoJugador(puntaje_jugador1,fichas1);
                    turno = 2;
                }break;
                case 3: {
                    fichas1->graficar();
                    cout << "\nVer Reporte de las fichas\n";
                    system("pause");
                }break;
                case 4: {
                    tablero->graficar();
                }break; 
                case 5: {
                    nuevaCola->graficarCola();
                }break;
                }
            }
            else {
                cout << "\nTurno Jugador2 - " + jugador2->getUsuario() +" - " + to_string(puntaje_jugador2) + "\n";
                MenuJuego();
                cin >> opcion;
                switch (opcion)
                {
                case 1: {
                    for (int i = 0; i < 7; i++)
                    {
                        NodoCola* cambiar = fichas2->cambiar();
                        if (cambiar != NULL)
                        {
                            nuevaCola->encolar(cambiar->getCaracter(), cambiar->getPunteo());
                        }
                    }
                    for (int i = 0; i < 7; i++)
                    {
                        fichas2->insertar(nuevaCola->desencolar());
                    }
                    cout << "\nMirar Reporte de su Mano\n";
                    fichas2->graficar();
                }break;
                case 2: {
                    puntaje_jugador2 = turnoJugador(puntaje_jugador2,fichas2);
                    turno = 1;
                }break;
                case 3: {
                    fichas2->graficar();
                    cout << "\nVer Reporte de las fichas\n";
                    system("pause");
                }break;
                case 4: {
                    tablero->graficar();
                }break;
                case 5: {
                    nuevaCola->graficarCola();
                }break;
                }
            }
        } while (opcion != 6);
        ListaPuntajeJugador* pj1 = new ListaPuntajeJugador();
        if (jugador1 != NULL)
        {
            pj1->iniciarLista(jugador1->getNodoPuntaje());
            pj1->insertar(jugador1->getUsuario(), puntaje_jugador1);
            jugador1->setNodoPuntaje(pj1->retornrPrimero());
        }
        ListaPuntajeJugador* pj2 = new ListaPuntajeJugador();
        if (jugador2 != NULL)
        {
            pj2->iniciarLista(jugador2->getNodoPuntaje());
            pj2->insertar(jugador2->getUsuario(), puntaje_jugador2);
            jugador2->setNodoPuntaje(pj2->retornrPrimero());
        }
    }    
}
void leerArchivo(string rutaArchivo) {
    std::ifstream i(rutaArchivo);
    json archivo;
    i >> archivo;
    int dimensiones_tablero = 0;
    dimensiones_tablero = archivo.at("dimension");
    nuevoDiccionario->vaciarLista();
    tablero->iniciartablero();
    dimensiones = dimensiones_tablero;
    for (int j= 0; j < archivo.at("casillas").at("dobles").size(); j++)
    {
        tablero->generarDobles(archivo.at("casillas").at("dobles")[j].at("x"), archivo.at("casillas").at("dobles")[j].at("y"));
    }
    for (int j = 0; j < archivo.at("casillas").at("triples").size(); j++)
    {
        tablero->generarTriples(archivo.at("casillas").at("triples")[j].at("x"), archivo.at("casillas").at("triples")[j].at("y"));
    }
    for (int j = 0; j < archivo.at("diccionario").size(); j++)
    {
        nuevoDiccionario->insertar(archivo.at("diccionario")[j].at("palabra"));
    }
}
void MenuArchivo() {
    std::cout << "Menu Tablero\n";
    std::cout << "1. Leer Archivo\n";
    std::cout << "2. Regresar\n";
}
void opcionesArchivo() {
    int opcion = 0;
    do
    {
        MenuArchivo();
        cin >> opcion;
        switch (opcion)
        {
        case 1: {
            string ruta = "";
            cout << "\nRuta Del Archivo: ";
            cin >> ruta;
            leerArchivo(ruta);
        }break;
        }
    } while (opcion !=2);
}
int main()
{
    try
    {
        int opcion = 0;

        do
        {
            menu();
            cin >> opcion;
            switch (opcion)
            {
            case 1:
            {
                //Diccinario
                diccionario();

            }break;
            case 2:
            {
                //Diccinario
                colaLetras();

            }break;
            case 3: {
                opcionesTablero();
            }break;
            case 4: {
                opcionesArbol();
            }break;
            case 5: {
                iniciarJuego();
            }break;
            case 6: {
                opcionesTop();
            }break;
            case 7: {
                opcionesPuntajes();
            }break;
            case 8: {
                opcionesManos();
            }break;
            case 9: {
                opcionesArchivo();
            }break;
            }
        } while (opcion != 10);
    }
    catch (const std::exception&)
    {
        cout << "Error\n";
        system("pausa");
    }
    
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
