/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cola.h
 * Author: geanozv
 *
 * Created on 10 de mayo de 2019, 9:11
 */

#ifndef COLA_H
#define COLA_H
#include "paciente.h"
typedef Paciente telemento;
struct Nodo{
    telemento dato;
    Nodo *sig;
};

struct cola{
    Nodo *primero;
    Nodo *ultimo;
   
};
void iniciarCola(cola & C);
void anadir (cola & C, telemento d);
bool colaVacia(cola c);
telemento primero(cola C);
void eliminar(cola & C);


#endif /* COLA_H */

