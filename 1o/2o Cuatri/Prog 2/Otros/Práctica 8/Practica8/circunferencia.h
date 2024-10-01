/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   circunferencia.h
 * Author: Charo
 *
 * 
 */

#include "punto.h"
#include<iostream>
#include<cstdlib>
using namespace std;

struct circunferencia{
    punto centro;
    float radio;
};

void crearCircunferencia(punto p,float radio,circunferencia &c);
float radio(circunferencia c);
punto centro(circunferencia c);

