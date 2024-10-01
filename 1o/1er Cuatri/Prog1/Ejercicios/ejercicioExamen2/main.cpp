#include <iostream>
/*Busca si de la lista de palabras introducidas por pantalla hay alguna que acabe en n*/
using namespace std;

int main()
{
    char p,ultimaLetra;
    bool encontradoN;
    encontradoN=false;
    cin.unsetf(ios::skipws);
    cout << "Introduzca una lista de palabras." << endl;
    cin>>p;
    while(p==' '){
        cin>>p;
    }
    while((p!='.')&&(encontradoN!=true)){
        while((p!=' ')&&(p!='.')){
            ultimaLetra=p;
            cin>>p;
        }
        if(ultimaLetra=='n'||ultimaLetra=='N'){
            encontradoN=true;
        }
        while(p==' '){
            cin>>p;
        }
    }

    if(encontradoN==true){
        cout<<"Hay alguna palabra que acabe por N";
    }else{
        cout<<"No hay ninguna palabra que acabe por N";
    }
    return 0;
}
