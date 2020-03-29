#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include "NodoPuntaje.h"

using namespace std;

class Jugador {
private:
	string usuario;
	NodoPuntaje* puntajes;
	Jugador* izquierda;
	Jugador* derecha;
public:
	void setUsuario(string user) {
		usuario = user;
	}
	string getUsuario() {
		return usuario;
	}
	void setNodoPuntaje(NodoPuntaje* np) {
		puntajes = np;
	}
	NodoPuntaje* getNodoPuntaje() {
		return puntajes;
	}
	void setIzquierda(Jugador* ji) {
		izquierda = ji;
	}
	Jugador* getIzquierda() {
		return izquierda;
	}
	void setDerecha(Jugador* ji) {
		derecha = ji;
	}
	Jugador* getDerecha() {
		return derecha;
	}
};