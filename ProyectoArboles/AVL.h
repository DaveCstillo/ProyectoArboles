#pragma once
#include <iostream>

/*---------  Estructura del arbol AVL  -------*/

typedef struct AVLnodo {
	int nro;
	int hDer, hIzq;
	int FE;
	struct AVLnodo *izq, *der;
}AVL;

int numNodosAVL = 0; // nummero de nodos del arbol AVL


					 //-------Creacion de un nuevo nodo para el arbol AVL------------//

AVL* crearNodoAVL(int x)
{
	AVL* Nodo = new(struct AVLnodo);
	Nodo->nro = x;
	Nodo->izq = NULL;
	Nodo->der = NULL;
	Nodo->hIzq = 0;
	Nodo->hDer = 0;
	Nodo->FE = 0;

	return Nodo;
}
