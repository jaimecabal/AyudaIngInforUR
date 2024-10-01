/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: geanozv
 *
 * Created on 5 de abril de 2019, 9:10
 */

#include <cstdlib>
#include <iostream>

using namespace std;
struct Nodo{
    int dato;
    Nodo *sig;
};
typedef Nodo * lista;

void anadirPrincipio(lista & l,int n);
void crearLista(lista & l);
//void mostrarLista(lista & l);
//void liberarLista(lista & l);
//void anadirFinal(lista & l, int n);
void mediaYdiferencia(lista & l);
/*
 * 
 */
int main(){
    Nodo * l=NULL;
    
    /*
    cout<<"introduce n: "<<endl;
    cin>>n;
    anadirFinal(l,n);
    */
    mediaYdiferencia(l);
    

    system("Pause");
    return 0;
    
}

void anadirPrincipio(lista & l, int n){
    Nodo * aux;
    aux=new(Nodo);
    if(aux!=NULL){
        aux->dato=n;
        aux->sig=l;
        l=aux;
    }
    
} 

void crearLista(lista & l){
    
    Nodo * anadir;
    
    anadir=new(Nodo);
    cout<<"introduce el elemento a anhadir: "<<endl;
    cin>>anadir->dato;
    while((anadir->dato!=0)&(anadir!=NULL)){
    anadirPrincipio(l,anadir->dato);
     cout<<"introduce el elemento a anhadir: "<<endl;
    cin>>anadir->dato;
        
    }
}
/*
void mostrarLista(lista & l){
    Nodo * aux;
    aux=new(Nodo);
    aux=l;
    while(n!=0){
    cout<<aux.dato<<endl;
    aux=aux->sig;
    }
}
void liberarLista(lista & l){
    Nodo * aux;
    aux=new(Nodo);
    int n;
   
    
    while(n!=0){
        aux=l;
        l=l->sig;
        delete(aux);
    }
}
 
void anadirFinal(lista & l, int n){
    Nodo * aux;
    Nodo * nuevo;
    nuevo=new(Nodo);
    if(nuevo!=NULL){
        nuevo->dato=n; //(*nuevo).dato=n;
        nuevo->sig=NULL;
    }
   
    
    if(l==NULL){
        l=nuevo;
    }
    else{
    aux=l;
   
    while(aux!=NULL){
        aux=aux->sig;
    }
    aux->sig=nuevo;
    }
}
*/
void mediaYdiferencia(lista & l){
    float media;
    int sumatotal=0;
    int elementos=0;
    crearLista(l);
    Nodo * aux;
    aux=new(Nodo);
    aux=l;
    while(aux->dato!=0){
        sumatotal=sumatotal+aux->dato;
        elementos++;
    aux=aux->sig;
    }
    media=sumatotal/elementos;
     while(aux->dato!=0){
    cout<<aux->dato<<endl;
    cout<<media-aux->dato<<endl;  
    aux=aux->sig;
    }
}
    
