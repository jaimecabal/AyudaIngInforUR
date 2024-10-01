#include <iostream>

using namespace std;

int main()
{
    int n;
    bool todoPar;
    todoPar=true;
        cout<<"Introduzca un numero: ";
        cin>>n;
    while(n=='-1'){
        if((n%2)!=0){
            todoPar=false;
        }
        cout<<"Introduzca un numero: ";
        cin>>n;

    }
    if(todoPar==false){
        cout<<"Todos los numeros de la secuencia son pares";
    }else{
        cout <<"No todos los numeros son pares";
    }
    return 0;
}
