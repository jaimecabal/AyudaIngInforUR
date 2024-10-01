#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch(1).hpp"


using namespace std;

int longitudInv(char cadena[],int suma){
      
    if (cadena[suma]=='\0') 
        return suma;
   else  
       return longitudInv(cadena,suma+1);
       
}

// Ejercicio 1. Función recursiva que calcule longitud de cadena de caractéres
/*
{Pre: }
{Post: }
*/
int longitud(char cadena[]){
    
  
        return(longitudInv(cadena,0));
    

}
// Ejercicio 2. FunciÃ³n recursiva que dada una cadena de caracteres sin espacios
// en blanco, devuelve verdad si dicha cadena es un palÃ­ndromo y falso en caso contrario.
/*
{Pre: }
{Post: }
*/
bool palindromoInm(char cadena[],int i,int j){
    if(i>=j){
        return true;
    }else{
        if(cadena[i]==cadena[j]){
            return(palindromoInm(cadena,i+1,j-1));
        }else{
            return false;
        }
    }
}
bool palindromo(char cadena[]){
    
    return palindromoInm(cadena,0,longitud(cadena)-1);
}


// Ejercicio 3. FunciÃ³n recursiva que dada una cadena de caracteres sin espacios en blanco,
// devuelve verdad si dicha cadena contiene la letra â€˜Aâ€™ y falso en caso contrario.
/*
{Pre: }
{Post: }
*/
bool contieneLaAInv(char cadena[],int suma){
   
      if(cadena[suma]=='\0'){
        return false;}
    
    if(cadena[suma]=='A'){
        return true;
    }else{
        return(contieneLaAInv(cadena,suma+1));
  
        
    }
}

bool contieneLaA(char cadena[]){
    
    return contieneLaAInv(cadena,0);
    

}






// Casos de prueba
TEST_CASE( "Calculando longitudes", "[longitud]" ) {
    REQUIRE( longitud((char *)"Hola") == 4 );
    REQUIRE( longitud((char *)"Adios") == 5 );
    REQUIRE( longitud((char *)"") == 0 );
}

TEST_CASE( "Comprobando palindromos", "[palindromos]" ) {
    REQUIRE( palindromo((char *)"dabaleelabad") == true );
    REQUIRE( palindromo((char *)"abba") == true );
    REQUIRE( palindromo((char *)"abcde") == false );
    REQUIRE( palindromo((char *)"abcdecba") == false );
    REQUIRE( palindromo((char *)"") == true );
    REQUIRE( palindromo((char *)"arrozalazorra") == true );
}

TEST_CASE( "Comprobando si cadenas contienen la letra A", "[contieneLaA]" ) {
    REQUIRE( contieneLaA((char *)"Pepe") == false );
    REQUIRE( contieneLaA((char *)"Pepa") == false );
    REQUIRE( contieneLaA((char *)"PEPA") == true );
    REQUIRE( contieneLaA((char *)"") == false );
    REQUIRE( contieneLaA((char *)"ABCDE") == true );
    REQUIRE( contieneLaA((char *)"BCADC") == true );
}
