/*
 *
 */

#include <cstdlib>
#include <iostream>

using namespace std;
int factorial(int n);

int main(int argc, char** argv) {
    int n,factorialN;

    cout << "Introduce un numero para calcular su factorial" << endl;
    cin >> n;

    factorialN=factorial(n);
    cout << "El resultado es: " <<factorialN <<endl;
    return 0;
}

int factorial(int n){
    if(n==0){
        return 1;
    }else{
        return(n*factorial(n-1));
    }
}