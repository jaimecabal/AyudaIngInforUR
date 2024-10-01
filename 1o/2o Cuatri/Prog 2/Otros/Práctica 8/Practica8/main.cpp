#include <iostream>
#include "racional.h"

using namespace std;

void leerRacional(racional &r);
void escribirRacional(racional r);
void sumaRacionales(racional r1, racional r2, racional & r);
void multiplicaRacionales(racional r1, racional r2, racional & r);
bool racionalesIguales(racional r1, racional r2);
void sumaSecuenciaRacionales();
/*
bool concentricas(circunferencia c1,circunferencia c2);
bool puntosIguales(punto p1,punto p2);
bool dentroCircunferencia(punto p, circunferencia c);
float distanciaPuntos(punto p1,punto p2);
*/
int main()
{
    sumaSecuenciaRacionales();
    system("Pause");

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

void sumaRacionales(racional r1, racional r2, racional & r){
    int num= numerador(r1)*denominador(r2)+numerador(r2)*denominador(r1);
    int den = denominador(r1)*denominador(r2);
    crear(num,den,r);
    irreducible(r,r);
}

void multiplicaRacionales(racional r1, racional r2, racional & r){
    int num= numerador(r1)*numerador(r2);
    int den = denominador(r2)*denominador(r1);
    crear(num,den,r);
    irreducible(r,r);
}

bool racionalesIguales(racional r1, racional r2){
    racional ir1,ir2;
    irreducible(r1,ir1);
    irreducible(r2,ir2);
    return (numerador(ir1)==numerador(ir2) && denominador(ir1)==denominador(ir2));
}

void sumaSecuenciaRacionales(){
    racional r,sum;
    crear(0,1,sum);
    leerRacional(r);
    while(numerador(r)!=0){
        sumaRacionales(r,sum,sum);
        leerRacional(r);
    }
    escribirRacional(sum);
}

/*
bool concentricas(circunferencia c1,circunferencia c2){
    return puntosIguales(centro(c1),centro(c2));
}

bool puntosIguales(punto p1,punto p2){
    return(abscisa(p1)==abscisa(p2)&&ordenada(p1)==ordenada(p2));
}

bool dentroCircunferencia(punto p, circunferencia c){
    return(distanciaPuntos(p1,centro(c))<radio(c));
}

float distanciaPuntos(punto p1,punto p2){
    float a = abscisa(p1)-abscisa(p2);
    float b = ordenada(p1)-ordenada(p2);
    return(sqrt(a*a+b*b));

}
*/