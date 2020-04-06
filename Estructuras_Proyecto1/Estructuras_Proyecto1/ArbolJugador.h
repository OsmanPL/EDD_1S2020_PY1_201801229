#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include "Jugador.h"

using namespace std;

class ArbolJugador {
private:
public:
	Jugador* raiz;
	int i = 0;
	int j = 0;
	int k = 0;
	Jugador* ultimoInorden;
	Jugador* ultimoPreorden;
	Jugador* ultimoPostorden;
	bool arbolVacio() {
		if (raiz!=NULL)
		{
			return false;
		}
		else {
			return true;
		}
	}
	void crearJugador(string nombre) {
		Jugador* nuevo = new Jugador();
		nuevo->setUsuario(nombre);
		NodoPuntaje* nuevoPuntaje = new NodoPuntaje();
		nuevo->setNodoPuntaje(nuevoPuntaje);
		if (arbolVacio())
		{
			raiz = nuevo;
		}
		else {
			insertar(raiz, nuevo);
		}
	}
	Jugador* buscarJugador(string nombre, Jugador* actual) {
		int resultado = orden(actual->getUsuario(), nombre);
		if (resultado == 0)
		{
			return actual;
		}
		else if (resultado > 0)
		{
			if (actual->getIzquierda() != NULL)
			{
				return buscarJugador(nombre, actual->getIzquierda());
			}
			else { return NULL; }
		}
		else if (resultado < 0)
		{
			if (actual->getDerecha() != NULL)
			{
				return buscarJugador(nombre, actual->getDerecha());
			}
			else { return NULL; }
		}
	}
	Jugador* iniciarBusqueda(string buscar) {
		return buscarJugador(buscar, raiz);
	}
	void insertar(Jugador* actual, Jugador* nuevo) {
		int resultado = orden(actual->getUsuario(), nuevo->getUsuario());
		if (resultado == 0)
		{

		}
		else if (resultado > 0)
		{
			if (actual->getIzquierda()!=NULL)
			{
				insertar(actual->getIzquierda(), nuevo);
			}
			else {
				actual->setIzquierda(nuevo);
			}
		}
		else if (resultado < 0)
		{
			if (actual->getDerecha() != NULL)
			{
				insertar(actual->getDerecha(), nuevo);
			}
			else {
				actual->setDerecha(nuevo);
			}
		}
	}
	int orden(string actual, string nuevo) {
		const char* nodoviejo = &actual[0];
		const char* nodonuevo = &nuevo[0];
		return strcmp(nodoviejo, nodonuevo);
	}
	void iniciarGrafica() {
		Jugador* aux = raiz;
		string grafica = "digraph Jugadores{\n";
		grafica += graficar(aux);
		grafica += "}";
		ofstream archivo;
		archivo.open("ArbolJugadores.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Tjpg ArbolJugadores.txt -o ArbolJugadores.jpg");
	}
	string graficar(Jugador* actual) {
		string grafica = "";
		int l = i;
		grafica += "node"+ to_string(l) +" [label=\u0022"+actual->getUsuario()+"\u0022];\n";
		if (actual->getIzquierda()!=NULL)
		{

			i++;
			grafica += "node"+ to_string(l) +" -> node"+ to_string(i) +";\n";
			
			grafica += graficar(actual->getIzquierda());
		}
		if (actual->getDerecha() != NULL)
		{
			i++;
			grafica += "node"+ to_string(l) +" -> node"+ to_string(i) +";\n";
			grafica += graficar(actual->getDerecha());
		}
		return grafica;
	}
	void iniciarInorden() {
		Jugador* aux = raiz;
		string grafica = "digraph Inorden{\nrankdir=\u0022LR\u0022;\n";
		grafica += inorden(aux);
		grafica += "}";
		ofstream archivo;
		archivo.open("Inorden.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Tjpg Inorden.txt -o Inorden.jpg");
	}
	string inorden(Jugador* actual) {
		string grafica = "";
		
		if (actual->getIzquierda()!=NULL)
		{
			grafica += inorden(actual->getIzquierda());
			grafica += ultimoInorden->getUsuario() + " -> " + actual->getUsuario()+";\n";
			ultimoInorden = actual;
		}
		grafica += actual->getUsuario() + ";\n";
		ultimoInorden = actual;
		if (actual->getDerecha()!=NULL)
		{
			grafica += ultimoInorden->getUsuario() + " -> " + actual->getDerecha()->getUsuario() + ";\n";
			ultimoInorden = actual->getDerecha();
			grafica += inorden(actual->getDerecha());
			
		}
		return grafica;
	}
	void iniciarPreorden() {
		Jugador* aux = raiz;
		string grafica = "digraph Inorden{\nrankdir=\u0022LR\u0022;\n";
		grafica += preorden(aux);
		grafica += "}";
		ofstream archivo;
		archivo.open("Preorden.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Tjpg Preorden.txt -o Preorden.jpg");
	}
	string preorden(Jugador* actual) {
		string grafica = "";
		grafica += actual->getUsuario() + ";\n";
		ultimoPreorden = actual;
		if (actual->getIzquierda() != NULL)
		{
			grafica += ultimoPreorden->getUsuario() + " -> " + actual->getIzquierda()->getUsuario() + ";\n";
			ultimoPreorden = actual->getIzquierda();
			grafica += preorden(actual->getIzquierda());
		}
		if (actual->getDerecha() != NULL)
		{
			grafica += ultimoPreorden->getUsuario() + " -> " + actual->getDerecha()->getUsuario() + ";\n";
			grafica += preorden(actual->getDerecha());
			ultimoPreorden = actual->getDerecha();
		}
		return grafica;
	}
	void iniciarPostorden() {
		Jugador* aux = raiz;
		string grafica = "digraph Inorden{\nrankdir=\u0022LR\u0022;\n";
		grafica += postorden(aux);
		grafica += "}";
		ofstream archivo;
		archivo.open("Postorden.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Tjpg Postorden.txt -o Postorden.jpg");
	}
	string postorden(Jugador* actual) {
		string grafica = "";
		if (actual->getIzquierda() != NULL)
		{
			ultimoPostorden = actual->getIzquierda();
			grafica += postorden(actual->getIzquierda());
		}
		if (actual->getDerecha() != NULL)
		{
			grafica += ultimoPostorden->getUsuario() + " -> " + actual->getDerecha()->getUsuario() + ";\n";
			ultimoPostorden = actual->getDerecha();
			grafica += postorden(actual->getDerecha());
			grafica += ultimoPostorden->getUsuario() + " -> " + actual->getUsuario() + ";\n";
		}
		grafica += actual->getUsuario() + ";\n";
		ultimoPostorden = actual;
		return grafica;
	}
	Jugador* devolverRaiz() {
		return raiz;
	}
};