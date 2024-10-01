#include <iostream>
/*El programa tiene que contar el numero de As que tiene la secuencia*/
using namespace std;

int main()
{
    char l;
    int numA;
    numA=0;
    while(l==','){
        cout << "Introduzca una letra: ";
        cin >> l;
    }
    while(l!=','&&l!='.'){
        if (l=='a'){
            numA++;
        }
        cout << "Introduzca una letra: ";
        cin >> l;
    }
    cout << numA;
    return 0;
}
