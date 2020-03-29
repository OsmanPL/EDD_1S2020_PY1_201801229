#include <string>
#include <iostream>
#include <cstdio>
#include "NodoCola.h"

using namespace std;

class ColaLetras {
private:
	
public:
	NodoCola* primero;

	bool listaVacia() {
		if (primero!=NULL)
		{
			return false;
		}
		else {
			true;
		}
	}
	void encolar(char c, int punteo) {
		NodoCola* nuevo = new NodoCola();
		nuevo->setCaracter(c);
		nuevo->setPunteo(punteo);
		if (listaVacia())
		{
			primero = nuevo;
		}
		else {
			nuevo->setSiguiente(primero);
			primero->setAnterior(nuevo);
			primero = nuevo;
		}
	}
	NodoCola* desencolar() {
		NodoCola* aux = primero;
		while (aux!=NULL) {
			if (aux->getSiguiente()==NULL)
			{
				NodoCola* temporal = aux->getAnterior();
				temporal->setSiguiente(NULL);
				return aux;
			}
		}
		
	}
};