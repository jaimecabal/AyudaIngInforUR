/*
 * Agencia alquiler de coches, fichero COCHES.DAT
 * Fichero ordenador alfabeticamente por marcas usando 
 * tcoche
 * Subprograma que a partir de los datos de coche
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

struct tcoche{
    char marca[30];
    char matricula[7];
    float kms;
};

using namespace std;

tcoche leerCoche();
void modificarDatos(tcoche ch);

int main(int argc, char** argv) {

    modificarDatos(leerCoche());

    return 0;
}

tcoche leerCoche(){
    tcoche ch;
    cout << "Introduce la marca de coche" << endl;
    cin >> ch.marca;

    cout << "Introduce la matricula del coche" << endl;
    cin >> ch.matricula;

    cout << "Introduce los kms que ha hecho el coche" << endl;
    cin >> ch.kms;
    return ch;
}

void modificarDatos(tcoche ch){
    ifstream f;
    bool encontrado;
    encontrado=false;
    f.open("coches.dat",ios::in|ios::binary);
        if(f){
            f.read((char *)&ch,sizeof(ch));
            while(!f.eof() && encontrado==false){
                
            }
        }else{
            cout << "Inutil" << endl;
        }
    f.close();
}