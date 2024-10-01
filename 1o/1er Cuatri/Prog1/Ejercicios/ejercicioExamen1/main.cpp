#include <iostream>
/*Busca si de la lista de palabras introducidas por pantalla hay alguna que empiece por a*/
using namespace std;

int main()
{
    char p,primeraLetra;
    bool encontradoA;
    encontradoA=false;
    cin.unsetf(ios::skipws);
    cout << "Introduzca una lista de palabras." << endl;
    cin>>p;
    while(p==' '){
        cin>>p;
    }
    while((p!='.')&&(encontradoA!=true)){
        primeraLetra=p;
        if(primeraLetra=='a'||primeraLetra=='A'){
            encontradoA=true;
        }
        while((p!=' ')&&(p!='.')){
            cin>>p;
        }
        while(p==' '){
            cin>>p;
        }
    }

    if(encontradoA==true){
        cout<<"Hay alguna palabra que empieza por A";
    }else{
        cout<<"No hay ninguna palabra que empieza por A";
    }
    return 0;
}
