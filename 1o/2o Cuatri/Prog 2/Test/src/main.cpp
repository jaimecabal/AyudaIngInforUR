#include <iostream>
#include <cstring>

using namespace std;
bool palindromo(char cadena[]);
bool palinCheck(char cadena[], int izq, int dcha);
int tmn(char cadena[],int l);
int longitud(char cadena[]);

int main(int argc, char *argv[]) {
	char cadena[100];
	strcpy(cadena,"oso");
	cout << "Size of cadena is: " << longitud(cadena) << endl;
	cout << cadena << " es : "<<palindromo(cadena) << endl;
}

int longitud(char cadena[]){
    /*
     * Se hace un subprograma para que vaya sumando y
     * compruebe si se ha llegado al fin del vector
     */
    return tmn(cadena,0);
}
int tmn(char cadena[],int l){
    if (cadena[l]=='\0'){
        return l;
    }
    else{
        tmn(cadena,l+1);
    }
}

bool palindromo(char cadena[]){
    char izq=0;
    char dcha=longitud(cadena);
    if(izq>dcha){
        /*si solo tiene una letra, siempre es palindromo*/
        return true;
    }else{
        return palinCheck(cadena,izq,dcha);
    }
}

bool palinCheck(char cadena[], int izq, int dcha){
    /* 
     * Si los indices se cruzan, devuelve cierto
     * esto es porque si llega a ese caso es que todas
     * las comprobaciones anteriores han sido ciertas
     */
    if(izq>dcha){
        return true;
    }else{
    /*Si no, se va comprobando si las letras son iguales*/
        if(cadena[izq]==cadena[dcha]){
            /*Si lo son, comprobar las siguientes*/
            return palinCheck(cadena,izq++,dcha--);
        }else{
            /*Si no lo son, devuelve false*/
            return false;
        }
    }
}