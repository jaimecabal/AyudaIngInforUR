#include <iostream>
/*DNF*/
using namespace std;

int main()
{
    int numFilas,numColumnas;
        numFilas=0;
    while(numFilas<5){
        numColumnas=0;
        while(numColumnas<5){
            switch(numFilas){
            case 1:
                cout<<"****+";
            ;
            case 2:
                cout<<"***++";
            ;
            case 3:
                cout<<"**+++";
            ;
            case 4:
                cout<<"*++++";
            ;
            default:
                cout<<"+++++";
            ;
            }
        }
        cout<<""<<endl;
        numFilas++;
    }
    return 0;
}
