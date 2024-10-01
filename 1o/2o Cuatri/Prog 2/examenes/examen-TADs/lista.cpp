#include <cstring>
#include <iostream>
#include "lista.h"

using namespace std;

void iniciar(lista &l){
    //Iniciamos el primero nodo de la lista de comics a NULL
    l.primero=NULL;
    l.num=0;
}

void add(lista & l, tComic & c){
    //Esta es la que va a depender que el listado este bien o no
    //Tiene que insertar los comics de tal manera que esten ordenados por titulo
    //Asi luego no hay que hacer otra funcion distinta para hacer la operacion 3
    //COSTE: O(n)
    Nodo * nuevo = new(Nodo);
    Nodo * actual = l.primero;
    Nodo * anterior = NULL;
    copiarComic(c, (*nuevo).dato);
    (*nuevo).sig=NULL;
    if (l.primero==NULL){ 
        //la lista está vacía y se añade el primero
        l.primero= nuevo;
    } else {
        char titulo1[50];                           // --> con este sacamos el titulo del comic que vamos a insertar
        char tituloActual[50];                      // --> con este sacamos el titulo actual de la lista
        tituloComic(c,titulo1);                     //Sacamos el titulo del comic a insertar
        tituloComic((*actual).dato,tituloActual);   // Sacamos el titulo del primero comic actual de la lista
        
        //Para el while hay dos condiciones de salida
        //Que hayamos recorrido toda la lista o que hemos encontrado el "punto de insercion"
        while (actual!=NULL && strcmp(titulo1,tituloActual)>0 ){
            anterior=actual;
            actual= (*actual).sig;
            if (actual!=NULL){
                tituloComic((*actual).dato,tituloActual);
            }
        }
        //Esto se da en caso de que la lista este vacia, y este sea el primer comic que añadimos
        if(anterior==NULL){
            l.primero= nuevo;
        }else{
            //En caso contrario, inserta el comic como el siguiente nodo de la lista
            (*anterior).sig = nuevo;
        }
        //FALTABA ESTA LINEA SINO ESTABA PENCO
        (*nuevo).sig=actual;
    }
    l.num++; //--> esto indica el numero de comics que tiene nuestra lista
}

bool listaVacia(lista & l){
    //Si el primer nodo es null, es que la lista ya esta vacia
    //Tambien se puede comprobar que el numero de comics sea 0 (l.num==0)
    return (l.primero == NULL);
}

void crearLista(lista & l){
    tComic c;
    //Yo voy a tomar como condicion de salida que el titulo sea "0", como se nos ha indicado
    char titulo[50];
    cout << "Introduce la secuencia de comics, indicando el ultimo libro aquel que tenga titulo 0" << endl;
    crearComic(c);
    tituloComic(c,titulo);
    //La condicion de salida de este bucle es que lleguemos al titulo 0, como hemos dicho antes
    while(!strcmp(titulo,"0")==0){
        add(l,c);
        crearComic(c);
        tituloComic(c,titulo);
    }
}

void copiarLista(lista & l, lista & ll){
    Nodo * nuevo;
    Nodo * aux;
    //Comprobamos si la lista l esta vacia o no
    if(listaVacia(l) == true){
        //Aqui solo haria falta iniciarla ya que no hay eltos que copiar
        iniciar(ll);
    }else{
        iniciar(ll);
        //Copiamos primero el numero de datos de las dos
        ll.num=l.num;
        //Preparamos los nodos auxiliares
        nuevo=new(Nodo);
        ll.primero=nuevo;
        aux=ll.primero;
        //La condicion de salida del while es el hecho de que lleguemos al penultimo elto de la lista
        //He cambiado == por !=
        while ((*aux).sig!=NULL){
            copiarComic((*aux).dato,(*nuevo).dato);
            aux=(*aux).sig;
            (*nuevo).sig=new(Nodo);
            nuevo=(*nuevo).sig;
        }
        //Copiamos el ultimo elemento
        copiarComic((*aux).dato,(*nuevo).dato);
        //Finalizamos dejando el siguiente como NULL para indicar que es el final 
        //PENCO NUEVO, NO AUX
        (*nuevo).sig=NULL;
    }
}

void mostrarLista(lista & l){
    //Voy pillao de tiempo, no me da tiempo a redactar de todo este ejercicio
    //COSTE: O(n)
    lista lAux;
    iniciar(lAux);
    copiarLista(l,lAux);
    if(lAux.primero!=NULL){
        Nodo * aux;
        aux=lAux.primero;
        while (aux!=NULL){
            mostrarComic((*aux).dato);
            aux=(*aux).sig;
        }
    }else{
        cout << "La lista de comics esta vacia" << endl;
    }
}

bool esta(lista & l, char titulo[]){
    //Voy pillao de tiempo, no me da tiempo a redactar de todo este ejercicio
    bool here=false; //esta daba error asi que pongo here
    lista ll;
    if(listaVacia(l)==true){
        //No puede estar si la lista esta vacia
        here=false;
    }else{
        //Hacemos una copia de la lista
        copiarLista(l,ll);
        //Igual que hemos hecho antes vamos recorriendo la copia hasta encontrar el titulo que sea igual
        Nodo * actual = ll.primero;
        Nodo * anterior = NULL;
        char tituloActual[50];
        tituloComic((*actual).dato,tituloActual);
        while (actual!=NULL && strcmp(titulo,tituloActual)!=0){
            anterior=actual;
            actual= (*actual).sig;
            if (actual!=NULL){
                tituloComic((*actual).dato,tituloActual);
            }
        }
        //Si llegamos aqui, es que el bucle ha salido por la segunda condicion, por tanto esta el titulo en la lista
        if(actual!=NULL){
            here=true;
        }
    }
    return here;
}