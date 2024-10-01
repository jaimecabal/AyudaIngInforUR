#include "punto.h"

void crearPunto(float abscisa, float ordenada, punto &p){
    p.abscisa = abscisa;
    p.ordenada = ordenada;
}

float abscisa(punto p){
    return p.abscisa;
}

float ordenada(punto p){
    return p.ordenada;
}


float distanciaOrigen(punto p){
    return(sqrt(p.abscisa*p.abscisa+p.ordenada*p.ordenada));
}

