/*
    Interfaz:
        Entrada: Real valor
        Salida:  Real valorSen, valorCos, valorTan
    Efecto:
        Condiciones: N/A
        Efecto Producido:   valorSen es el sin(valor)
                            valorCos es el cos(valor)
                            valorTan es el tan(valor)
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Variables que vamos a usar
    float valor, valorSen, valorCos, valorTan;
    //algoritmo:
    cout << "Introduzca el valor del que quiere encontrar el seno, coseno y tangente.";
    cin >> valor;

    valorSen=sin(valor);
    valorCos=cos(valor);
    valorTan=tan(valor);

    cout << "El seno de " << valor << " es: " << valorSen;
    cout << "El coseno de " << valor << " es: " << valorCos;
    cout << "La tangente de " << valor << " es: " << valorTan;


    return 0;
}
