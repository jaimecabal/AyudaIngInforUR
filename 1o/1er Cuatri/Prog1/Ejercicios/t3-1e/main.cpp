#include <iostream>

using namespace std;

int main()
{
    char l;
    int numD,numC;
    cout << "Introduzca una letra: ";
    cin>>l;
    while(l==','){
        cout << "Introduzca una letra: ";
        cin>>l;
    }

    while((l!=',')&&(l!='.')){
        if(l=='d'){
            numD++;
        }
        if(l=='c'){
            numC++;
        }
        cout << "Introduzca una letra: ";
        cin>>l;
    }
    if(numD>numC){
        cout<<"Hay mas Ds que Cs";
    }else{
        cout<<"No hay mas Ds que Cs";
    }

    return 0;
}
