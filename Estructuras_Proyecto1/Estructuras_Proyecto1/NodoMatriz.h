#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include "NodoCola.h"

using namespace std;

class NodoMatriz {
private:
	int x;
	int y;
	string estado;
	NodoCola* nodo;
	NodoMatriz* arriba;
	NodoMatriz* abajo;
	NodoMatriz* izquierda;
	NodoMatriz* derecha;
public:

	void setX(int x1) { x = x1; }
	void setY(int y1) { y = y1; }
	void setNodo(NodoCola* ficha) { nodo = ficha; }
	void setArriba(NodoMatriz* arr) { arriba = arr; }
	void setAbajo(NodoMatriz* x1) { abajo = x1; }
	void setIzquierda(NodoMatriz* x1) { izquierda = x1; }
	void setDerecha(NodoMatriz* x1) { derecha = x1; }
	void setEstado(string est) { estado = est; }

	int getX() { return x; }
	int getY() { return y; }
	NodoCola* getNodo() { return nodo; }
	NodoMatriz* getArriba() { return arriba; }
	NodoMatriz* getAbajo() { return abajo; }
	NodoMatriz* getIzquierda() { return izquierda; }
	NodoMatriz* getDerecha() { return derecha; }
	string getEstado() { return estado; }

};