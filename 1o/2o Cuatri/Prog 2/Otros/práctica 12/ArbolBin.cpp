/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ArbolBinario.h"

void iniciarArbol(arbolBin & a){
    a=NULL;
 
}



void enraizar(arbolBin & a,arbolBin & Aiz,arbolBin & Ade,telemento n){
    a=new(nodo);
    if(a!= NULL){
        strcpy(a->raiz,n);
        a->dcho=Ade;
        a->izdo=Aiz;
        Aiz=NULL;
        Ade=NULL;
    }    
}
arbolBin Izquierdo(arbolBin a){
    return(a->izdo);
}
arbolBin Derecho(arbolBin a){
    return(a->dcho);
}
void raiz(arbolBin a,telemento n){
    strcpy(n,a->raiz);
}
bool arbolVacio(arbolBin a){
    return(a==NULL);
}
