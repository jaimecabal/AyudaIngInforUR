/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: geanozv
 *
 * Created on 24 de mayo de 2019, 9:08
 */


#include <cstdio>

#include <cstdlib>
#include "ArbolBinario.h"
using namespace std;
//void arbolGenealogico1(arbolBin & a,int n);
void arbolGenealogico(arbolBin & a);
bool SonIguales(arbolBin & a1,arbolBin & a2);
/*
 * 
 */
int main() {
    bool Son;
    arbolBin a1,a2;
    /*int generacion1,generacion2;
     cout<<"introduce las generaciones que quieras representar"<<endl;
    cin>>generacion1;
    cout<<"introduce las generaciones que quieras representar"<<endl;
    cin>>generacion2;*/
    arbolGenealogico(a1);
    arbolGenealogico(a2);
    Son=SonIguales(a1,a2);
    cout<<Son<<endl;
    
    return 0;
}
void arbolGenealogico(arbolBin & a){

    arbolBin ppa, mpa, pma, mma, pa, ma, nulo;
    iniciarArbol(nulo);
    telemento raizppa,raizmpa,raizpma,raizmma,raizpa,raizma,raiza;

     cout<<"introduce el nombre del ppa ";
    cin>>raizppa;
    cout<<"introduce el nombre de la mpa ";
    cin>>raizmpa;
    cout<<"introduce el nombre del pma ";
    cin>>raizpma;
    cout<<"introduce el nombre de la mma ";
    cin>>raizmma;
    cout<<"introduce el nombre del pa ";
    cin>>raizpa;
    cout<<"introduce el nombre de la ma ";
    cin>>raizma;
    cout<<"introduce el nombre de a";
    cin>>raiza;
    enraizar(ppa,nulo,nulo,raizppa);
    enraizar(mpa,nulo,nulo,raizmpa);
    enraizar(pma,nulo,nulo,raizpma);
    enraizar(mma,nulo,nulo,raizmma);
    enraizar(pa,ppa,mpa,raizpa);
    enraizar(ma,pma,mma,raizma);
    enraizar(a,pa,ma,raiza);

}




/*void arbolGenealogico1(arbolBin & a,int generacion){
telemento familiar1;
iniciarArbol(a);
iniciarArbol(a->dcho);
iniciarArbol(a->izdo);
arbolBin derechoA,izquierdoA;
derechoA=Derecho(a);
    izquierdoA=Izquierdo(a);
if(generacion==0){
    cout<<"Has Acabado el arbol."<<endl;
    
    }else{
    
        if(generacion==1){
         cout<<"introduce el familiar "<<generacion<<". "<<endl;
         cin>>familiar1; 
   
         enraizar(a,derechoA,izquierdoA,familiar1);
         arbolGenealogico1(a,generacion-1);
   
            }else{if(generacion>1){
    
                arbolGenealogico1( derechoA,generacion-1);
                arbolGenealogico1( izquierdoA,generacion-1);
                raiz(a,familiar1);
                enraizar(a,derechoA, izquierdoA,familiar1);
                }
    
            }
        }
}*/

bool SonIguales(arbolBin & a1,arbolBin & a2){
    arbolBin derechoa1,izquierdoa1,derechoa2,izquierdoa2;
    derechoa1=Derecho(a1);
    izquierdoa1=Izquierdo(a1);
    derechoa2=Derecho(a2);
    izquierdoa2=Izquierdo(a2);
    telemento aux1,aux2;
    if(arbolVacio(a1)&&(arbolVacio(a2))){
        return(true);
    }else{
        if (!arbolVacio(a1)){
        if(arbolVacio(a2)){
            return(false);}
          }else{
            if(!arbolVacio(a2)){
                if(arbolVacio(a1)){
            return(false);} 
            }else{
                raiz(a1,aux1);
                raiz(a2,aux2);
                if(strcmp(aux1,aux2)==0){
                    return(SonIguales(derechoa1,derechoa2)&&SonIguales(izquierdoa1,izquierdoa2));
                            
                }else{
                    return(false);
                }
            }
        }
    }
}