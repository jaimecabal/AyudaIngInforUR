#include <iostream>

using namespace std;

int main()
{
    char l,primeraLetra,ultimaLetra;
    int numPalabras;
    cout << "Introduzca una letra: " << endl;
    cin >> l;
    numPalabras=0;
    while (l!='.'){
        primeraLetra=l;
        while(l!=',' && l!='.'){
            ultimaLetra=l;
            cout << "Introduzca una letra: " << endl;
            cin >> l;
        }
        if(primeraLetra==ultimaLetra){
            numPalabras++;
        }
        cout << "Introduzca una letra: " << endl;
        cin >> l;
    }
    cout<<numPalabras;
    return 0;
}
