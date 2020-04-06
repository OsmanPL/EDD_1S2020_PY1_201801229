#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include "NodoMatriz.h"

using namespace std;

class Tablero {
private:

public:

	NodoMatriz* raiz;
	int tx = 0;
	int ty = 0;

	void iniciartablero() {
		raiz = new NodoMatriz();
		raiz->setY(-1);
		raiz->setX(-1);
	}
	bool existeColumna(int y) {
		NodoMatriz* aux = raiz;
		bool existe = false;
		while (aux!=NULL)
		{
			if (aux->getY()==y)
			{
				existe = true;
			}
			aux = aux->getDerecha();
		}
		return existe;
	}

	bool existeFila(int x) {
		NodoMatriz* aux = raiz;
		bool existe = false;
		while (aux != NULL)
		{
			if (aux->getX() == x)
			{
				existe = true;
			}
			aux = aux->getAbajo();
		}
		return existe;
	}

	NodoMatriz* devolverFila(int x) {
		NodoMatriz* aux = raiz;
		while (aux != NULL)
		{
			if (aux->getX() == x)
			{
				return aux;
			}
			aux = aux->getAbajo();
		}
		return NULL;
	}

	NodoMatriz* devolverColumna(int y) {
		NodoMatriz* aux = raiz;
		while (aux != NULL)
		{
			if (aux->getY() == y)
			{
				return aux;
			}
			aux = aux->getDerecha();
		}
		return NULL;
	}

	void crearColumna(int y) {
		NodoMatriz* nuevaColumna = new NodoMatriz();
		nuevaColumna->setY(y);
		NodoMatriz* aux = raiz->getDerecha();
		bool agregar = true;
		if (aux==NULL)
		{
			raiz->setDerecha(nuevaColumna);
			nuevaColumna->setIzquierda(raiz);
		}
		else {
			NodoMatriz* temporal = aux->getDerecha();
			while (agregar)
			{
				if (temporal!=NULL)
				{
					if (y==aux->getY())
					{
						agregar = false;
					}
					else if (y<aux->getY() && y>aux->getIzquierda()->getY() && aux->getIzquierda()!=NULL)
					{
						aux->getIzquierda()->setDerecha(nuevaColumna);
						nuevaColumna->setIzquierda(aux->getIzquierda());
						aux->setIzquierda(nuevaColumna);
						nuevaColumna->setDerecha(aux);
						agregar = false;
					}
					else if (y>aux->getY() && y<aux->getDerecha()->getY() && aux->getDerecha()!=NULL)
					{
						aux->getDerecha()->setIzquierda(nuevaColumna);
						nuevaColumna->setDerecha(aux->getDerecha());
						aux->setDerecha(nuevaColumna);
						nuevaColumna->setIzquierda(aux);
						agregar = false;
					}
					else {
						aux = aux->getDerecha();

						temporal = aux->getDerecha();
					}
				}
				else {
					aux->setDerecha(nuevaColumna);
					nuevaColumna->setIzquierda(aux);
					agregar = false;
				}
			}
		}

	}

	void crearFila(int x) {
		NodoMatriz* nuevaFila = new NodoMatriz();
		nuevaFila->setX(x);
		NodoMatriz* aux = raiz->getAbajo();
		bool agregar = true;
		if (aux == NULL)
		{
			raiz->setAbajo(nuevaFila);
			nuevaFila->setArriba(raiz);
		}
		else {
			NodoMatriz* temporal = aux->getAbajo();
			while (agregar)
			{
				if (temporal != NULL)
				{
					if (x == aux->getX())
					{
						agregar = false;
					}
					else if (x<aux->getX() && x>aux->getArriba()->getX() && aux->getArriba() != NULL)
					{
						aux->getArriba()->setAbajo(nuevaFila);
						nuevaFila->setArriba(aux->getArriba());
						aux->setArriba(nuevaFila);
						nuevaFila->setAbajo(aux);
						agregar = false;
					}
					else if (x > aux->getX() && x < aux->getAbajo()->getX() && aux->getAbajo() != NULL)
					{
						aux->getAbajo()->setArriba(nuevaFila);
						nuevaFila->setAbajo(aux->getAbajo());
						aux->setAbajo(nuevaFila);
						nuevaFila->setArriba(aux);
						agregar = false;
					}
					else {
						aux = aux->getAbajo();

						temporal = aux->getAbajo();
					}
				}
				else {
					aux->setAbajo(nuevaFila);
					nuevaFila->setArriba(aux);
					agregar = false;
				}
			}
		}

	}

	void generarTablero(int t) {
		for (int i = 0; i < t; i++)
		{
			crearFila(i);
			crearColumna(i);
		}
	}
	void generarDobles(int x, int y) {
		NodoMatriz* doble = new NodoMatriz();
		NodoCola* vacio = new NodoCola();
		doble->setX(x);
		doble->setY(y);
		doble->setEstado("X2");
		bool exColumna = existeColumna(y);
		bool exFila = existeFila(x);
		if (exFila && exColumna)
		{
			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
		else if (exFila && exColumna==false)
		{
			crearColumna(y);
			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
		else if (exColumna && exFila==false)
		{
			crearFila(x);
			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
		else {
			crearFila(x);
			crearColumna(y);
			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
	}
	void generarTriples(int x, int y) {
		NodoMatriz* doble = new NodoMatriz();
		NodoCola* vacio = new NodoCola();
		doble->setX(x);
		doble->setY(y);
		doble->setEstado("X3");
		bool exColumna = existeColumna(y);
		bool exFila = existeFila(x);
		if (exFila && exColumna)
		{
			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
		else if (exFila && exColumna == false)
		{
			crearColumna(y);
			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
		else if (exColumna && exFila == false)
		{
			crearFila(x);
			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
		else {
			crearFila(x);

			crearColumna(y);

			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
	}
	NodoMatriz* tieneNodo(int x, int y) {

		NodoMatriz* fila = devolverFila(x);
		NodoMatriz* columna = devolverColumna(y);
		if (columna!=NULL&&fila!=NULL)
		{
			if (columna->getAbajo()!=NULL)
			{
				NodoMatriz* aux = columna->getAbajo();
				while (aux!=NULL)
				{
					if (aux->getX() == fila->getX())
					{
						return aux;
					}
					aux = aux->getAbajo();
				}
				return NULL;
			}
			return NULL;
		}
		else {
			return NULL;
		}
	}
	void agregarFicha(int x, int y, NodoCola* ficha) {
		NodoMatriz* doble = new NodoMatriz();
		doble->setX(x);
		doble->setY(y);
		doble->setNodo(ficha);
		bool exColumna = existeColumna(y);
		bool exFila = existeFila(x);
		if (exFila && exColumna)
		{
			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
		else if (exFila && exColumna == false)
		{
			crearColumna(y);
			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
		else if (exColumna && exFila == false)
		{
			crearFila(x);
			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
		else {
			crearFila(x);
			crearColumna(y);
			NodoMatriz* fila = devolverFila(x);
			NodoMatriz* columna = devolverColumna(y);
			agregarNodoColumna(columna, doble, x);
			agregarNodoFila(fila, doble, y);
		}
	}
	void agregarNodoColumna(NodoMatriz* columna, NodoMatriz* nodo, int fila) {
		if (columna->getAbajo()!=NULL)
		{
			NodoMatriz* aux = columna->getAbajo();
			bool agregar = true;
			while(agregar)
			{
				if (aux->getAbajo() != NULL)
				{
					NodoMatriz* temporal = aux->getAbajo();
					if (fila > aux->getX() && fila < temporal->getX())
					{
						aux->setAbajo(nodo);
						nodo->setArriba(aux);
						temporal->setArriba(nodo);
						nodo->setAbajo(temporal);
						agregar = false;
						break;
					}
					else if (fila < aux->getX())
					{
						aux->getArriba()->setAbajo(nodo);
						nodo->setArriba(aux->getArriba());
						aux->setArriba(nodo);
						nodo->setAbajo(aux);
						agregar = false;
						break;
					}
					else if (fila == aux->getX())
					{
						if (nodo->getNodo() != NULL)
						{
							aux->setNodo(nodo->getNodo());
						}
						else
						{
							aux->setEstado(nodo->getEstado());
						}
						agregar = false;
						break;
					}
					aux = aux->getAbajo();
				}
				else {
					if (fila > aux->getX())
					{
						aux->setAbajo(nodo);
						nodo->setArriba(aux);
						agregar = false;
						break;
					}
					else if (fila < aux->getX())
					{
						aux->getArriba()->setAbajo(nodo);
						nodo->setArriba(aux->getArriba());
						aux->setArriba(nodo);
						nodo->setAbajo(aux);
						agregar = false;
						break;
					}
					else if (fila == aux->getX())
					{
						if (nodo->getNodo() != NULL)
						{
							aux->setNodo(nodo->getNodo());
						}
						else
						{
							aux->setEstado(nodo->getEstado());
						}
						agregar = false;
						break;
					}
					agregar = false;
					break;
				}
			}
		}
		else {
			columna->setAbajo(nodo);
			nodo->setArriba(columna);
		}
	}

	void agregarNodoFila(NodoMatriz* fila, NodoMatriz* nodo, int columna) {
		if (fila->getDerecha() != NULL)
		{
			NodoMatriz* aux = fila->getDerecha();
			bool agregar = true;
			while (agregar)
			{
				if (aux->getDerecha() != NULL)
				{
					NodoMatriz* temporal = aux->getDerecha();
					if (columna > aux->getY() && columna < temporal->getY())
					{
						aux->setDerecha(nodo);
						nodo->setIzquierda(aux);
						temporal->setIzquierda(nodo);
						nodo->setDerecha(temporal);
						agregar = false;
						break;
					}
					else if (columna < aux->getY())
					{
						aux->getIzquierda()->setDerecha(nodo);
						nodo->setIzquierda(aux->getIzquierda());
						aux->setIzquierda(nodo);
						nodo->setDerecha(aux);
						agregar = false;
						break;
					}
					else if (columna == aux->getY())
					{
						if (nodo->getNodo() != NULL)
						{
							aux->setNodo(nodo->getNodo());
						}
						else
						{
							aux->setEstado(nodo->getEstado());
						}
						agregar = false;
						break;
					}
					aux = aux->getDerecha();
				}
				else {
					if (columna > aux->getY())
					{
						aux->setDerecha(nodo);
						nodo->setIzquierda(aux);
						agregar = false;
						break;
					}
					else if (columna < aux->getY())
					{
						aux->getIzquierda()->setDerecha(nodo);
						nodo->setIzquierda(aux->getIzquierda());
						aux->setIzquierda(nodo);
						nodo->setDerecha(aux);
						agregar = false;
						break;
					}
					else if (columna == aux->getY())
					{
						if (nodo->getNodo() != NULL)
						{
							aux->setNodo(nodo->getNodo());
						}
						else
						{
							aux->setEstado(nodo->getEstado());
						}
						agregar = false;
						break;
					}
					agregar = false;
					break;
				}
			}
		}
		else {
			fila->setDerecha(nodo);
			nodo->setIzquierda(fila);
		}
	}
	void graficar() {
		string grafica = "digraph Tablero{\nrankdir=\u0022LR\u0022;\n";
		NodoMatriz* columna = new NodoMatriz(); 
		NodoMatriz* fila = new NodoMatriz();
		string ranksame = "";

		NodoMatriz* fin = new NodoMatriz();
		int i = 0;
		grafica += "Raiz[shape=box;style=filled;pos=\u0022-1,-1!\u0022];\n";
		if (raiz->getDerecha() != NULL && raiz->getAbajo() != NULL)
		{
			columna = raiz->getDerecha();
			fila = raiz->getAbajo();
		}
		//columnas raiz
		while (fila != NULL)
		{
			grafica += "F"+to_string(fila->getX())+"[shape=box;style=filled;pos=\u0022-1,"+ to_string(fila->getX()) +"!\u0022];\n";
			fila = fila->getAbajo();
		}

		fila = raiz->getAbajo();
		grafica += "Raiz -> F" + to_string(fila->getX()) + ";\n";
		grafica += "F" + to_string(fila->getX()) + "->Raiz;\n";
		while (fila != NULL)
		{
			if (fila->getAbajo()!=NULL)
			{
				grafica += "F" + to_string(fila->getX()) + " -> F" + to_string(fila->getAbajo()->getX()) + ";\n";
				grafica += "F" + to_string(fila->getAbajo()->getX()) + " -> F" + to_string(fila->getX()) + ";\n";
			}
			if (fila->getDerecha()!=NULL)
			{
				grafica += "F" + to_string(fila->getX()) + " -> X" + to_string(fila->getDerecha()->getX()) + "Y"+to_string(fila->getDerecha()->getY())+";\n";
				grafica += "X" + to_string(fila->getDerecha()->getX()) + "Y" + to_string(fila->getDerecha()->getY()) + " -> F" + to_string(fila->getX()) + ";\n";
			}
			fila = fila->getAbajo();
		}
		i=2;
		NodoMatriz* ultimo = new NodoMatriz();
		while (columna != NULL) {
			grafica += "C" + to_string(columna->getY()) + "[shape=box;style=filled;pos=\u0022" + to_string(columna->getY()) +",-1!\u0022];\n";
			
			ultimo = columna;
			columna = columna->getDerecha();
			i++;
		}
		columna = raiz->getDerecha();
		grafica += "Raiz -> C" + to_string(columna->getY()) + ";\n";
		grafica += "C" + to_string(columna->getY()) + "->Raiz;\n";
		while (columna!=NULL)
		{
			if (columna->getDerecha() != NULL)
			{
				grafica += "C" + to_string(columna->getY()) + " -> C" + to_string(columna->getDerecha()->getY()) + ";\n";
				grafica += "C" + to_string(columna->getDerecha()->getY()) + " -> C" + to_string(columna->getY()) + ";\n";
			}
			columna = columna->getDerecha();
		}
		i = 2;
		columna = raiz->getDerecha();
		while (columna != NULL)
		{
			if (columna->getAbajo()!=NULL)
			{

				grafica += "C" + to_string(columna->getY()) + " -> X" + to_string(columna->getAbajo()->getX()) + "Y" + to_string(columna->getAbajo()->getY()) + ";\n";
				grafica += "X" + to_string(columna->getAbajo()->getX()) + "Y" + to_string(columna->getAbajo()->getY()) + " -> C" + to_string(columna->getY()) + ";\n";

				fila = columna->getAbajo();

				while (fila!=NULL)
				{
					if (fila->getNodo()!=NULL)
					{
						grafica += "X" + to_string(fila->getX()) + "Y" + to_string(fila->getY()) + "[shape=box;style=filled;label=\u0022" + fila->getNodo()->getCaracter() + "\u0022;pos=\u0022"+ to_string(fila->getY()) +","+ to_string(fila->getX()) +"!\u0022];\n";
					}
					else {
						grafica += "X" + to_string(fila->getX()) + "Y" + to_string(fila->getY()) + "[shape=box;style=filled;label=\u0022" + fila->getEstado() + "\u0022; pos=\u0022" + to_string(fila->getY()) + "," + to_string(fila->getX()) + "!\u0022];\n";
					}

					if (fila->getAbajo() != NULL)
					{
						grafica += "X" + to_string(fila->getX()) + "Y"+ to_string(fila->getY()) +"-> X" + to_string(fila->getAbajo()->getX()) + "Y" + to_string(fila->getAbajo()->getY()) + ";\n";
						grafica += "X" + to_string(fila->getAbajo()->getX()) + "Y"+to_string(fila->getAbajo()->getY())+" -> X" + to_string(fila->getX()) + "Y" + to_string(fila->getY()) + ";\n";
					}
					if (fila->getDerecha() != NULL)
					{
						grafica += "X" + to_string(fila->getX()) + "Y"+ to_string(fila->getY()) +" -> X" + to_string(fila->getDerecha()->getX()) + "Y" + to_string(fila->getDerecha()->getY()) + ";\n";
						grafica += "X" + to_string(fila->getDerecha()->getX()) + "Y" + to_string(fila->getDerecha()->getY()) + " -> X" + to_string(fila->getX()) + "Y" + to_string(fila->getY()) + ";\n";
					}
					if (fila->getX()==fin->getX())
					{

						fin = fila;
					}
					fila = fila->getAbajo();
				}
			}
			i++;
			columna = columna->getDerecha();
		}
		fila = raiz->getAbajo();
		
		
		grafica += "}\n";
		ofstream archivo;
		archivo.open("Tablero.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Kfdp -n -Tjpg -o Tablero.jpg Tablero.txt");
	}
};