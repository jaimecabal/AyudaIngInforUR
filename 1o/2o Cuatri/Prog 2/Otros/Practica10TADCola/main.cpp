#include <iostream>
#include "cola.h"
#include "paciente.h"

using namespace std;

void copiarCola(cola &c1, cola &c2);
void nuevaCita(cola & c);
void atiende(cola & c1, cola & c2);
void listaPacientes(cola & c1);
int numeroPacientesPendientes(cola & c);
void pacienteMasJoven(cola & c);

int main()
{
    int opcion;
    cola pendientes;
    cola atendidos;
    iniciarCola(pendientes);
    iniciarCola(atendidos);
    do{
        cout<< "MENU"<<endl;        
        cout<<"1) Crear cola de citas"<<endl;
        cout<<"2) Nueva Cita"<<endl;
        cout<<"3) Atiende paciente"<<endl;
        cout<<"4) Listado de pacientes pendientes"<<endl;
        cout<<"5) Numero de pacientes pendientes"<<endl;
        cout<<"6) Listado de pacientes atendidos"<<endl;
        cout<<"7) Ver paciente más jóven"<<endl;
        cout<<"8) Fin"<<endl;
        cout<<"------------------------------------"<<endl;
        cin >>opcion;
        switch(opcion){
            case 1:
               iniciarCola(pendientes);
                break;
            case 2:
                nuevaCita(pendientes);
                break;
            case 3:                
                atiende(pendientes,atendidos);
                break;
            case 4:
                listaPacientes(pendientes);
                break;
            case 5:
                cout<<"El numero de pacientes pendientes es"<<numeroPacientesPendientes(pendientes)<<endl;
                break;
            case 6:
                listaPacientes(atendidos);                
                break;
            case 7: 
                pacienteMasJoven(atendidos);
                break;
            case 8:
                break;
            default:
                cout << "Introduce una opcion valida"<<endl;
        }
    }while(opcion!=8);    
}



void nuevaCita(cola & c){
    Paciente p;
    leerPaciente(p);
    anadir(c,p);
}

void atiende(cola & c1, cola & c2){
    if(!colaVacia(c1)){
        Paciente p = primero(c1);
        anadir(c2,p);        
        eliminar(c1);
        cout<<"Se ha atendido al paciente:"<<endl;
        mostrarPaciente(p);
    }else{
        cout<<"No quedan pacientes"<<endl;
    }
}

void listaPacientes(cola & c){
    int i=1;
    Paciente p;
    cola aux;
    copiarCola(c,aux);        
    while(!colaVacia(aux)){
        cout<<"Paciente "<< i << endl;
        p = primero(aux);
        mostrarPaciente(p);        
        eliminar(aux);
        i++;
    }    
}


int numeroPacientesPendientes(cola & c){
    int i=0;
    Paciente p;
    cola aux;
    copiarCola(c,aux);        
    while(!colaVacia(aux)){                      
        i++;
        eliminar(aux);
    }    
    return i;
}


void pacienteMasJoven(cola & c)
//PRE: La cola no es vacía
{
    Paciente masJoven, p;
    cola aux;
    copiarCola(c, aux);
    masJoven = primero(aux);
    while(!colaVacia(aux)){
        p = primero(aux);
        if(edadPaciente(p)<edadPaciente(masJoven)){
            //copiarPaciente(p,masJoven);
            masJoven=p;
        }        
        eliminar(aux);
    }    
    cout << "El paciente mas joven es:"<<endl;
    mostrarPaciente(masJoven);
}

void copiarCola(cola &c1, cola &c2)
//PRE: c1 está iniciada, de c2 no digo nada.
{
    cola aux;
    iniciarCola(aux);
    iniciarCola(c2);
    while (!colaVacia(c1))
    {
        anadir(aux, primero(c1));
        anadir(c2, primero(c1));
        eliminar(c1);
    }
    while (!colaVacia(aux))
    {
        anadir(c1, primero(aux));
        eliminar(aux);
    }
}

