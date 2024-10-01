#include <iostream>
/*Dada una secuencia de números enteros positivos acabada en 0,
calcular la longitud del mayor tramo de valores ordenados
de forma decreciente.*/
using namespace std;

int main()
{
    int n,longitudTramo,tramoGrande;
    cin.unsetf(ios::skipws);

    longitudTramo=0;
    tramoGrande=0;

    cout << "Introduzca una secuencia de numeros enteros" << endl;
    cin>>n;

    while(n==' '){
        cin>>n;
    }

    while((n!=' ')&&(n!=0)){
        while(n!=' '){
            longitudTramo++;
            cin>>n;
        }
        if(longitudTramo>tramoGrande){
            tramoGrande=longitudTramo;
        }
        longitudTramo=0;
        while(n==' '){
            cin>>n;
        }
    }
    cout<<"La longitud del tramo mas grande es: "<<tramoGrande;
    return 0;
}
