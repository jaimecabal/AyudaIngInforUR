/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: geanozv
 *
 * Created on 29 de marzo de 2019, 9:04
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    int *p;
    int x;
    cout<<"La direccion de x es, "<<&x<<"."<<endl;
    cout<<"La dirección de p es, "<<&p<<"."<<endl;
    cout<<"El destino de p es, "<<*p<<"."<<endl;
    cout<<"La dirección del destino de p es,"<<*(&p)<<".";
            
    return 0;
}

