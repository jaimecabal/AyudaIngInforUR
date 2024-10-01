/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cola.h"
#include <iostream>

void iniciarCola(cola & C)
/*Pre: 
 Post: inicializa una cola vacía.
*/
{
    C.primero=NULL;
    C.ultimo=NULL;
    
}
void anadir (cola & C, telemento d){
    Nodo *nuevo=new(Nodo);
    if(nuevo != NULL){
        (*nuevo).dato=d;
        (*nuevo).sig=NULL;
        if(C.primero== NULL){
            C.primero= nuevo;
        }
        else{
            (*C.ultimo).sig= nuevo;
        }
        C.ultimo=nuevo;
    }
}
bool colaVacia(cola c){
    
    return(c.primero == NULL);
}
telemento primero(cola C){
    return(*(C.primero)).dato; //solo interesa el dato
}
void eliminar(cola & C){
    Nodo *aux =C.primero;
    C.primero= (*(C.primero)).sig;
    delete(aux);
    if(C.primero==NULL){
        C.ultimo=NULL;
    }
}
