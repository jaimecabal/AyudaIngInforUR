#include "circunferencia.h"

void crearCircunferencia(punto p,float radio,circunferencia &c){
    c.centro = p;
    c.radio = radio;
}

float radio(circunferencia c){
    return c.radio;
}

punto centro(circunferencia c){
    return c.centro;
}

