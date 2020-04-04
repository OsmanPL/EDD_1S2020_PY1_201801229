
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include "NodoDiccionario.h"
using namespace std;

class Diccionario {
private:
	
public:
	NodoDiccionario* primero;
	NodoDiccionario* ultimo;

	void insertar(string palabra) {
		NodoDiccionario* nuevo = new NodoDiccionario();
		nuevo->setPalabra(palabra);
		if (listaVacia())
		{
			nuevo->setSiguiente(primero);
			nuevo->setAnterior(ultimo);
			primero->setAnterior(nuevo);
			ultimo->setSiguiente(nuevo);
			primero = nuevo;
		}
		else {
			primero = nuevo;
			ultimo = nuevo;
			primero->setSiguiente(ultimo);
			primero->setAnterior(ultimo);
			ultimo->setSiguiente(primero);
			ultimo->setAnterior(primero);
		}
	}
	bool listaVacia() {
		if (primero!=NULL && ultimo != NULL)
		{
			return true;
		}
		else {
			return false;
		}
	}
	void vaciarLista() {
		primero = NULL;
		ultimo = NULL;
	}
	NodoDiccionario* buscar(string buscar) {
		NodoDiccionario* aux = primero;
		if (aux!=NULL)
		{
			do {
				if (aux->getPalabra() == buscar)
				{
					return aux;
				}
				aux = aux->getSiguiente();
			} while (aux != primero);
		}
		return NULL;
		
	}
	void grficar() {
		string grafica = "digraph Diccionario{\n rankdir=\u0022LR\u0022;\n";
		NodoDiccionario* aux = primero;
		int i = 0;
		if (aux!=NULL)
		{
			do {
				grafica += "node"+ to_string(i) +" [label=\u0022 "+aux->getPalabra()+" \u0022];";
				i++;
				aux = aux->getSiguiente();
			} while (aux!=primero);
		}
		int ultimo = i - 1;
		int l = 1;
		int j = 0;
		if (aux != NULL)
		{
			do {
				if (j == ultimo) {

					grafica += "node"+ to_string(j) +" -> node0 ;\n",j;
					grafica += "node0 -> node"+ to_string(j) +" ;\n",j;
				}
				else {
					grafica += "node"+ to_string(j) +" -> node"+ to_string(l) +" ;\n",j,l;
					grafica += "node"+ to_string(l) +" -> node"+ to_string(j) +" ;\n", l, j;
				}
				j++;
				l++;
				aux = aux->getSiguiente();
			} while (aux != primero);
		}
		grafica += "}";
		ofstream archivo;
		archivo.open("Diccionario.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Tjpg Diccionario.txt -o Diccionario.jpg -Gcharset=latin1");
	}
};