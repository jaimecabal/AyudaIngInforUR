#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

struct tSuscriptor{
    int idS;
    char nombre[20],direccion[30],telef[10],ciudad[15];
};

tSuscriptor aniadir ();
void aniadirSuscripicion (char fichero[]);
void leerDatos (char fichero[]);
void mostrarDatos(char fichero[]);
int main()
{
    char fichero[20];
    cout<<"Introduce el nombre del fichero: "<<endl;
    cin>>fichero;
    leerDatos(fichero);
    mostrarDatos(fichero);
    aniadirSuscripicion(fichero);
    mostrarDatos(fichero);
}

void leerDatos (char fichero[]){
    ofstream archivo;
    tSuscriptor t;
    archivo.open(fichero,ios::out|ios::binary);
    if (archivo){
            t=aniadir();
            while (t.idS!=0){
                archivo.write((char *)&t,sizeof(t));
                t=aniadir();
            }
    }
    archivo.close();
}

tSuscriptor aniadir (){
    tSuscriptor n;
    cout<<"-------------------------------------"<<endl;
    cout<<"  Introduce el id:"<<endl;
    cin>>n.idS;
    cout<<"  Introduce el nombre:"<<endl;
    cin>>n.nombre;
    cout<<"  Introduce el direccion:"<<endl;
    cin>>n.direccion;
    cout<<"  Introduce el telefono:"<<endl;
    cin>>n.telef;
    cout<<"  Introduce el ciudad:"<<endl;
    cin>>n.ciudad;
    return n;
}

void mostrarDatos(char fichero[]){
    ifstream archivo;
    tSuscriptor t;
    archivo.open(fichero,ios::in|ios::binary);
    if (archivo){
        archivo.read((char *)&t,sizeof(t));
        while (!archivo.eof()){
            cout<<"-------------------------------------"<<endl;
            cout<<"  El id:"<<t.idS<<endl;
            cout<<"  El nombre:"<<t.nombre<<endl;
            cout<<"  La direccion:"<<t.direccion<<endl;
            cout<<"  El telefono:"<<t.telef<<endl;
            cout<<"  La ciudad:"<<t.ciudad<<endl;
            archivo.read((char *)&t,sizeof(t));
        }
    }
    archivo.close();
}

void aniadirSuscripicion (char fichero[]){
    ifstream archivo;
    ofstream auxiliar;
    tSuscriptor t,subs;
    archivo.open(fichero,ios::in|ios::binary);
    auxiliar.open("Auxiliar.dat",ios::app|ios::binary);
    if ((archivo)&&(auxiliar)){
         archivo.read((char *)&t,sizeof(t));
            while (!archivo.eof()){
                auxiliar.write((char *)&t,sizeof(t));
                archivo.read((char *)&t,sizeof(t));
            }
        subs=aniadir();
        auxiliar.write((char *)&subs,sizeof(subs));
    }
    archivo.close();
    auxiliar.close();
    remove(fichero);
    rename("Auxiliar.txt",fichero);
}