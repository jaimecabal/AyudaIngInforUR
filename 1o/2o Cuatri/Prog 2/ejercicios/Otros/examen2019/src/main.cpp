#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;

struct tProductos{
    char codProducto[5];
    char nombre[40];
    float precio;
};

void eliminar(char fichero[]);
void crearFichero(char fichero[]);
tProductos nuevoProducto();
void leerFichero(char fichero[]);
void calcularMedia(char fichero[]);

int main(){
    char fichero[100];
    int m;

	cout<<" Introduce el nombre del fichero:"<<endl;
    cin.getline(fichero,100);
	
	cout << "Introduce el apartado: "<<endl;
	cout << "1: Eliminar "<<endl;
	cout << "2: Media Precios "<<endl;
	cin >>m;
	
	crearFichero(fichero);
	leerFichero(fichero);

	if(m==1){
    	eliminar(fichero);
		leerFichero(fichero);
	}else if(m==2){
		calcularMedia(fichero);
	}else{
		cout << "Inutil" <<endl;
	}

    return 0;
}
void crearFichero(char fichero[]){
	ofstream f;
	f.open(fichero,ios::out|ios::binary);
	tProductos prod;
	int n,i;
	if(f){
		cout << "Introduce el numero de productos que va a insertar" << endl;
		cin >> n;
		for(i=0;i<n;i++){
			prod=nuevoProducto();
			f.write((char *)&prod,sizeof(prod));
		}
	}else{
		cout << "Sa matao" << endl;
	}
	f.close();
}

tProductos nuevoProducto(){
	tProductos prod;

	cout<< "Introduce el codigo de producto" <<endl;
	cin >> prod.codProducto;
	cout<< "Introduce el nombre del producto" <<endl;
	cin >> prod.nombre;
	cout<< "Introduce el precio del producto" <<endl;
	cin >> prod.precio;
	
	return prod;
}
void eliminar(char fichero[]){
	/*
	*	PRE: Cadena de caracteres con el nombre del fichero a modificar
	*	POST: Devolver un fichero donde se ha eliminado el dato que se le ha pedido al usuario
	*	Coste: o(n) ???
	*/
    ifstream f;
    ofstream aux;
    tProductos t;
    char codigo[5];
    cout<<" Introduce el codigo que deseas eliminar: "<<endl;
    cin>>codigo;
    f.open(fichero,ios::in|ios::binary);
    aux.open("aux.dat",ios::out|ios::binary);
    if ((f)&&(aux)){
        f.read((char *)&t,sizeof (t));
        while ((!f.eof())&&(strcmp(codigo,t.codProducto)<0)){
            aux.write((char *)&t,sizeof (t));
            f.read((char *)&t,sizeof (t));
        }
		if(!strcmp(codigo,t.codProducto)){
        	f.read((char *)&t,sizeof (t));
		}
		while (!f.eof()){
            aux.write((char *)&t,sizeof (t));
            f.read((char *)&t,sizeof (t));
        }
    }
	f.close();
    aux.close();
	remove(fichero);
	rename("aux.dat",fichero);
}
void leerFichero(char fichero[]){
	ifstream f;
	tProductos prod;

	f.open(fichero,ios::in|ios::binary);
	f.read((char *)&prod,sizeof(prod));
	if(f){
		while(!f.eof()){
			cout << "Codigo producto: "<<prod.codProducto <<endl;
			cout << "Nombre producto: "<<prod.nombre <<endl;
			cout << "Precio producto: "<<prod.precio <<endl;
			f.read((char *)&prod,sizeof(prod));
		}
	}
	
	f.close();
}
void calcularMedia(char fichero[]){
	/*
	*	PRE: 	Tenemos un fichero creado con datos de producto y le pasamos a la funcion el nombre del fichero
	*	POST: 	Muestra por pantalla la media del precio de los productos
	*	COSTE:  o(n) ???
	*	
	*/
	ifstream f;
	tProductos prod;
	int contador=0;
	float suma=0,media=0;
	
	f.open(fichero,ios::in|ios::binary);
	if(f){
		f.read((char *)&prod,sizeof(prod));
		while(!f.eof()){
			suma=suma+prod.precio;
			contador++;
			f.read((char *)&prod,sizeof(prod));
		}
		media=suma/contador;
		cout << "La media de precio es: "<< media <<endl;
	}else{
		cout << "Sa matao" <<endl;
	}
	f.close();
}