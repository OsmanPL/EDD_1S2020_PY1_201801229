#pragma once
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

class NodoPuntaje {
private:
	string nombreJugador;
	int puntaje;
	NodoPuntaje* siguiente;
public:
	void setNombreJugador(string nombre) {
		nombreJugador = nombre;
	}
	string getNombreJugador() {
		return nombreJugador;
	}
	void setPuntaje(int puntos) {
		puntaje = puntos;
	}
	int getPuntaje() {
		return puntaje;
	}
	void setSiguiente(NodoPuntaje* sig) {
		siguiente = sig;
	}
	NodoPuntaje* getSiguiente() {
		return siguiente;
	}
};