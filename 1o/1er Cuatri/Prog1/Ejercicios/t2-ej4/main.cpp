#include <iostream>
/*Calcula longitud media de las palabras de una frase acabada en .*/
using namespace std;

int main()
{
    char l;
    float media,longitudPalabra,numPalabras,longitudTotal;
    media=0;
    longitudPalabra=1;
    numPalabras=1;

    cout << "Introduzca letras :" << endl;
    cin>>l;

    while(l!='.'){
        while((l!=',')&&(l!='.')){
            cout<<longitudPalabra;
            longitudPalabra++;
            cout << "Introduzca letras :" << endl;
            cin>>l;
        }
        numPalabras++;
        longitudTotal=longitudTotal+longitudPalabra;
        longitudPalabra=1;
        cout << "Introduzca letras :" << endl;
        cin>>l;
    }
    media=longitudTotal/numPalabras;
    cout<<media;
    return 0;
}
