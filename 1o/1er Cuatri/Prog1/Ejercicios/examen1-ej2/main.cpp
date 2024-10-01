#include <iostream>
#include <cmath>
/*Dado un real x entre 1 y 2, calcula un n tal que 1+x^2+....+x^n>1000*/
using namespace std;

int main()
{
    int n;
    float aux, aux2, x;
    cout << "Introduzca un numero :";
    cin>>x;
    aux=1;
    n=1;
    while(x<1||x>2){
       cout << "Introduzca un numero :";
       cin>>x;
    }
    while (aux<1000){
        aux2=pow(x,n);
        aux=aux+(aux2);
        n++;
    }
    cout<<n;
    return 0;
}
