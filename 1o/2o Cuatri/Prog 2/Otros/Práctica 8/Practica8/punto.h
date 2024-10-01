

/* 
 * File:   punto.h
 * Author: Charo
 *
 * 
 */

#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

struct punto{
    float abscisa;
    float ordenada;
};

void crearPunto(float abscisa, float ordenada, punto &p);
float abscisa(punto p);
float ordenada(punto p);
float distanciaOrigen(punto p);
