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

	NodoMatriz* raiz = new NodoMatriz();
	int tx = 0;
	int ty = 0;

	void iniciartablero() {
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
	}
	void generarTriples(int x, int y) {
		NodoMatriz* doble = new NodoMatriz();
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
	}
	void agregarFicha(int x, int y, NodoCola* ficha) {
		NodoMatriz* doble = new NodoMatriz();
		doble->setX(x);
		doble->setY(y);
		doble->setEstado("X1");
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
	}
	void agregarNodoColumna(NodoMatriz* columna, NodoMatriz* nodo, int fila) {
		NodoMatriz* aux = columna->getAbajo();
		bool agregar = true;
		if (aux==NULL)
		{
			columna->setAbajo(nodo);
			nodo->setArriba(columna);
		}
		else {
			NodoMatriz* temporal = aux;
			aux = aux->getAbajo();
			while (agregar)
			{
				if (aux!=NULL)
				{
					if (fila == temporal->getX())
					{
						nodo->setAbajo(temporal->getAbajo());
						nodo->setArriba(temporal->getArriba());
						temporal->getArriba()->setAbajo(nodo);
						temporal->getAbajo()->setArriba(nodo);
						agregar = false;
					}
					else if (fila > temporal->getX() && fila<aux->getX())
					{
						temporal->setAbajo(nodo);
						nodo->setArriba(temporal);
						aux->setArriba(nodo);
						nodo->setAbajo(aux);
						agregar = false;
					}
					else if (fila < temporal->getX() && fila > temporal->getArriba()->getX())
					{
						temporal->getArriba()->setAbajo(nodo);
						nodo->setArriba(temporal->getArriba());
						temporal->setArriba(nodo);
						nodo->setAbajo(temporal);
						agregar = false;
					}
					else {
						temporal = aux;
						aux = aux->getAbajo();
					}
				}
				else {
					temporal->setAbajo(nodo);
					nodo->setArriba(temporal);
					agregar = false;
				}
			}
		}
	}

	void agregarNodoFila(NodoMatriz* fila, NodoMatriz* nodo, int columna) {
		NodoMatriz* aux = fila->getDerecha();
		bool agregar = true;
		if (aux == NULL)
		{
			fila->setDerecha(nodo);
			nodo->setIzquierda(fila);
		}
		else {
			NodoMatriz* temporal = aux;
			aux = aux->getDerecha();
			while (agregar)
			{
				if (aux != NULL)
				{
					if (columna == temporal->getY())
					{
						nodo->setDerecha(temporal->getDerecha());
						nodo->setIzquierda(temporal->getIzquierda());
						temporal->getIzquierda()->setDerecha(nodo);
						temporal->getDerecha()->setIzquierda(nodo);
						agregar = false;
					}
					else if (columna > temporal->getY() && columna < aux->getY())
					{
						temporal->setDerecha(nodo);
						nodo->setIzquierda(temporal);
						aux->setIzquierda(nodo);
						nodo->setDerecha(aux);
						agregar = false;
					}
					else if (columna < temporal->getY() && columna > temporal->getIzquierda()->getY())
					{
						temporal->getIzquierda()->setDerecha(nodo);
						nodo->setIzquierda(temporal->getIzquierda());
						temporal->setIzquierda(nodo);
						nodo->setDerecha(temporal);
						agregar = false;
					}
					else {
						temporal = aux;
						aux = aux->getDerecha();
					}
				}
				else {
					temporal->setDerecha(nodo);
					nodo->setIzquierda(temporal);
					agregar = false;
				}
			}
		}
	}
	void graficar() {
		string grafica = "digraph Tablero{\n";
		NodoMatriz* columna = raiz->getDerecha();
		NodoMatriz* fila = raiz->getAbajo();
		int i=0;
		grafica += "subgraph N%i{\nrankdir=\u0022LR\u0022;\n Raiz;\n",i;
		i++;
		//columnas raiz
		while (columna!=NULL)
		{
			grafica += "C%i;", columna->getY();
			columna = columna->getDerecha();
		}
		grafica += "}\n";

		while (fila != NULL) {
			grafica += "subgraph N%i{\nrankdir=\u0022LR\u0022;\n F%i;\n",i,fila->getX();
			columna = fila->getDerecha();
			i++;
			while (columna!=NULL)
			{
				grafica += "node%i%i[label=\u0022%c\u0022];\n",columna->getX(),columna->getY(),columna->getNodo()->getCaracter();
				columna = columna->getDerecha();
			}
			grafica += "}\n";
			fila = fila->getAbajo();
		}
		grafica += "Raiz -> C%;\n Raiz -> F%;\n", raiz->getDerecha()->getY(), raiz->getAbajo()->getX();
		columna = raiz->getDerecha();
		
		//apuntar columnas
		while (columna!=NULL)
		{
			if (columna->getDerecha()!=NULL)
			{
				grafica += "C% -> C%;\n",columna->getY(),columna->getDerecha()->getY();
			}
			if (columna->getAbajo() != NULL)
			{
				grafica += "C% -> node%i%i;\n", columna->getY(), columna->getAbajo()->getX(), columna->getAbajo()->getY();
			}
			if (columna->getIzquierda() != NULL)
			{
				if (columna->getIzquierda()==raiz)
				{
					grafica += "C% -> Raiz;\n", columna->getY();
				}
				else {
					grafica += "C% -> C%;\n", columna->getY(), columna->getIzquierda()->getY();
				}
			}
			columna = columna->getDerecha();
		}

	}
};