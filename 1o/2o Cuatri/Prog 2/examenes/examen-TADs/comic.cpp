#include <cstring>
#include <iostream>
#include "comic.h"

using namespace std;


void crearComic(tComic & c){
    //Creamos mediante la entrada por teclado el comic
    cout << "Introduce el titulo del comic: " << endl;
    cin >> c.titulo;
    cout << "Introduce el protagonista del comic: " << endl;
    cin >> c.protagonista;
    cout << "Introduce el guionista del comic: " << endl;
    cin >> c.guionista;
    cout << "Introduce el año de publicacion del comic: " << endl;
    cin >> c.anioPublicacion;
}

void tituloComic(tComic & c, char titulo[]){
    //Copiamos el titulo de comic y lo pegamos en titulo
    strcpy(titulo,c.titulo);
}

void mostrarComic(tComic & c){
    cout << "<----------------------------------------------------------->" << endl;
    cout << "El titulo de este comic es: " << c.titulo << endl;
    cout << "El protagonista de este comic es: " << c.protagonista << endl;
    cout << "El guionista de este comic es: " << c.guionista << endl;
    cout << "El año de publicacion de este comic es: " << c.anioPublicacion << endl;
    cout << "<----------------------------------------------------------->" << endl;
}
void copiarComic (tComic & c, tComic & cc){
    //Para los componentes que son vectores no podemos copiar igualando simplemente, tenemos
    //que usar la funcion string copy de cstring
    strcpy(cc.titulo,c.titulo);
    strcpy(cc.protagonista,c.protagonista);
    strcpy(cc.guionista,c.guionista);
    cc.anioPublicacion=c.anioPublicacion;
}