#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include "NodoCola.h"

using namespace std;

class FichasJugador {
private:

public:
	NodoCola* primero;
	NodoCola* ultimo;

	bool listaVacia() {
		if (primero != NULL && ultimo != NULL)
		{
			return false;
		}
		else {
			true;
		}
	}
	void insertar(NodoCola* nuevo) {
		if (listaVacia())
		{
			primero = nuevo;
			ultimo = nuevo;
		}
		else {
			primero->setAnterior(nuevo);
			nuevo->setSiguiente(primero);
			primero = nuevo;
		}
	}
	bool existe(char c) {
		NodoCola* aux = primero;
		while (aux != NULL) {
			if (aux->getCaracter() == c)
			{
				return true;
			}
			aux = aux->getSiguiente();
		}
		return false;
	}
	NodoCola* buscar(char c) {
		NodoCola* aux = primero;
		while (aux != NULL) {
			if (aux->getCaracter() == c)
			{
				return aux;
			}
			aux = aux->getSiguiente();
		}
	}
	void borrar(NodoCola* eliminar) {
		NodoCola* derecha = eliminar->getSiguiente();
		NodoCola* izquierda = eliminar->getAnterior();
		derecha->setAnterior(izquierda);
		izquierda->setAnterior(derecha);
	}
	void graficar() {
		NodoCola* aux = primero;
		int i = 0;
		string grafica = "digraph FichasJugador{\nrankdir=\u0022LR\u0022;\n";
		while (aux != NULL)
		{
			grafica += "node%i [label=\u0022%c\u0022];\n", i, aux->getCaracter();
			aux = aux->getSiguiente();
			i++;
		}
		int j = 0;
		int l = 1;
		aux = primero;
		while (aux!=NULL)
		{
			if (aux->getSiguiente()!=NULL)
			{
				grafica += "node%i -> node%i;",j,l;
				grafica += "node%i -> node%i;", l, j;
			}
			aux = aux->getSiguiente();
			j++;
			l++;
		}
		grafica += "}";
		ofstream archivo;
		archivo.open("FichasJugador.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Tjpg FichasJugador.txt -o FichasJugador.jpg");
	}
	
};