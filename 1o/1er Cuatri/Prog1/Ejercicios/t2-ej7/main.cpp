#include <iostream>
/*Calcula longitud media de las palabras de una frase acabada en .*/
using namespace std;

int main()
{
    char l;
    float coste;
    int longitudPalabra;
    longitudPalabra=0;
    coste=0;
    cout << "Introduzca letras :" << endl;
    cin>>l;

    while(l!='.'){
        while(l!=','){
            longitudPalabra++;
            cout << "Introduzca letras :" << endl;
            cin>>l;
        }
        switch(longitudPalabra){
            case 1:
                coste=coste+5;
                break;
            case 2:
                coste=coste+7;
                break;
            case 3:
                coste=coste+11;
                break;
            case 4:
                coste=coste+17;
                break;
            case 5:
                coste=coste+25;
                break;
            default:
                coste=coste+30;
        }
        longitudPalabra=0;
        cout << "Introduzca letras :" << endl;
        cin>>l;
    }
    cout<<coste;
    return 0;
}
