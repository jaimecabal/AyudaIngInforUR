#include <iostream>
/*Autor: Jaime Cabal*/
/*Numero de palabras que empiezan y acaban por la misma letra en una secuencia de caracteres acabada en .*/
using namespace std;

int main()
{
    int numPalabras;
    char l,primeraL,aux;

    cin.unsetf(ios::skipws);

    numPalabras=0;

    cout << "Introduzca una frase: ";
    cin>>l;
    while(l==' '){
        cin>>l;
    }
    while(l!='.'){
        primeraL=l;
        cin>>l;
        while(l!=' '){
            aux=l;
            cin>>l;
        }
        while(l==' '){
            cin>>l;
        }
        if(primeraL==aux){
            numPalabras++;
        }
    }
    cout<<"El numero de palabras que empiezan y acaban en la misma letra es "<<numPalabras;
    return 0;
}
