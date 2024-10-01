/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: geanozv
 *
 * Created on 22 de marzo de 2019, 10:58
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

/*
 * 
 */
void busqSecR (int v[],int , int ,bool & esta, int & pos); 
int main(int argc, char** argv) {
    int n;
    int clave; 
    int v[100];
    int pos=0;
     cout<<"introduce el tamaño: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"introduce la componente "<<i<<" del vector: "<<endl;
        cin>>v[i];
    }
    cout<<"introduce la clave a buscar: "<<endl;
    cin>>clave;
    busqSecR(v,n,clave,esta,pos);

    return (EXIT_SUCCESS);
}

void busqSecR (int v[],int n, int clave,bool & esta, int & pos){
   
    if(n==0){
        pos=-1;
        cout<<esta<<" "<<pos; 
    }
    if(v[n-]=clave){
        pos=n;
        esta=true;
    cout<<esta<<" "<<pos;
    }else busqSecR(v,n-1,clave,esta,pos);
}