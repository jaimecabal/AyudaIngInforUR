#include <iostream>
/*Dada una secuencia que acabe en -1 calcular el numero de veces que aparece el entero k*/
using namespace std;

int main()
{
    char c;
    int numK;
    numK=0;

    cout << "Introduzca un caracter: ";
    cin>>c;

    while(c!=','){
        if(c=='k'){
            numK++;
        }
        cout << "Introduzca un caracter: ";
        cin>>c;
    }
    cout<<"El numero de ks es: "<<numK;
    return 0;
}
