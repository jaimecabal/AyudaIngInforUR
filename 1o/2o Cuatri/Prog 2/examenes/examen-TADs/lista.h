#ifndef LISTA_H
#define LISTA_H
#include "comic.h"
//Incluimos la declaracion de comic para poder usar las accion/funciones basicas del TAD

typedef tComic telemento;

struct Nodo{
    telemento dato;
    Nodo * sig;
};
struct lista{
    Nodo * primero;
    int num;
};

void iniciar(lista &l);
/*
{PRE:}
{POST: devuelve lista como una lista iniciada pero sin comics}
*/

void add(lista & l, tComic & c);
/*
{PRE: lista es una lista ya iniciada}
{POST: lista es devuelta con el comic c insertado}
*/

bool listaVacia(lista & l);
/*
{PRE:}
{POST: Devuelve true si la lista esta vacia y false en caso contrario}
*/

void crearLista(lista & l);
/*
{PRE: lista es una lista que ya ha sido creada}
{POST: Devuelve la lista con todos los comics que se han querido añadir dentro}
*/

void copiarLista(lista & l, lista & ll);
/*
{PRE: Lista l es una lista ya iniciada}
{POST:Lista ll es una lista que contiene una copia de los datos de l}
*/

void mostrarLista(lista & l);
/*
{PRE: lista es una lista que ya ha sido creada y que contiene algunos comics dentro}
{POST: Muestra por pantalla todos los datos de los comics que tiene dentro l}
*/

bool esta(lista & l, char titulo[]);
/*
{PRE:}
{POST: Devuelve true si esta el comic con ese titulo en la lista, y false en caso contrario}
*/

#endif /* LISTA_H */