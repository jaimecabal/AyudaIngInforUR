/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: geanozv
 *
 * Created on 28 de febrero de 2019, 11:05
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
struct tEstudiante{
    char dni[10];
    char nombre[31];
    char apellido[51];
};
struct tNotaAsig{
    char CodAsignatura[4];
    char DNI[9];
    char Nota[4];
};
void VerificarFichero(char nombref[]);
void altaNota(char nombrefestudiante[],char nombrefnota[]);
tNotaAsig leerNota(char dni[]);
bool existeEstudiante(char nombreE[],char dni[]);
tEstudiante completarInformacionEstudiante(char dni[]);
void guardaEstudiante(char nombrefEstudiantes[], tEstudiante e);
void guardaNota(char nombrefNotas[], tNotaAsig n);
void altaNota(char nombrefEstudiantes[],char nombrefNotas[]);
int main(int argc, char** argv) {
    ifstream nombreFEstudiantes;//estudiantes
    ifstream nombreFNota;//notas
    int seleccion;
    char nombreFEstudiante[30];
    char nombreFNotas[30];
    cout<<"introduce el nombre del fichero estudiantes"<<endl;
    cin>>nombreFEstudiante;
    cout<<"introduce el nombre del fichero de notas"<<endl;
    cin>>nombreFNotas;
    VerificarFichero(nombreFEstudiante);
    VerificarFichero(nombreFNotas);
    do{
    cout<<"Menu principal:"<<endl;
    cout<<"1.- Dar de alta"<<endl;
    cout<<"2.- Mostrar informacion de los estudiantes de la asignatura"<<endl;
    cout<<"3.- Modificar la nota del estudiante"<<endl;
    cout<<"4.- Dar de baja estudiante"<<endl;
    cout<<"5.- Nota media asignatura"<<endl;
    cout<<"6.- Terminar"<<endl;
    cout<<"elegir opcion:"<<endl;
    cin>>seleccion;
    switch(seleccion){
        case 1://dar de alta
            altaNota(nombreFEstudiante, nombreFNotas);
            break;
        case 2://mostrar informacion.
            break;
        case 3://modificar la nota del estudiante.
            break;
        case 4://dar de baja.
            break;
        case 5://nota media.
            break;
        case 6://terminar.
            cout<<"Has cerrado el programa"<<endl;
            break;
        default:
            cout<<"introduce un numero valido"<<endl;
            break;
    }
    }
    while(seleccion!=6);       
    
    return 0;
}

void VerificarFichero(char nombref[])
{
    ifstream f;
    f.open(nombref, ios::in|ios::binary);
    if(f) f.close();
    else
    {
        ofstream f2;
        f2.open(nombref, ios::out|ios::binary);
        f2.close();
    }   
    
}
void altaNota(char nombreFEstudiante[],char nombreFNota[]){
    char dni[10];
    cout<<"introduce el DNI del estudiante"<<endl;
    cin>>dni;
    if(!existeEstudiante(nombreFEstudiante,dni))
    {
        tEstudiante e;
        e=completarInformacionEstudiante(dni);
        guardaEstudiante(nombreFEstudiante,e);
    }
    tNotaAsig nota=leerNota(dni);
    guardaNota(nombreFNota,nota);
    
}
bool existeEstudiante(char nombreFEstudiante[],char dni[]){
    bool encontrado=false;
    tEstudiante e;
    ifstream f;
    f.open(nombreFEstudiante, ios::in|ios::binary);
    if(f){
        f.read((char*)& e,sizeof(e));
        while((!f.eof())&&(strcmp(e.dni,dni)<0)){
            f.read((char*)& e,sizeof(e));
        }
        if(strcmp(dni,e.dni)==0)
        {
            encontrado=true;
        }
        f.close();
    
    }
    
}
tEstudiante completarInformacionEstudiante(char dni[]){
    tEstudiante e;
    strcpy(e.dni,dni);
    cout<<"introduce el nombre del estudiante con DNI "<<dni<<endl;
    cin>>e.nombre;
    cout<<"introduce el apellido del estudiante con DNI "<<dni<<endl;
    cin>>e.apellido;
    return(e);
}
tNotaAsig leerNota(char dni[]){
    tNotaAsig n;
    strcpy(n.DNI,dni);
    cout<<"introduce el Codigo de la Asignatura"<<endl;
    cin>>n.CodAsignatura;
    cout<<"introduce la nota de la Asignatura dada"<<endl;
    cin>>n.Nota;
}
void guardaEstudiante(char nombreFEstudiantes[], tEstudiante e){
    tEstudiante es;
    ifstream f;
    ofstream g;
    f.open(nombreFEstudiantes,ios::in|ios::binary);
    g.open("auxiliar.dat",ios::out|ios::binary);
    
    if(existeEstudiante(nombreFEstudiantes,e.dni)){
        cout<<"el estudiante introducido ya existe";
    }
    else{
        if(f&&g){
        f.read((char*)& es,sizeof(es));
        while((!f.eof())&&(strcmp(e.dni,es.dni)<0)){
            g.write((char*)& es,sizeof(es));
            f.read((char*)& es,sizeof(es));
        }
        
        g.write((char*)& e,sizeof(e));
            
        
        f.read((char*)& es,sizeof(es));
        while(!f.eof()){
            g.write((char*)& es,sizeof(es));
            f.read((char*)& es,sizeof(es));
        }
        f.close();
        g.close();
        remove(nombreFEstudiantes);
        rename("auxiliar.dat",nombreFEstudiantes);
        
        
    }
}
}
void guardaNota(char nombreFNotas[],tNotaAsig n){
    tNotaAsig no;
    ifstream f;
    ofstream g;
    f.open(nombreFNotas,ios::in|ios::binary);
    g.open("auxiliar.dat",ios::out|ios::binary);
    
    if(existeEstudiante(nombreFNotas,n.DNI)){
        cout<<"el estudiante introducido ya existe";
    }
    else{
        if(f&&g){
        f.read((char*)& no,sizeof(no));
        while((!f.eof())&&(strcmp(n.DNI,no.DNI)<0)){
            g.write((char*)& no,sizeof(no));
            f.read((char*)& no,sizeof(no));
        }
        
        g.write((char*)& n,sizeof(n));
            
        
        f.read((char*)& no,sizeof(no));
        while(!f.eof()){
            g.write((char*)& no,sizeof(no));
            f.read((char*)& no,sizeof(no));
        }
        f.close();
        g.close();
        remove(nombreFNotas);
        rename("auxiliar.dat",nombreFNotas);
}
    }
}