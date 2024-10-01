#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>

using namespace std;

struct tEmpleado{
	char dni[10];
	char nombre[30];
	int horas_trabajadas;
	int precio_hora;
};

void crearFichero(char nombref[30]);
tEmpleado leerEmpleado();
void trabajaMas40Horas(char nombref[30]);
void escribirEmpleado(tEmpleado empl);
void mostrarEmpleado(char dni[10],char nombref[30]);
void appendFichero(char nombref[30]);
void insertarPos(char nombref[30],int pos);

int main() {
	ifstream f;
	char nombref[30];
	strcpy(nombref,"empleados.dat");
	f.open(nombref,ios::in);
	if(!f){
		crearFichero(nombref);
	}
	int m;
	cout << "Introduce el apartado que quieres hacer" << endl;
	cin >> m;
	if(m==1){
		trabajaMas40Horas(nombref);
	}else if(m==2){
		char dni[10];
		cout <<"Introduce el dni a mostrar"<<endl;
		cin>>dni;
		mostrarEmpleado(dni,nombref);
	}else if(m==3){
		appendFichero(nombref);
	}else if(m==4){
		int pos;
		cout << "En que posicion se va a insertar" <<endl;
		cin >>pos;
		insertarPos(nombref,pos);
	}
	f.close();
}
void crearFichero(char nombref[30]){
	ofstream f;
	tEmpleado empl;
	int n;
	int i;
	cout<<"Introduce el numero de empleados que quieres añadir al fichero"<<endl;
	cin >>n;
	f.open(nombref,ios::out);
		if(f){
			for(i=0;i<=n;i++){
				empl=leerEmpleado();
				f<<empl.dni << " " << empl.nombre << " " << empl.horas_trabajadas << " " << empl.precio_hora<<endl;
			}
		}else{
			cout << "Inutil" <<endl;
		}
	f.close();
}
tEmpleado leerEmpleado(){
	tEmpleado empl;
	
	cout<<"Introduce el dni del empleado"<<endl;
	cin>>empl.dni;
	cout << "Introduce el nombre del empleado" << endl;
	cin>>empl.nombre;
	cout<<"Introduce las horas que trabaja la semana" << endl;
	cin>>empl.horas_trabajadas;
	cout<<"Introduce el precio que cobra por semana" << endl;
	cin>>empl.precio_hora;
	
	return empl;
}
void escribirEmpleado(tEmpleado empl){
	cout<<"DNI: " << empl.dni <<endl;
	cout<<"Nombre: " << empl.nombre <<endl;
	cout<<"Horas semanales de trabajo: " << empl.horas_trabajadas <<endl;
	cout<<"Precio por hora: " << empl.precio_hora <<endl;
}
void trabajaMas40Horas(char nombref[30]){
	ifstream f;
	tEmpleado empl;
	f.open(nombref,ios::in);
	if(f){
		f>>empl.dni;
		while(!f.eof()){
			f>>empl.nombre>>empl.horas_trabajadas>>empl.precio_hora;
			if(empl.horas_trabajadas>40){
				cout<<"El nombre es: "<< empl.nombre<<endl;
				cout<<"El sueldo semanal es: "<< empl.horas_trabajadas*empl.precio_hora<<" euros."<<endl;
			}
			f>>empl.dni;
		}
	}else{
		cout << "Inutil" << endl;
	}
	f.close();
}
void mostrarEmpleado(char dni[10],char nombref[30]){
	ifstream f;
	tEmpleado empl;
	bool encontrado;
	encontrado=false;
	f.open(nombref,ios::in);
	if(f){
		f>>empl.dni;
		while(!f.eof() && encontrado==false){
			if(!strcmp(dni,empl.dni)){
				encontrado=true;
			}
			f>>empl.nombre>>empl.horas_trabajadas>>empl.precio_hora;
			f>>empl.dni;
		}
		if(encontrado==true){
			escribirEmpleado(empl);
		}
	}else{
		cout << "El fichero no existe" <<endl;
	}
	f.close();
}
void appendFichero(char nombref[30]){
	ofstream f;
	tEmpleado empl;
	f.open(nombref,ios::out|ios::app);
	if(f){
		empl=leerEmpleado();
		f<<empl.dni << " " << empl.nombre << " " << empl.horas_trabajadas << " " << empl.precio_hora<<endl;
	}else{
		cout<<"No existe el fichero";
	}
	f.close();
}
void insertarPos(char nombref[30],int pos){
	ofstream aux;
	ifstream f;
	tEmpleado empl,nuevoEmpl;
	int contador;
	contador=1;
	nuevoEmpl=leerEmpleado();

	f.open(nombref,ios::in);
	aux.open("aux.dat",ios::out);
	if(f && aux){
		f>>empl.dni;
		while(!f.eof()&&contador<pos){
			f>>empl.nombre>>empl.horas_trabajadas>>empl.precio_hora;
			aux<<empl.dni << " " << empl.nombre << " " << empl.horas_trabajadas << " " << empl.precio_hora<<endl;
			f>>empl.dni;
			contador++;
		}
		aux<<nuevoEmpl.dni << " " << nuevoEmpl.nombre << " " << nuevoEmpl.horas_trabajadas << " " << nuevoEmpl.precio_hora<<endl;
		while(!f.eof()){
			f>>empl.nombre>>empl.horas_trabajadas>>empl.precio_hora;
			aux<<empl.dni << " " << empl.nombre << " " << empl.horas_trabajadas << " " << empl.precio_hora<<endl;
			f>>empl.dni;
		}
	}
	aux.close();
	f.close();

	remove(nombref);
	rename("aux.dat",nombref);
}