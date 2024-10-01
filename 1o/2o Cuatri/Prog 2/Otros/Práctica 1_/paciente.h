/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   paciente.h
 * Author: geanozv
 *
 * Created on 10 de mayo de 2019, 10:25
 */
#include <iostream>
#ifndef PACIENTE_H
#define PACIENTE_H
struct Paciente{
    char nombre[25];
    char dni[10];
    int edad;
};
void crearPaciente(Paciente &,char [],char[],int);
void nombreP(Paciente,char[]);
void DNIP(Paciente,char[]);
void edadP(Paciente,int &);
void leerPaciente(Paciente &);
void mostrarPaciente(Paciente);
void copiarPaciente(Paciente, Paciente&);

#endif /* PACIENTE_H */

