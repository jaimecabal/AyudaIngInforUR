/*
    Interfaz:
             Entrada:real gradosCentigrados
             Salida: real gradosFahrenheit
    Efecto:
           Condiciones: N/A
           Efecto Producido:gradosFahrenheit=((9/5)*gradosCentigrados + 32)
*/

#include <iostream>

using namespace std;

int main()
{
    //Variables
    float gradosCentigrados, gradosFahrenheit;
    //Algoritmo
    cout << "Introduzca los grado centigrados para convertir a Fahrenheit: ";
    cin >> gradosCentigrados;
    //Necesita estar como 9.0 y 5.0 porque sino le da un siroco
    gradosFahrenheit=((((9.0/5.0))*gradosCentigrados) + 32);

    cout << gradosCentigrados << " son " << gradosFahrenheit << " .";

    return 0;
}
