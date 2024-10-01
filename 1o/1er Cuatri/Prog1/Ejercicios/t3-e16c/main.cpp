#include <iostream>

using namespace std;

int main()
{
    int numFilas, numAsteriscos;
    numFilas=0;
    numAsteriscos=5;
    while(numFilas<5){
        while(numAsteriscos!=0){
            cout<<"*";
            numAsteriscos=numAsteriscos-1;
        }
        cout<<""<<endl;
        numFilas++;
        numAsteriscos=5;
        numAsteriscos=numAsteriscos-numFilas;
    }
    return 0;
}
