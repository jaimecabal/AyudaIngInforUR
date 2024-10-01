#include <iostream>
/*Dado una secuencia de enteros acabada en -1, determina segun un valor k, si algun numero de esa secuencia es multiplo de k*/
using namespace std;

int main()
{
    int n,k;
    float aux;
    bool esMult;
    esMult=false;
    cin.unsetf(ios::skipws);

    cout << "Introduce una secuencia de numeros enteros acabado en -1: ";
    cin>>n;

    while(n==' '){
        cin>>n;
    }

    cout<<"Introduce un numero para comparar: ";
    cin>>k;

    while((n!='-1')&&(esMult==false)){
        aux=n%k;
        cout<<"Llego while"<<endl;
        if(aux==0){
        cout<<"Llego if"<<endl;
            esMult=true;
        }
        cin>>n;
        while(n==' '){
            cin>>n;
        }
    }
    if(esMult==true){
        cout<<"Hay numeros en la secuencia que si es multiplo de "<<k<<" .";
    }else{
        cout<<"Ningun numero de la secuencia es multiplo de "<<k<<" .";
    }
    return 0;
}
