/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolBinario.h
 * Author: geanozv
 *
 * Created on 24 de mayo de 2019, 9:13
 */
#include <iostream>
#include <cstring>
typedef char telemento[20];

struct nodo{
    telemento raiz;
    nodo * izdo;
    nodo * dcho;
};
typedef nodo * arbolBin;
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
void iniciarArbol(arbolBin & a);
void enraizar(arbolBin & a,arbolBin & Aiz,arbolBin & Ade,telemento n);
arbolBin Izquierdo(arbolBin a);
arbolBin Derecho(arbolBin a);
void raiz(arbolBin  a,telemento n);
bool arbolVacio(arbolBin a);



#endif /* ARBOLBINARIO_H */

