#include <iostream>
#include "paciente.h"

using namespace std;

typedef Paciente telemento;

struct Nodo{
    telemento dato;
    Nodo * sig;
};

struct cola{
    Nodo * primero;
    Nodo * ultimo;
};

void  iniciarCola (cola & c);
/*
{Pre: }
{Post: Inicia c como una cola vacía}
*/
void anadir (cola & c, telemento d);
/*
{Pre: la cola c ha debido ser previamente inicializada}
{Post: Añade a c el elemento d}
*/
bool colaVacia (cola c); 
/*
{Pre: la cola c ha debido ser previamente inicializada}
{Post: Si c está vacía devuelve VERDAD y FALSO en otro 
caso}
*/
telemento primero(cola c);
/*
{Pre: la cola c ha debido ser previamente inicializada y 
no está vacía}
{Post: Devuelve el elemento más antiguo de la cola c y no 
modifica la cola}
*/ 
void eliminar(cola  & c);
/*
{Pre: la cola c ha debido ser previamente inicializada y 
no está vacía}
{Post: Modifica la cola c eliminando el elemento más 
antiguo}
*/