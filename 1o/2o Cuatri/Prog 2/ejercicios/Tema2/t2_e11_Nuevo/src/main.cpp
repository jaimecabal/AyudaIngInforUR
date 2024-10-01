#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
struct tEmpleado{
	char dni[10];
	char nombre[30];
	int horas_trabajadas;
	int precio_hora;
};

void crearFichero(char nombref[30]);
tEmpleado nuevoEmpleado();
void listarEmpleadosMas40Horas(char nombref[30]);
int mostrarMenu();
void listarEmpleado(char nombref[30],char dni[10]);
void insertarNuevoEmpleado(char nombref[30]);
void insertarPos(char nombref[30],int posicion);
void eliminarEmpleado(char nombref[30],char dni[10]);
void buscarEmpleadoOrdenado(char nombref[30],char dni[10]);
void insertarOrdenado(char nombref[30],tEmpleado emplNuevo);

int main() {
	int m;
	char nombref[30];
	char dni[10];
	
	cout << "Introduce el nombre del fichero a usar" <<endl;
	cin >>nombref;
	crearFichero(nombref);
	m=mostrarMenu();
	
	while(m!=0){
		switch (m){
		case 1:
			listarEmpleadosMas40Horas(nombref);
			break;
		case 2:
			cout<< "Introduce el dni a buscar" <<endl;
			cin >> dni;
			listarEmpleado(nombref,dni);
			break;
		case 3:
			insertarNuevoEmpleado(nombref);
			break;
		case 4:
			int posicion;
			cout<<"Introduce la posicion en la que quieres insertar el nuevo empleado"<<endl;
			cin>>posicion;
			insertarPos(nombref,posicion);
			break;
		case 5:
			cout << "Introduce el DNI a buscar: " <<endl;
			cin >> dni;
			eliminarEmpleado(nombref,dni);
			break;
		case 6:
			cout << "Introduce el DNI a buscar: " <<endl;
			cin >> dni;
			buscarEmpleadoOrdenado(nombref,dni);
			break;
		case 7:
			tEmpleado emplNuevo;
			emplNuevo=nuevoEmpleado();
			insertarOrdenado(nombref,emplNuevo);
			break;
		default:
			break;
		}
		m=mostrarMenu();
	}

	cout << "Adios" <<endl;
}
int mostrarMenu(){
	int m;
	cout << "------------------------------------------------" << endl;
	cout << "Introduce el apartado del menu que quieres hacer" << endl;
	cout << "0: Acabar ejercicio" << endl;
	cout << "1: Listar empleados que trabajan más de 40 horas" << endl;
	cout << "2: Lista un empleado usando su DNI" << endl;
	cout << "3: Insertar un empleado nuevo" << endl;
	cout << "4: Insertar un empleado nuevo en una posicion concreta" << endl;
	cout << "5: Eliminar un empleado" << endl;
	cout << "6: Buscar un empleado ordenado" <<endl;
	cout << "7: Insertar un empleado nuevo de manera ordenada" <<endl;
	cout << "------------------------------------------------" << endl;
	cin >> m;
	
	return m;
}
void crearFichero(char nombref[30]){
	ofstream f;
	tEmpleado empl;
	int n,i;
	cout << "Introduce el numero de empleados a insertar" <<endl;
	cin >> n;
	f.open(nombref,ios::out|ios::binary);
	if(f){
		for(i=0;i<n;i++){
			empl=nuevoEmpleado();
			f.write((char *)&empl,sizeof(empl));
		}
	}else{
		cout << "Sa matao" << endl;
	}
	f.close();
}
tEmpleado nuevoEmpleado(){
	tEmpleado empl;
	
	cout<<"Introduce el DNI: "<<endl;
	cin >>empl.dni;
	cout<<"Introduce el nombre: "<<endl;
	cin >>empl.nombre;
	cout<<"Introduce el horas trabajadas: "<<endl;
	cin >>empl.horas_trabajadas;
	cout<<"Introduce el precio que cobra por hora: "<<endl;
	cin >>empl.precio_hora;
	
	return empl;
}
void listarEmpleadosMas40Horas(char nombref[30]){
	ifstream f;
	tEmpleado empl;
	f.open(nombref,ios::in|ios::binary);
	if(f){
		f.read((char *)&empl,sizeof(empl));
		while(!f.eof()){
			if(empl.horas_trabajadas>40){
				cout<<"Nombre: "<<empl.nombre<<endl;
				cout<<"Sueldo Semanal: "<<empl.horas_trabajadas*empl.precio_hora<<endl;
			}
			f.read((char *)&empl,sizeof(empl));
		}
	}else{
		cout <<"Sa matao" <<endl;
	}
	f.close();
}
void listarEmpleado(char nombref[30],char dni[10]){
	ifstream f;
	tEmpleado empl;
	bool encontrado=false;
	f.open(nombref,ios::in|ios::binary);
		if(f){
			f.read((char *)&empl,sizeof(empl));
			while (!f.eof()&&encontrado==false){
				if(!strcmp(empl.dni,dni)){
					cout << "DNI: " << empl.dni << endl;
					cout << "Nombre: " << empl.nombre << endl;
					cout << "Horas Trabajadas: " << empl.horas_trabajadas << endl;
					cout << "Sueldo por hora: " << empl.precio_hora << endl;
					encontrado=true;
				}
				f.read((char *)&empl,sizeof(empl));
			}
			if(encontrado==false){
				cout << "Este empleado no esta guardado en el fichero" <<endl;
			}
		}else{
			cout <<"Sa matao" <<endl;
		}
	f.close();
}
void insertarNuevoEmpleado(char nombref[30]){
	ofstream f;
	tEmpleado empl;
	empl=nuevoEmpleado();
	f.open(nombref,ios::app|ios::binary);
		if(f){
			f.write((char *)&empl,sizeof(empl));
		}else{
			cout << "Sa matao" <<endl;
		}
	f.close();
	cout << "El empleado nuevo es: " <<endl;
	/*No es necesario, pero sirve para ver
	*si se ha insertado correctamente*/
	listarEmpleado(nombref,empl.dni);
	/*Solo chuta debajo del f.close()*/
}
void insertarPos(char nombref[30],int posicion){
	tEmpleado nuevoEmpl,empl;
	ifstream f;
	ofstream o;
	int contador=1;
	nuevoEmpl=nuevoEmpleado();
	f.open(nombref,ios::in|ios::binary);
	o.open("aux.dat",ios::out|ios::binary);
		f.read((char *)&empl,sizeof(empl));
		while (!f.eof()&& contador<posicion){
			/* Insertamos los empleados anteriores al aux */
			o.write((char *)&empl,sizeof(empl));
			f.read((char *)&empl,sizeof(empl));
		}
		/* Insertamos el empleado nuevo al aux */
		o.write((char *)&nuevoEmpl,sizeof(nuevoEmpl));
		f.read((char *)&empl,sizeof(empl));
		
		while (!f.eof()){
			/* Insertamos el resto de empleados al aux */
			o.write((char *)&empl,sizeof(empl));
			f.read((char *)&empl,sizeof(empl));
		}
	o.close();
	f.close();
	remove(nombref);
	rename("aux.dat",nombref);
	listarEmpleado(nombref,nuevoEmpl.dni);
}
void eliminarEmpleado(char nombref[30],char dni[10]){
	ifstream f;
	ofstream o;
	tEmpleado empl;

	f.open(nombref,ios::in|ios::binary);
	o.open("aux.dat",ios::out|ios::binary);

	if(f&&o){
		f.read((char *)&empl,sizeof(empl));
		while(!f.eof() && !strcmp(dni,empl.dni)){
			o.write((char *)&empl,sizeof(empl));
			f.read((char *)&empl,sizeof(empl));
		}
			f.read((char *)&empl,sizeof(empl));
		while(!f.eof()){
			o.write((char *)&empl,sizeof(empl));
			f.read((char *)&empl,sizeof(empl));
		}
	}else{
		cout << "Sa matao"<<endl;
	}
	f.close();
	o.close();
	remove(nombref);
	rename("aux.dat",nombref);
}
void buscarEmpleadoOrdenado(char nombref[30],char dni[10]){
	ifstream f;
	tEmpleado empl;
	bool encontrado=false;

	f.open(nombref,ios::in|ios::binary);
	if(f){
		f.read((char *)&empl,sizeof(empl));
		while(!f.eof() && encontrado==false){
			if(strcmp(dni,empl.dni)==0){
				cout << "DNI: " << empl.dni << endl;
				cout << "Nombre: " << empl.nombre << endl;
				cout << "Horas Trabajadas: " << empl.horas_trabajadas << endl;
				cout << "Sueldo por hora: " << empl.precio_hora << endl;
				encontrado=true;
			}
			f.read((char *)&empl,sizeof(empl));
		}
	}else{
		cout << "Sa matao" <<endl;
	}
	f.close();
}
void insertarOrdenado(char nombref[30],tEmpleado emplNuevo){
	ifstream f;
	ofstream o;
	tEmpleado empl;

	f.open(nombref,ios::in|ios::binary);
	o.open(nombref,ios::out|ios::binary);

	if(f&&o){
		f.read((char *)&empl,sizeof(empl));
		while(!f.eof()&&strcmp(empl.dni,emplNuevo.dni)<0){
			o.write((char *)&empl,sizeof(empl));
			f.read((char *)&empl,sizeof(empl));
		}
		o.write((char *)&emplNuevo,sizeof(emplNuevo));
		while(!f.eof()){
			o.write((char *)&empl,sizeof(empl));
			f.read((char *)&empl,sizeof(empl));
		}
	}else{
		cout << "Sa matao" <<endl;
	}

	o.close();
	f.close();

	remove(nombref);
	rename("aux.dat",nombref);
}
void eliminarOrdenado(){
	
}