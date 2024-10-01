/* 
 * File:   main.c++
 * Author: Charo
 *
 * 
 */

#include <iostream>

using namespace std;

void seanParesInm(int v[],int n,int &cont,int &num);
int seanPares(int v[], int n);
void numVecesInm (int v[], int n, int k, int &veces);
int numVecesFinal (int v[], int n, int k);
void modaInv(int v[], int n, int &moda, int &numModa);
int moda(int v[], int n);

int main() {
    int a[]={7,3,5,3};
    int b[]={7,2,8,1,5,4,6};
    int c[]={7,2,8,1,5,6,10,4,3,2,3};
    int d[]={7,2,1,5,3};
    int e[]={1,1,1,1,1};
    int num;
    cout<<"Numero de veces que aparece valor"<<endl;
    num= numVecesFinal(a,4,3);
    cout<<"Vector a: "<<num<<endl;
    num= numVecesFinal(b,7,1);
    cout<<"Vector b: "<<num<<endl;
    num= numVecesFinal(c,11,2);
    cout<<"Vector c: "<<num<<endl;
    num= numVecesFinal(d,5,6);
    cout<<"Vector d: "<<num<<endl;
    num= numVecesFinal(e,5,1);
    cout<<"Vector e: "<<num<<endl;
    num= numVecesFinal(e,5,2);
    cout<<"Vector e: "<<num<<endl;
    
    cout<<"Moda"<<endl;
    num= moda(a,4);
    cout<<"Vector a: "<<num<<endl;
    num= moda(b,7);
    cout<<"Vector b: "<<num<<endl;
    num= moda(c,11);
    cout<<"Vector c: "<<num<<endl;
    num= moda(d,5);
    cout<<"Vector d: "<<num<<endl;
    num= moda(e,5);
    cout<<"Vector e: "<<num<<endl;
    
    cout<<"seanPares"<<endl;
    num= seanPares(a,4);
    cout<<"Vector a: "<<num<<endl;
    num= seanPares(b,7);
    cout<<"Vector b: "<<num<<endl;
    num= seanPares(c,11);
    cout<<"Vector c: "<<num<<endl;
    num= seanPares(d,5);
    cout<<"Vector d: "<<num<<endl;
    num= seanPares(e,5);
    cout<<"Vector e: "<<num<<endl;
    
    
    return 0;
}


//Ej1: Misma solución que la propuesta a los alumnos
/*Diseña una función recursiva que, dado un vector v de enteros, de tamaño n, y un
entero k, calcule el número de veces que k aparece en v. 
 */
void numVecesInm (int v[], int n, int k, int &veces)
{
    if (n>0)
    {
        if (v[n-1]==k) veces++;
        numVecesInm(v,n-1,k,veces);
    }
}

int numVecesFinal (int v[], int n, int k)
{
    int veces = 0;
    numVecesInm(v,n,k,veces);
    return veces;
}
//Ej2. Versión final (más eficiente): numVecesInm como acción
//Con menos variables que el propuesto en las soluciones
//Me apoyo en llamar a modaInm(v, n-1, moda, numModa) dentro del de inmersión reduciendo el valor de n. Con ello hago que las llamadas a numVecesFinal cada vez sea más pequeña también porque está buscando en un n vector más pequeño. 
//Tened en cuenta que si tenemos un vector a=[2,3,4,3,5,3], la moda de 3 es 3 veces, si luego lo voy reduciendo, en el siguiente 3 que vaya a buscar (hacia la izquierda) ya sólo está 2 veces pero te da igual porque no necesitas guardarlo… quiero decir, los que te comes a la derecha (cuando vas a la izquierda) ya los cogiste la primera vez que te aparecía. 

void modaInv(int v[], int n, int &moda, int &numModa){
    if (n>0)
    {
        int m = numVecesFinal(v,n,n-1);
        if (numModa<m) {numModa=m;moda=v[n-1];}
        modaInv(v,n-1,moda,numModa);
    }
    
}

int moda(int v[], int n){
    int moda=0, numModa=0;
    modaInv(v,n,moda,numModa);
    return moda;
}

//Ej3. Similar al propuesto como solución
void seanParesInm(int v[],int n,int &cont,int &num){
    
    if (n>0)
    {
        if (v[n-1]%2==0){
			cont++;
			if (cont > num) num=cont;
		}else cont=0;
        seanParesInm(v,n-1,cont,num);
    }
        
}

int seanPares(int v[], int n){
    int num=0, cont=0;
    seanParesInm(v,n,cont,num);
    return num;
}


/*ALTERNATIVA EJERCICIO 1. Mejor la de inmversión final propuesta arriba.
 int numVeces (int v[], int n, int k)
{
    if (n==0)
    {
        return 0;
    }
    else
    {
        if (v[n-1]==k)
        {
            return (1+numVeces(v,n-1,k));
        }
        else
            return (numVeces(v,n-1,k));
    }
}
int numVecesFinal (int v[], int n, int k)
{
    return numVecesInm(v,n,k);
}

 
 */