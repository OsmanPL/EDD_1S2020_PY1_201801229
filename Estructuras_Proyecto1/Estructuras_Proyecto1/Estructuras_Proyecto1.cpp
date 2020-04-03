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
ColaLetras* nuevaCola = new ColaLetras();
ArbolJugador* arbolJugadores = new ArbolJugador();
ListaTopJugadores* listTop = new ListaTopJugadores();
Tablero* tablero = new Tablero();
FichasJugador* fj1 = new FichasJugador();
FichasJugador* fj2 = new FichasJugador();

void menu() {
    std::cout << "Menu\n";
    std::cout << "1. Probar Diccionario\n";
    std::cout << "2. Cola Letras\n";
    std::cout << "3. Matriz Dispersa\n";
    std::cout << "4. Arbol Binario\n";
    std::cout << "5. Juego\n";
    std::cout << "6. Top Jugadores\n";
    std::cout << "7. Puntaje a Jugador\n";
    std::cout << "8. Fichas de Jugador\n";
    std::cout << "9. Salir\n";
}
void MenuDiccionario() {
    std::cout << "Menu Diccionrio\n";
    std::cout << "1. Agregar\n";
    std::cout << "2. Buscar\n";
    std::cout << "3. Graficar\n";
    std::cout << "4. Regresar\n";
}
void MenuCola() {
    std::cout << "Menu Cola\n";
    std::cout << "1. Revolver\n";
    std::cout << "2. Graficar\n";
    std::cout << "3. Desencolar\n";
    std::cout << "4. Regresar\n";
}
void MenuArbol() {
    std::cout << "Menu Arbol\n";
    std::cout << "1. Agregar\n";
    std::cout << "2. Graficar\n";
    std::cout << "3. Regresar\n";
}
void MenuJuego() {
    std::cout << "Menu Juego\n";
    std::cout << "1. Cambiar Ficha\n";
    std::cout << "2. Ingresar Palabra\n";
    std::cout << "3. Pasar\n";
    std::cout << "4. Sacar Ficha Cola\n";
    std::cout << "5. Graficar Tablero\n";
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
        }
    } while (opcion != 3);
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
                    fj1->insertar(nuevaCola->desencolar());
                    fj2->insertar(nuevaCola->desencolar());
                }
                cout << "Manos Llenas\n";
            }
           
        }break;
        case 2: {
            fj1->graficar();
            fj2->graficar();
        }break;
        }
    } while (opcion != 3);
}
void iniciarJuego() {
    cout << "-----------------Scrable Iniciado-----------------------\n";
    Jugador* jugador1 = new Jugador();
    string nombre1 = "";
    cout << "Seleccine Jugador1: ";
    cin >> nombre1;
    jugador1 = arbolJugadores->iniciarBusqueda(nombre1);
    while (jugador1==NULL)
    {
        cout << "Usuario no existe\nSeleccione Jugador1: ";
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
        cout << "Usuario no existe\nSeleccione Jugador2: ";
        cin >> nombre2;
        jugador2 = arbolJugadores->iniciarBusqueda(nombre2);
    }
    int turno = rand() % 2 +1;
    int opcion = 0;
    fj1 = new FichasJugador();
    fj2 = new FichasJugador();
    if (nuevaCola!=NULL)
    {
        for (int i = 0; i < 7; i++)
        {
            fj1->insertar(nuevaCola->desencolar());
            fj2->insertar(nuevaCola->desencolar());
        }
        do {
            
            if (turno == 1)
            {
                cout << "Turno Jugador1 - " + jugador1->getUsuario()+"\n";
                MenuJuego();
                cin >> opcion;
                switch (opcion)
                {
                case 1: {
                    int j = 0;
                    do {
                        fj1->graficar();
                        char c = ' ';
                        cout << "Mirar Reporte para ver sus fichas\n";
                        cout << "Seleccine ficha a cambiar: ";
                        cin >> c;
                        NodoCola* buscar = fj1->buscar(c);
                        if (buscar!=NULL)
                        {
                            nuevaCola->encolar(buscar->getCaracter(), buscar->getPunteo());
                            fj1->borrar(buscar);
                            fj1->insertar(nuevaCola->desencolar());
                        }
                        else {
                            cout << "\nEsa Ficha No Existe\n";
                        }
                        cout << "¿Quiere seguir Cambiando Ficha? Presione 1. No o 2. Si: ";
                        cin >> j;
                    } while (j != 1);
                }break;
                case 2: {

                }break;
                case 3: {

                }break;
                case 4: {

                }break;
                case 5: {

                }break;
                }
                turno = 2;
            }
            else {
                cout << "Turno Jugador2 - " + jugador2->getUsuario() +"\n";
                MenuJuego();
                cin >> opcion;
                switch (opcion)
                {
                case 1: {
                    int j = 0;
                    do {
                        fj2->graficar();
                        char c = ' ';
                        cout << "Mirar Reporte para ver sus fichas\n";
                        cout << "Seleccine ficha a cambiar: ";
                        cin >> c;
                        NodoCola* buscar = fj2->buscar(c);
                        if (buscar != NULL)
                        {
                            nuevaCola->encolar(buscar->getCaracter(), buscar->getPunteo());
                            fj2->borrar(buscar);
                            fj2->insertar(nuevaCola->desencolar());
                        }
                        else {
                            cout << "\nEsa Ficha No Existe\n";
                        }
                        cout << "¿Quiere seguir Cambiando Ficha? Presione 1. No o 2. Si: ";
                        cin >> j;
                    } while (j != 1);
                }break;
                case 2: {

                }break;
                case 3: {

                }break;
                case 4: {

                }break;
                case 5: {

                }break;
                }
                turno = 1;
            }
        } while (opcion != 6);
    }    
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
            }
        } while (opcion != 9);
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
