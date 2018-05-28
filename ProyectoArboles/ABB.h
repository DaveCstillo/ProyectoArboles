#pragma once


/*---------  Estructura del arbol ABB  -------*/
typedef struct ABBnodo {
	int nro;
	struct ABBnodo *izq, *der;
}*ABB;

int numNodosABB = 0; // nummero de nodos del arbol ABB
int numK = 0, k;     //  nodos menores que un numero k ingresado


					 /* ---------- Estructura de la cola ---------*/
struct nodoCola {
	ABB ptr;
	struct nodoCola *sgte;
};
struct cola {
	struct nodoCola *delante;
	struct nodoCola *atras;
};

ABB desencola(struct cola &q)
{
	struct nodoCola *p;
	p = q.delante;
	ABB n = p->ptr;
	q.delante = (q.delante)->sgte;
	delete(p);
	return n;
}


ABB unirABB(ABB izq, ABB der)
{
	if (izq == NULL) return der;
	if (der == NULL) return izq;

	ABB centro = unirABB(izq->der, der->izq);
	izq->der = centro;
	der->izq = izq;
	return der;
}

//-------Creacion de un nuevo nodo para el arbol ABB------------//
ABB crearNodo(int x)
{
	ABB nuevoNodo = new(struct ABBnodo);
	nuevoNodo->nro = x;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;

	return nuevoNodo;
}
