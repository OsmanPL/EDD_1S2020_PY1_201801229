#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include "NodoPuntaje.h"

using namespace std;

class ListaTopJugadores {
private:

public:

	NodoPuntaje* primero;
	bool listaVacia() {
		if (primero != NULL)
		{
			return false;
		}
		else {
			return true;
		}
	}
	void insertar(string nombre, int puntaje) {
		NodoPuntaje* nuevo = new NodoPuntaje();
		nuevo->setNombreJugador(nombre);
		nuevo->setPuntaje(puntaje);
		if (listaVacia())
		{
			primero = nuevo;
		}
		else {
			NodoPuntaje* aux = primero;
			NodoPuntaje* temporal = aux;
			int r = 0;
			if (puntaje >= primero->getPuntaje())
			{
				nuevo->setSiguiente(primero);
				primero = nuevo;
			}
			else {
				while (r == 0) {
					if (aux != NULL)
					{
						if (puntaje >= aux->getPuntaje())
						{
							nuevo->setSiguiente(aux->getSiguiente());
							aux->setSiguiente(nuevo);
							r = 1;
						}
						else {
							aux = aux->getSiguiente();
							temporal = aux;
						}
					}
					else {
						temporal->setSiguiente(nuevo);
					}
				}
			}
		}
	}
	NodoPuntaje* puntajeMasAlto() {
		return primero;
	}
};