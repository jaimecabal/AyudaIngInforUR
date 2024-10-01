#include "pila.h"

/*
Implementación estática del tad pila mediante un registro con dos
campos: uno de ellos es un vector que contiene los datos de la pila
y el otro es un entero que nos indica el número de datos que hay
almacenados en la pila.
*/


void iniciarPila(pila & P)
/*
{Pre: }
{Post: Inicia P como una pila vacía}
*/
{
	P.num=0;
}

void apilar(pila & P ,telemento d)
/*
{Pre: la pila P ha debido ser previamente inicializada }
{Post: Apila en la pila P el elemento d}
*/
{
	if (P.num<MAX-1)
	{

		P.datos[P.num]=d;
		P.num=P.num+1;
	}
}


bool pilaVacia(pila P)
/*
{Pre: la pila P ha debido ser previamente inicializada }
{Post: Si la pila P está vacía devuelve el valor verdad. En caso contrario devuelve el valor falso}
*/
{
	return (P.num==0);
}


telemento cima(pila P)
/*
{Pre: la pila P ha debido ser previamente inicializada y no está vacía}
{Post:Devuelve el elemento más reciente en la pila P y no modifica P}
*/
{
	return(P.datos[P.num-1]);
}


void desapilar(pila & P)
/*
{Pre: la pila P ha debido ser previamente inicializada y no está vacía}
{Post: Modifica la pila P eliminando el último elemento apilado}
*/
{
	P.num=P.num-1;

}


