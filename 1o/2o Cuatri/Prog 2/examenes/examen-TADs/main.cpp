#include <iostream>
//Como estoy haciendo el examen en VSCode tengo que incluir el cpp ya que la extension que uso
//para compilar no me permite vincular directamente el .h
#include "lista.h"
//La "anidacion" del TAD es la siguiente
//      comic.h --> lista.h  --> lista.cpp --> main.cpp
//      comic.h --> comic.cpp
using namespace std;

/*
 * Autor: Jaime Cabal
 * Programa usado: Netbeans para crear la estructura del proyecto, VSCode para realizar el examen
 */
//Yo prefiero crear la funcion menu para hacer mas limpio el main
int menu();

int main() {
    int m;
    //Yo prefiero declarar todas las variables al principio
    lista l,ll;
    tComic c;
    char titulo[50];
    //Iniciamos las listas ya, aunque en algunos casos se volveran a iniciar
    iniciar(l);
    iniciar(ll);
    m=menu();
    while(m!=5){
        switch (m){
            case 1:
            crearLista(l);
                break;
            case 2:
                cout << "Esta es la lista original." << endl;
                mostrarLista(l);
                crearComic(c);
                add(l,c); 
                cout << "Esta es la lista despues de añadir el nuevo valor." << endl;
                mostrarLista(l);
                break;
            case 3:
                cout << "Esta es la lista de comics." << endl;
                mostrarLista(l);
                break;
            case 4:
                cout << "Introduce el titulo de comic a buscar" << endl;
                cin>>titulo;
                if(esta(l,titulo)){
                    cout<<"Esta el titulo en la lista" << endl;
                }else{
                    cout<<"No esta el titulo en la lista " << endl;
                }
                break;
            default:
                cout << "Esa opcion no la hemos implementado todavia, por favor introduzca una valida." << endl;
                break;  
        }
        m=menu();
    }
    return 0;
}

int menu(){
    int m;
    cout << "////////////////////////////////////////////////////////////" << endl;
    cout << "Por favor introduce el apartado que se quiere hacer: " << endl;
    cout << "1. Crear una lista de películas" << endl;
    cout << "2. Añadir un cómic." << endl;
    cout << "3. Mostrar los cómicsde la lista de películas, ordenados por orden alfabético del campo titulo." << endl;
    cout << "4. Dado el títulode un cómic, indicar si dicho cómicse encuentra o no en la lista." << endl;
    cout << "5. Salir" << endl;
    cout << "////////////////////////////////////////////////////////////" << endl;
    cin >> m;
    return m;
} 
