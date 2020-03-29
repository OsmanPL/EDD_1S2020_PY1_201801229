#pragma once
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

class NodoDiccionario {
private:
	string palabra;
	NodoDiccionario* siguiente;
	NodoDiccionario* anterior;

public:
	~NodoDiccionario();
	void setPalabra(string cadena) {
		palabra = cadena;
	}
	string getPalabra() {
		return palabra;
	}
	void setSiguiente(NodoDiccionario* sig) {
		siguiente = sig;
	}
	NodoDiccionario* getSiguiente() {
		return siguiente;
	}
	void setAnterior(NodoDiccionario* ant) {
		anterior = ant;
	}
	NodoDiccionario* getAnterior() {
		return anterior;
	}
};
