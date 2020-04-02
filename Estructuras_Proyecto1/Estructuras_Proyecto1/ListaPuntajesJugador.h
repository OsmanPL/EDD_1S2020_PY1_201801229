#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include "NodoPuntaje.h"

using namespace std;

class ListaPuntajeJugador {
private:

public:

	NodoPuntaje* primero;

	void iniciarLista(NodoPuntaje* iniciar) {
		primero = iniciar;
	}
	bool listaVacia() {
		if (primero!=NULL)
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
			if (puntaje>=primero->getPuntaje())
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
							temporal = aux;
							aux = aux->getSiguiente();
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
	void graficar(string nombrejugador) {
		NodoPuntaje* aux = primero;
		int i=0;
		string grafica = "digraph PuntajeJugador" + nombrejugador + "{\nrankdir=\u0022LR\u0022;\n";
		while (aux !=NULL)
		{
			grafica += "node%i [label=\u0022%i\u0022];\n",i,aux->getPuntaje();
			i++;
			aux = aux->getSiguiente();
		}
		int j = 0;
		int l = 1;
		aux = primero;
		while (aux!=NULL)
		{
			if (aux->getSiguiente()!=NULL)
			{
				grafica += "node%i -> node%i;\n", j, l;
			}
			j++;
			l++;
			aux = aux->getSiguiente();
		}
		grafica += "}";
		ofstream archivo;
		archivo.open("ListaPuntajes.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Tjpg ListaPuntajes.txt -o ListaPuntajes.jpg");
	}
};