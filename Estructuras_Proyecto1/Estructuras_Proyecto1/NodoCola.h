#pragma once

#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

class NodoCola {
private:
	char caracter;
	int punteo;
	NodoCola* siguiente;
	NodoCola* anterior;
public:
	void setCaracter(char c) {
		caracter = c;
	}
	char getCaracter() {
		return caracter;
	}
	void setPunteo(int puntos) {
		punteo = puntos;
	}
	int getPunteo() {
		return punteo;
	}
	void setSiguiente(NodoCola* sig) {
		siguiente = sig;
	}
	NodoCola* getSiguiente() {
		return siguiente;
	}
	void setAnterior(NodoCola* ant) {
		anterior = ant;
	}
	NodoCola* getAnterior() {
		return anterior;
	}
};