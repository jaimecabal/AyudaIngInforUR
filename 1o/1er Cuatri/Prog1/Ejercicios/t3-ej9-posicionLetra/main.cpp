/*
    Interfaz:
            Entrada: caracter letraMayus
            Salida:  entero posicionAlfabeto
    Efecto:
          Condiciones necesarias: Tiene que ser una letra mayuscula
          Efecto producido: letraMayus=
*/
#include <iostream>
using namespace std;

int main()
{
    char letraMayus;
    int /*posicionAlfabeto,*/ asciiMayus;
    cout << "Introduzca una letra mayuscula: ";
    cin >> letraMayus;

    asciiMayus=(int(letraMayus)-int('A'))+1;

    cout << "La posicion de la letra " << letraMayus << " es :" <<asciiMayus;

    return 0;
}
