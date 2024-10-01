#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

int factorial(int n);
float potencia(float a, int n);
int suma(int v[100],int n);
float promedio(int n1, int n2);
float media(int v[100],int n);
int max(int n1,int n2);
int min(int n1,int n2);
int maximo(int v[100],int n);
int minimo(int v[100],int n);

// Ejercicio 1. Función recursiva para calcular el factorial de un número.

/*
{Pre: n>=0}
{Post:devuelve n! }
*/
int factorial(int n){

    if (n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}


// Ejercicio 2. Función recursiva para calcular el cálculo de la potencia de a elevado a n.
/*
{Pre: n>=0 }
{Post: devuelve a elevado n }
*/
float potencia(float a, int n){
    if(n==0){
        return 1;
    }
    else{
        return a*potencia(a,(n,1));
    }
}


// Ejercicio 3.a. Suma las componentes de un vector. Recuerda que el segundo parámetro de 
// la función representa el tamaño del vector, no la posición de la última componente.
/*
{Pre: n es el tamaño de v, 0 < n <= 100 }
{Post: devuelve v[0]+v[1]+...+v[n-1] }
*/
int suma(int v[100],int n){
    if(n==1){
        return v[0];
    }
    else{
        return v[n-1]+suma(v,n-1);
    }
}


// Ejercicio 3.b. Calcula la media de los elementos de un vector.
//El siguiente subalgoritmo calcula la media de dos números
float promedio(int n1, int n2){
    float n;
    n = (n1+n2)/2;
    return n;
}
/*
{Pre: n es el tamaño de v, 0 < n <= 100 }
{Post: devuelve la media de todos los números de un vector}
*/
float media(int v[100],int n){
    if(n==1){
        return v[0];
    }
    else{
        return promedio(v[n-1],media(v,n-1));
    }   
    
}

//los siguiente dos subalgoritmos calculan el máximo y el mínimo de dos números, los cuales utilizaremos en los subprogramas que calculan máximos y mínimos de un vector

int max(int n1,int n2){
    if(n1>n2){
        return n1;
    }
    else{
        return n2;
    }
} 
int min(int n1,int n2){
    if(n1<n2){
        return n1;
    }
    else{
        return n2;
    }
} 
// Ejercicio 3.c. Calcula el máximo de los elementos de un vector.
/*
{Pre: n es el tamaño de v, 0 < n <= 100 }
{Post: devuelve el máximo del vector v }
*/
int maximo(int v[100],int n){
    if (n==1){
        return v[0];
    }
    else{
        return max(v[n-1],maximo(v,n-1));
    }
}

// Ejercicio 3.d. Calcula el mínimo de los elementos de un vector.
/*
{Pre: n es el tamaño de v, 0 < n <= 100}
{Post: devuelve el minimo del vector v }
*/
int minimo(int v[100],int n){
   if (n==1){
        return v[0];
    }
    else{
        return min(v[n-1],minimo(v,n-1));
    }
} 




TEST_CASE( "Calculando factoriales", "[factorial]" ) {
    REQUIRE( factorial(0) == 1 );
    REQUIRE( factorial(1) == 1 );
    REQUIRE( factorial(2) == 2 );
    REQUIRE( factorial(3) == 6 );
    REQUIRE( factorial(10) == 3628800 );
}

TEST_CASE( "Calculando potencias", "[potencia]" ) {
    REQUIRE( potencia(1,0) == 1 );
    REQUIRE( potencia(2,2) == 4 );
    REQUIRE( potencia(3,3) == 27 );
    REQUIRE( potencia(5,0) == 1 );
    REQUIRE( potencia(0,5) == 0 );
    REQUIRE( potencia(2,-4) == 0.0625 );
}

TEST_CASE( "Calculando suma de vectores", "[suma]" ) {
    int v1[] = {5, 15, 20, 25, 30};
    int v2[] = {1};
    int v3[] = {1,2,3,4,5};
    int v4[] = {1,2,3,4,5,5, 15, 20, 25, 30};

    REQUIRE( suma(v1,5) == 95 );
    REQUIRE( suma(v2,1) == 1 );
    REQUIRE( suma(v3,5) == 15 );
    REQUIRE( suma(v4,10) == 110 );
}

TEST_CASE( "Calculando maximo de vectores", "[potencias]" ) {
    int v1[] = {5, 15, 20, 25, 30};
    int v2[] = {1};
    int v3[] = {1,2,3,4,5};
    int v4[] = {1,2,3,4,30,5,5, 15, 20, 25};

    REQUIRE( maximo(v1,5) == 30 );
    REQUIRE( maximo(v2,1) == 1 );
    REQUIRE( maximo(v3,5) == 5 );
    REQUIRE( maximo(v4,10) == 30 );
}

TEST_CASE( "Calculando minimo de vectores", "[minimo]" ) {
    int v1[] = {5, 15, 20, 25, 30};
    int v2[] = {1};
    int v3[] = {1,2,3,4,5};
    int v4[] = {2,3,4,30,5,5, 15, 20, 25,1};

    REQUIRE( minimo(v1,5) == 5 );
    REQUIRE( minimo(v2,1) == 1 );
    REQUIRE( minimo(v3,5) == 1 );
    REQUIRE( minimo(v4,10) == 1 );
}

TEST_CASE( "Calculando media de vectores", "[media]" ) {
    int v1[] = {5, 15, 20, 25, 30};
    int v2[] = {1};
    int v3[] = {1,2,3,4,5};
    int v4[] = {2,3,4,30,5,5, 15, 20, 25,1};

    REQUIRE( media(v1,5) == 19 );
    REQUIRE( media(v2,1) == 1 );
    REQUIRE( media(v3,5) == 3 );
    REQUIRE( media(v4,10) == 11 );
}