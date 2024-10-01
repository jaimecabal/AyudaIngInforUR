#include<iostream>
#include<cstdlib>
using namespace std;

//Vamos a trabajar con pilas de enteros
typedef int telemento;

//número máximo de datos que habrá en la pila
const int MAX= 1000;

struct pila
{

	int num;//número de datos que hay en la pila
	telemento  datos [MAX];
};


void iniciarPila(pila & P);
/*
{Pre: }
{Post: Inicia P como una pila vacía}
*/

void apilar(pila & P,telemento d);
/*
{Pre: la pila P ha debido ser previamente inicializada }
{Post: Apila en la pila P el elemento d}
*/

bool pilaVacia(pila P);
/*
{Pre: la pila P ha debido ser previamente inicializada }
{Post: Si la pila P está vacía devuelve el valor verdad. En caso contrario devuelve el valor falso}
*/

telemento cima(pila P);
/*
{Pre: la pila P ha debido ser previamente inicializada y no está vacía}
{Post:Devuelve el elemento más reciente en la pila P y no modifica P}
*/

void desapilar(pila & P);
/*
{Pre: la pila P ha debido ser previamente inicializada y no está vacía}
{Post: Modifica la pila P eliminando el último elemento apilado}
*/

