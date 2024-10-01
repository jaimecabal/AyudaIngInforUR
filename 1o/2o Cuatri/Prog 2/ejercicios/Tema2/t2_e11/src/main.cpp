#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

struct tEmpleado{
	char dni[10];
	char nombre[20];
	int horas_trabajadas;
	int precio_hora;
};
void empleadosMas40Horas(char nombrefEmpleados[30]);
void 
int main() {
	ifstream f;
	int m;
	char nombrefEmpleados[30];
	strcpy(nombrefEmpleados,"empleados.dat");
	f.open(nombrefEmpleados,ios::in|ios::binary);
	cout << "Introduce que apartado quieres hacer" << endl;
	cin >> m;
	switch(m){
		case 1:{
			empleadosMas40Horas(nombrefEmpleados);
			break;
		}
		case 2:{
			break;
		}
		case 3:{
			break;
		}
		case 4:{
			break;
		}
		case 5:{
			break;
		}
		case 6:{
			break;
		}
		case 7:{
			break;
		}
		case 8:{
			break;
		}
		default:{
			cout << "Venga, adios" << endl;
			break;
		}
	}
	f.close();
}
void empleadosMas40Horas(char nombrefEmpleados[30]){
	ifstream f;
	tEmpleado empl;
	f.open(nombrefEmpleados,ios::in|ios::binary);
	if(f){
		f.read((char *)&empl, sizeof(empl));
		while(!f.eof()){
			if(empl.horas_trabajadas>=40){
			 		cout << "El Nombre del empleado es: "<< empl.nombre <<endl;
			 		cout << "El sueldo mensual del empleado es: " << empl.horas_trabajadas*empl.precio_hora <<endl;
			}
			f.read((char *)&empl,sizeof(empl));
		}
	}else{
		cout << "Inutil" <<endl;
	}

	f.close();
}