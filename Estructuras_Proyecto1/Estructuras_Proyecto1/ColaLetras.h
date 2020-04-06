#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include "NodoCola.h"

using namespace std;

class ColaLetras {
private:
	
public:
	NodoCola* primero;

	bool listaVacia() {
		if (primero!=NULL)
		{
			return false;
		}
		else {
			true;
		}
	}
	void revolver() {
		primero = NULL;
		string letras = "a-1\n" ;
		letras += "a-1\n" ;
		letras += "a-1\n" ;
		letras += "a-1\n" ;
		letras += "a-1\n" ;
		letras += "a-1\n" ;
		letras += "a-1\n" ;
		letras += "r-1\n" ;
		letras += "a-1\n" ;
		letras += "a-1\n" ;
		letras += "a-1\n" ;
		letras += "a-1\n" ;
		letras += "e-1\n" ;
		letras += "e-1\n" ;
		letras += "e-1\n" ;
		letras += "e-1\n" ;
		letras += "e-1\n" ;
		letras += "e-1\n" ;
		letras += "e-1\n" ;
		letras += "e-1\n" ;
		letras += "e-1\n" ;
		letras += "e-1\n" ;
		letras += "e-1\n" ;
		letras += "e-1\n" ;
		letras += "o-1\n" ;
		letras += "o-1\n" ;
		letras += "o-1\n" ;
		letras += "o-1\n" ;
		letras += "o-1\n" ;
		letras += "o-1\n" ;
		letras += "o-1\n" ;
		letras += "o-1\n" ;
		letras += "i-1\n" ;
		letras += "i-1\n" ;
		letras += "i-1\n" ;
		letras += "i-1\n" ;
		letras += "i-1\n" ;
		letras += "i-1\n" ;
		letras += "s-1\n" ;
		letras += "s-1\n" ;
		letras += "s-1\n" ;
		letras += "s-1\n" ;
		letras += "s-1\n" ;
		letras += "s-1\n" ;
		letras += "n-1\n" ;
		letras += "n-1\n" ;
		letras += "n-1\n" ;
		letras += "n-1\n" ;
		letras += "n-1\n" ;
		letras += "l-1\n" ;
		letras += "l-1\n" ;
		letras += "l-1\n" ;
		letras += "l-1\n" ;
		letras += "r-1\n" ;
		letras += "r-1\n" ;
		letras += "r-1\n" ;
		letras += "h-4\n" ;
		letras += "r-1\n" ;
		letras += "u-1\n" ;
		letras += "u-1\n" ;
		letras += "u-1\n" ;
		letras += "u-1\n" ;
		letras += "u-1\n" ;
		letras += "t-1\n" ;
		letras += "t-1\n" ;
		letras += "t-1\n" ;
		letras += "t-1\n" ;
		letras += "d-2\n" ;
		letras += "d-2\n" ;
		letras += "d-2\n" ;
		letras += "d-2\n" ;
		letras += "d-2\n" ;
		letras += "g-2\n" ;
		letras += "g-2\n" ;
		letras += "c-3\n" ;
		letras += "c-3\n" ;
		letras += "c-3\n" ;
		letras += "c-3\n" ;
		letras += "b-3\n" ;
		letras += "b-3\n" ;
		letras += "m-3\n" ;
		letras += "m-3\n" ;
		letras += "p-3\n" ;
		letras += "p-3\n" ;
		letras += "h-4\n" ;
		letras += "f-4\n" ;
		letras += "v-4\n" ;
		letras += "y-4\n" ;
		letras += "q-5\n" ;
		letras += "a-1\n" ;
		letras += "j-8\n" ;
		letras += "ñ-8\n" ;
		letras += "x-8\n" ;
		letras += "z-10";
		int g = 94;
		string cantidad[94];
		int i = 0;
		for (size_t p = 0, q = 0; p != letras.npos; p = q)
		{
			cantidad[i] = letras.substr(p + (p != 0), (q = letras.find('\n', p + 1)) - p - (p != 0));
			i++;
		}
		while(g != 0)
		{
			string valores[2];
			int t = 0;

			srand(time(NULL));
			int j = rand()%g;

			for (size_t p = 0, q = 0; p != cantidad[j].npos; p = q)
			{
				valores [t]= cantidad[j].substr(p + (p != 0), (q = cantidad[j].find('-', p + 1)) - p - (p != 0));
				t++;
			}
			char c = valores[0][0];
			int n = stoi(valores[1]);
			encolar(c, n);
			for (int y = 0; y < g; y++) {
				if (y == j) {
					while (y < g - 1) {
						cantidad[y] = cantidad[y + 1];
						y++;
					}
					break;
				}
			}
			g--;
		}
		
	}
	void encolar(char c, int punteo) {
		NodoCola* nuevo = new NodoCola();
		nuevo->setCaracter(c);
		nuevo->setPunteo(punteo);
		if (listaVacia())
		{
			primero = nuevo;
		}
		else {
			nuevo->setSiguiente(primero);
			primero->setAnterior(nuevo);
			primero = nuevo;
		}
	}
	NodoCola* desencolar() {
		NodoCola* aux = primero;
		while (aux!=NULL) {
			if (aux->getSiguiente()==NULL)
			{
				NodoCola* temporal = aux->getAnterior();
				temporal->setSiguiente(NULL);
				return aux;
			}
			aux = aux->getSiguiente();
		}
		return NULL;
	}
	void graficarCola() {
		NodoCola* aux = primero;
		string grafica = "digraph ColaLetras{\nrankdir=\u0022TB\u0022;\n";
		int i = 0;
		while (aux!=NULL)
		{
			grafica += "node"+ to_string(i) +" [label=\u0022"+aux->getCaracter()+" - "+ to_string(aux->getPunteo()) +"\u0022]\n";
			i++;
			aux = aux->getSiguiente();
		}
		int j = 0;
		int l = 1;
		aux = primero;
		while (aux != NULL)
		{
			if (aux->getSiguiente()!=NULL)
			{
				grafica += "node"+ to_string(j) +" -> node"+ to_string(l) +";\n";
			}
			j++;
			l++;
			aux = aux->getSiguiente();
		}
		grafica += "}";
		ofstream archivo;
		archivo.open("ColaLetras.txt", ios::out);

		if (archivo.fail())
		{
			cout << "Error: no se pudo abrir el archivo";
			exit(1);
		}
		archivo << grafica;

		archivo.close();

		system("dot -Tjpg ColaLetras.txt -o ColaLetras.jpg -Gcharset=latin1");
	}
};