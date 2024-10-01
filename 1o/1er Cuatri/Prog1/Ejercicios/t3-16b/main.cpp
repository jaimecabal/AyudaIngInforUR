#include <iostream>

using namespace std;

int main()
{
    int numFilas, numAsteriscos;
    numFilas=0;
    numAsteriscos=0;
    while(numFilas<5){
        while(numAsteriscos<5){
            cout<<"*";
            numAsteriscos++;
        }
        cout<<""<<endl;
        numAsteriscos=0;
        numFilas++;
    }
    return 0;
}
