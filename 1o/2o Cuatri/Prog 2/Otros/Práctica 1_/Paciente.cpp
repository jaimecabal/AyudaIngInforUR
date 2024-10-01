
#include "paciente.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
void crearPaciente(Paciente &,char [],char[],int);



void mostrarPaciente(Paciente);
void copiarPaciente(Paciente, Paciente&);
void nombreP(Paciente & P,nombre[]){
    cout<<"introduce el nombre de paciente: "<<endl;
    cin>>nombre;
    strcpy(P.nombre,nombre);
}
void edadP(Paciente p,int & A){
    cout<<"introduce la edad del paciente: "<<endl;
    cin>>A;
    p.edad=A;
}
void DNIP(Paciente p,dni[]){
    cout<<"introduce el dni del paciente: "<<endl;
    cin>>dni;
    strcpy(P.dni,dni);
}
void crearPaciente(Paciente & p,nombre[],dni[],int edad){
    nombreP(p,nombre);
    DNIP(p,dni);
    edadP(p,edad);
}
