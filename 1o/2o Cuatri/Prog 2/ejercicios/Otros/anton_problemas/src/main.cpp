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
void leerDatos (char fichero[]);
int main()
{
    char fichero[20];
    cout<<"Introduce el nombre del fichero: "<<endl;
    cin>>fichero;
    leerDatos(fichero);
}

void leerDatos (char fichero[]){
    ofstream archivo;
    tSuscriptor t;
    int n;
    archivo.open(fichero,ios::out|ios::binary);
    cout<<" Introduce el numero de datos: ";
    cin>>n;
    if (archivo){
        for (int i=0;i<n;i++)
        {
            t=aniadir();
            archivo.write((char *)&t,sizeof(t));
        }
    }
}

tSuscriptor aniadir (){
    tSuscriptor n;
    cout<<"-------------------------------------";
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
    cout<<"-------------------------------------";
    return n;
}