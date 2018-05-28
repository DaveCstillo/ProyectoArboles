#include <iostream>
#include "ABB.h"

using namespace std;

void inicializaCola(struct cola &q)
{
	q.delante = NULL;
	q.atras = NULL;
}

void encola(struct cola &q, ABB n)
{
	struct nodoCola *p;
	p = new(struct nodoCola);
	p->ptr = n;
	p->sgte = NULL;
	if (q.delante == NULL)
		q.delante = p;
	else
		(q.atras)->sgte = p;
	q.atras = p;
}


//------Metodo de insertar en el arbol ABB------------//

void insertar(ABB &arbol, int x)
{
	system("cls");
	if (arbol == NULL)
	{
		arbol = crearNodo(x);
		cout << "\n\t  Insertado..!" << endl << endl;
		system("cls");
	}
	else if (x < arbol->nro)
		insertar(arbol->izq, x);
	else if (x > arbol->nro)
		insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		cout << arbol->nro << " ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void enOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		enOrden(arbol->izq);
		cout << arbol->nro << " ";
		enOrden(arbol->der);
	}
}

void postOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		enOrden(arbol->izq);
		enOrden(arbol->der);
		cout << arbol->nro << " ";
	}
}

void verArbol(ABB arbol, int n)
{
	if (arbol == NULL)
		return;
	verArbol(arbol->der, n + 1);

	for (int i = 0; i<n; i++)
		cout << "   ";

	numNodosABB++;
	cout << arbol->nro << endl;

	verArbol(arbol->izq, n + 1);
}

bool busquedaRec(ABB arbol, int dato)
{
	int r = 0;   // 0 indica que no lo encontre

	if (arbol == NULL)
		return r;

	if (dato<arbol->nro)
		r = busquedaRec(arbol->izq, dato);

	else if (dato> arbol->nro)
		r = busquedaRec(arbol->der, dato);

	else
		r = 1;   // son iguales, lo encontre

	return r;
}


void elimina(ABB &arbol, int x)
{
	if (arbol == NULL) return;

	if (x<arbol->nro)
		elimina(arbol->izq, x);
	else if (x>arbol->nro)
		elimina(arbol->der, x);

	else
	{
		ABB p = arbol;
		arbol = unirABB(arbol->izq, arbol->der);
		delete p;
	}
	system("PAUSE");
}



void recorrerxNivel(ABB arbol)
{
	struct cola q;
	inicializaCola(q);
	cout << "\t";

	if (arbol != NULL)
	{
		encola(q, arbol);

		while (q.delante != NULL)
		{
			arbol = desencola(q);
			cout << arbol->nro << ' ';

			if (arbol->izq != NULL)
				encola(q, arbol->izq);
			if (arbol->der != NULL)
				encola(q, arbol->der);
		}
	}
}
