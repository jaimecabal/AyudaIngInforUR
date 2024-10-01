#include <iostream>
#include <cstring>
#include "paciente.h"

using namespace std;
void creaPaciente(Paciente & p, char nombre[], char dni[], int edad)
{
    strcpy(p.nombre,nombre);
    strcpy(p.dni,dni);
    p.edad=edad;
}
int edadPaciente(Paciente p)
{
    return p.edad;
}
void nombrePaciente(Paciente p, char nombre[]) //devuelve nombre en el vector de e/s nombre.
{
     strcpy(nombre,p.nombre);
}
void dniPaciente(Paciente p, char dni[]) //devuelve dni en el vector de e/s dni.
{
    strcpy(dni,p.dni);
}

void mostrarPaciente(Paciente p)
{
    cout<<"NOMBRE: "<<p.nombre<<endl;
    cout<<"DNI: "<<p.dni<<endl;
    cout<<"EDAD: "<<p.edad<<endl;
}

void leerPaciente(Paciente &p)
{
    cout<<"Introduce el nombre"<<endl;
    cin>>p.nombre;
    cout<<"Introduce el dni"<<endl;
    cin>>p.dni;
    cout<<"Introduce la edad"<<endl;
    cin>>p.edad;
}

void copiarPaciente(Paciente p1,Paciente & p2) //En realidad no la necesitamos porque es una asignación de structs: p2=p1;
//Copias p1 en p2
{
    strcpy(p2.nombre,p1.nombre);
    strcpy(p2.dni,p1.dni);
    p2.edad=p1.edad;
}

