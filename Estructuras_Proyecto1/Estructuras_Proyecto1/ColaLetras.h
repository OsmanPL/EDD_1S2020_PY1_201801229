#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
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
	void graficarCola() {
		NodoCola* aux = primero;
		string grafica = "digraph ColaLetras{\nrankdir=\u0022TB\u0022;\n";
		int i = 0;
		while (aux!=NULL)
		{
			grafica += "node%i [label=\u0022%c - %i\u0022]\n",i,aux->getCaracter(),aux->getPunteo();
			i++;
			aux = aux->getSiguiente();
		}
		int j = 0;
		int l = 1;
		aux = primero;
		while (aux != NULL)
		{
			if (aux->getSiguiente()!=NULL)
			{
				grafica += "node%i -> node%i;\n",j,l;
			}
			j++;
			l++;
			aux = aux->getSiguiente();
		}
		grafica += "}";
		ofstream archivo;
		archivo.open("ColaLetras.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Tjpg ColaLetras.txt -o ColaLetras.jpg");
	}
};