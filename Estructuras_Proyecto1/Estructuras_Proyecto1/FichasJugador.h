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
	
};