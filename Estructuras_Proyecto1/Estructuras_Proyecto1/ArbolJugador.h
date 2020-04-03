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
	int i = 0;
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
			if (actual->getIzquierda()!=NULL)
			{
				insertar(actual->getIzquierda(), nuevo);
			}
			else {
				actual->setIzquierda(nuevo);
			}
		}
		else if (resultado < 0)
		{
			if (actual->getDerecha() != NULL)
			{
				insertar(actual->getDerecha(), nuevo);
			}
			else {
				actual->setDerecha(nuevo);
			}
		}
	}
	int orden(string actual, string nuevo) {
		const char* nodoviejo = &actual[0];
		const char* nodonuevo = &nuevo[0];
		return strcmp(nodoviejo, nodonuevo);
	}
	void iniciarGrafica() {
		Jugador* aux = raiz;
		string grafica = "digraph Jugadores{\n";
		grafica += graficar(aux);
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

		system("dot -Tjpg ArbolJugadores.txt -o ArbolJugadores.jpg");
	}
	string graficar(Jugador* actual) {
		string grafica = "";
		int l = i;
		grafica += "node"+ to_string(l) +" [label=\u0022"+actual->getUsuario()+"\u0022];\n";
		if (actual->getIzquierda()!=NULL)
		{

			i++;
			grafica += "node"+ to_string(l) +" -> node"+ to_string(i) +";\n";
			
			grafica += graficar(actual->getIzquierda());
		}
		if (actual->getDerecha() != NULL)
		{
			i++;
			grafica += "node"+ to_string(l) +" -> node"+ to_string(i) +";\n";
			grafica += graficar(actual->getDerecha());
		}
		return grafica;
	}
};