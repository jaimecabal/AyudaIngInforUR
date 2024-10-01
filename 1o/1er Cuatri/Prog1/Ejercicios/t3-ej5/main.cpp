#include <iostream>
/*Una secuencia de números enteros positivos se dice
melchoriforme si uno de sus elementos es rubio.
Un elemento de una secuencia se dice rubio si es la
suma del resto de elementos de la secuencia.
Escribir un programa que diga si una secuencia
es melchoriforme.*/

using namespace std;

int main()
{
    /*variables*/
    int maximo,suma,n;
    maximo=0;
    suma=0;

    cout << "Introduzca un numero";
    cin >> n;

    while(n!=-1){
        suma=suma+n;
        if (n>maximo){
            maximo=n;
        }
        cout << "Introduzca un numero";
        cin >> n;
    }
    cout<< maximo<<endl;
    if(maximo==(suma-maximo)){
        cout<<"La secuencia es melchoriforme";
    }else{
        cout<<"La secuencia no es melchoriforme";
    }

    return 0;
}
