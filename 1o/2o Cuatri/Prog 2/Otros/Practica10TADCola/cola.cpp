#include <iostream>
#include "cola.h"

void iniciarCola(cola & c) {
    c.primero = NULL;
    c.ultimo = NULL;
}

void anadir(cola & c, telemento d) {
    Nodo *nuevo = new(Nodo);
    if (nuevo != NULL) {
        (*nuevo).dato = d;
        (*nuevo).sig = NULL;
        if (c.primero == NULL) {
            c.primero = nuevo;
        } else {
            (*c.ultimo).sig = nuevo;
        }
        c.ultimo = nuevo;
    }
}

bool colaVacia(cola c) 
{
    return (c.primero == NULL);
}

telemento primero(cola c) {
    return (*(c.primero)).dato; //sólo interesa el dato.
}

void eliminar(cola & c) {
    Nodo *aux = c.primero;
    c.primero = (*(c.primero)).sig;
    delete(aux);
    if (c.primero == NULL) {
        c.ultimo = NULL;//ya que sólo había un elemento y lo hemos borrado en la instrucción anterior.
    }
}
