#include <iostream>
#include "racional.h"
void leerRacional(racional &r);
void escribirRacional(racional r);
int main() {
    racional r;
    leerRacional(r);
    escribirRacional(r);
    return 0;
}
void leerRacional(racional &r){
    int num;
    int den;
    cout << "Escribe el numerador: ";
    cin >> num;
    cout << "Escribe el denominador: ";
    cin >> den;
    crear(num,den,r);
}
void escribirRacional(racional r){
    cout << numerador(r) <<"/"<<denominador(r)<<endl;
}