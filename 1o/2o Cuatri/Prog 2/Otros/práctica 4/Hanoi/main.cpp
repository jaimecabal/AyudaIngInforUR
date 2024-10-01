/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: geanozv
 *
 * Created on 15 de marzo de 2019, 10:24
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

void mueve(int n, char origen, char destino, char auxiliar);
int main(int argc, char** argv) {
    
    int n;
    cout<<"introduce el numero de discos: "<<endl;
    cin>>n;
    mueve(n,'A','B','C');
    return 0;
}

void mueve(int n,char origen,char destino,char auxiliar){
           
    if(n==1)
        cout<<"mueve el disco 1 desde "<<origen<<" hasta "<<destino<<endl;
    else{
 
        
        mueve(n-1,origen, auxiliar,destino);
        cout<<"Mueve el disco "<<n<<" desde "<<origen<<" hasta "<<destino<<endl;
        mueve(n-1,auxiliar,destino,origen);
        
        
    }
}