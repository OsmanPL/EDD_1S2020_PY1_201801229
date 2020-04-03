#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
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
					if (aux->getSiguiente() != NULL)
					{
						if (puntaje >= aux->getPuntaje())
						{
							temporal->setSiguiente(nuevo);
							nuevo->setSiguiente(aux);
							r = 1;
						}
						else {
							temporal = aux;
							aux = aux->getSiguiente();
						}
					}
					else {
						if (puntaje >= aux->getPuntaje())
						{
							temporal->setSiguiente(nuevo);
							nuevo->setSiguiente(aux);
							r = 1;
						}
						else {

							aux->setSiguiente(nuevo);
						}
						r = 1;
					}
				}
			}
		}
	}

	void graficar() {
		NodoPuntaje* aux = primero;
		int i = 0;
		string grafica = "digraph TopScore{\nrankdir=\u0022LR\u0022;\n";
		while (aux != NULL)
		{
			grafica += "node"+to_string(i)+" [label=\u0022"+aux->getNombreJugador()+" - "+to_string(aux->getPuntaje())+"\u0022];\n";
			i++;
			aux = aux->getSiguiente();
		}
		int j = 0;
		int l = 1;
		aux = primero;
		while (aux != NULL)
		{
			if (aux->getSiguiente() != NULL)
			{
				grafica += "node"+to_string(j)+" -> node"+to_string(l)+";\n";
			}
			j++;
			l++;
			aux = aux->getSiguiente();
		}
		grafica += "}";
		ofstream archivo;
		archivo.open("TopScore.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Tjpg TopScore.txt -o TopScore.jpg");
	}

};