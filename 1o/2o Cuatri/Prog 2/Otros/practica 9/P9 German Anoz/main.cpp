/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: geanozv
 *
 * Created on 3 de mayo de 2019, 9:06
 */

#include <cstdlib>
#include "pila.h"

using namespace std;

void crear_leer_pila(pila & p);
void mostrar_pila(pila & p);
/*
void numero_enteros(pila & p);
void invertir_pila(pila & p,pila & q);
void copiar_pila(pila & p, pila & q);
void pilas_iguales(pila & p, pila & q);
void capicua(int n);
*/
int main() {
    pila p;
    crear_leer_pila(p);
    mostrar_pila(p);
    return 0;
}

void crear_leer_pila(pila & p){
    iniciarPila(p);
    int a;
    cout<<"introduce el elemento a anhadir"<<endl;
    cin>>a;
    
    while(a!=0){
        apilar(p,a);
        cout<<"introduce el nuevo elemento: "<<endl;
        cin>>a;
    }
}

void mostrar_pila(pila & p){
    pila aux;
    iniciarPila(aux);
    int n;
    while(!pilaVacia(p)){
    cout<<"elemento: "<<endl;
    cout<<cima(p)<<endl;
    apilar(aux,cima(p));
    desapilar(p);
    n++;
    }
    while(!pilaVacia(aux)){
       apilar(p,cima(aux));
    desapilar(aux); 
    }
            
}
/*
void numero_enteros(pila & p){
    int a;
    pila aux;
    iniciarPila(aux);
    while(!pilaVacia(p)){
        apilar(aux,cima(p));
         desapilar(p);
         a++;
    }
     while(!pilaVacia(aux)){
       apilar(p,cima(aux));
    desapilar(aux); 
    }
    cout<<"el numero de enteros es: "<<a<<endl;
    
}
void invertir_pila(pila & p,pila & q){
    pila aux;
    iniciarPila(q);
    iniciarPila(aux);
     while(!pilaVacia(p)){
        apilar(aux,cima(p));
        apilar(q,cima(p));
         desapilar(p);
         
    }
    while(!pilaVacia(aux)){
       apilar(p,cima(aux));
    desapilar(aux); 
    }
}
void copiar_pila(pila & p, pila & q){
    pila aux1;
    iniciarPila(aux1);

    while(!pilaVacia(p)){
        apilar(aux1,cima(p));
         desapilar(p);
         
    }
     while(!pilaVacia(aux1)){
       apilar(p,cima(aux1));
       apilar(q,cima(aux1));
    desapilar(aux1); 
    }
}
void pilas_iguales(pila & p, pila & q){
    pila aux;
    pila aux1;
    iniciarPila(aux);
    iniciarPila(aux1);
    bool iguales;
    iguales=true;
    if(p.num!=q.num){
        cout<<"No son iguales"<<endl;
            
    }else{
        while(iguales){
        if(cima(p)==cima(q)){
            apilar(aux,cima(p));
            apilar(aux1,cima(q));
            desapilar(p);
            desapilar(q);
        }else{
            iguales==false;
        }
    }
}
    while(!pilaVacia(aux1)){
       apilar(q,cima(aux1));
    desapilar(aux1); 
    }
    while(!pilaVacia(aux)){
       apilar(p,cima(aux1));
    desapilar(aux1); 
    }
}
void capicua(int n){
    pila p;
    pila q;
    int elemento;
    iniciarPila(p);
    iniciarPila(q);
    while(n>10){
    elemento= n/10;
    n=n%10;
    apilar(p,n);
    }
    apilar(p,elemento);
    invertir_pila(p,q);
    pilas_iguales(p,q);
    
    
}
*/