#include <iostream>
#include "pila.h"

using namespace std;

void leer_crear_pila(pila &p);
void mostrar_pila(pila p);


int main()
{
    pila p;
    leer_crear_pila(p);
    mostrar_pila(p);
    mostrar_pila(p);
    return 0;
}

void leer_crear_pila(pila &p){
iniciarPila(p);
telemento n;
do {
    cout<< "Introduzca un entero para la pila:";
    cin>>n;
    if (n==0){
        break;
    }
    apilar(p,n);
} while (true);
};
void mostrar_pila(pila p){
    pila aux;
    iniciarPila(aux);
    telemento e;
    while (!pilaVacia(p)) {
        e=cima(p);
        cout<<"Elemento:"<< e<<endl;
        apilar(aux,e);
        desapilar(p);
    }
    while (!pilaVacia(aux)) {
        e=cima(aux);
        apilar(p,e);
        desapilar(aux);
    }
};
