/*
Interaz:
        Entrada:    masa, fuerza
        Salida:     aceleracion
Efecto:
       Condiciones Requeridas: masa>0, fuerza>0
       Efecto producido: aceleracion = fuerza / masa
*/

#include <iostream>

using namespace std;

int main()
{
    //Variables:
    float masa, fuerza, aceleracion;

    cout << "Introduzca la masa de la particula: ";
    cin >> masa;

    cout << "Introduzca la fuerza de la particula: ";
    cin >> fuerza;

    if (masa<0){
        cout << "La masa tiene que ser mayor que 0";
    }else if(fuerza<0){
        cout << "La fuerza tiene que ser mayor que 0";
    }else{
        aceleracion=fuerza/masa;
        cout << "La aceleracion es: " << aceleracion;
    }
    return 0;
}
