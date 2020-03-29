#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include "Jugador.h"

using namespace std;

class ArbolJugador {
private:
public:
	Jugador* raiz;
	
	bool arbolVacio() {
		if (raiz!=NULL)
		{
			return false;
		}
		else {
			return true;
		}
	}
	void crearJugador(string nombre) {
		Jugador* nuevo = new Jugador();
		nuevo->setUsuario(nombre);
		if (arbolVacio())
		{
			raiz = nuevo;
		}
		else {
			insertar(raiz, nuevo);
		}
	}
	void insertar(Jugador* actual, Jugador* nuevo) {
		int resultado = orden(actual->getUsuario(), nuevo->getUsuario());
		if (resultado == 0)
		{

		}
		else if (resultado > 0)
		{
			if (actual->getDerecha()!=NULL)
			{
				insertar(actual->getDerecha(), nuevo);
			}
			else {
				actual->setDerecha(nuevo);
			}
		}
		else if (resultado < 0)
		{
			if (actual->getIzquierda() != NULL)
			{
				insertar(actual->getIzquierda(), nuevo);
			}
			else {
				actual->setIzquierda(nuevo);
			}
		}
	}
	int orden(string actual, string nuevo) {
		const char* nodoviejo = actual.c_str;
		const char* nodonuevo = nuevo.c_str;
		return strcmp(nodoviejo, nodonuevo);
	}
	void iniciarGrafica() {
		Jugador* aux = raiz;
		string grafica = "digraph Jugadores{\n";
		graficar(aux,grafica,0);
		grafica += "}";
		ofstream archivo;
		archivo.open("ArbolJugadores.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Tjpg ArbolJugadores.txt -o rbolJugadores.jpg");
	}
	void graficar(Jugador* actual, string grafica, int i) {
		int j = i;
		grafica += "node%i label[\u0022%s\u0022];\n",i,actual->getUsuario();
		if (actual->getIzquierda()!=NULL)
		{

			j++;
			grafica += "node%i -> node%i;\n",i,j;
			graficar(actual->getIzquierda(),grafica,j);
		}
		if (actual->getDerecha() != NULL)
		{
			j++;
			grafica += "node%i -> node%i;\n", i, j;
			graficar(actual->getDerecha(), grafica, j);
		}

	}
};