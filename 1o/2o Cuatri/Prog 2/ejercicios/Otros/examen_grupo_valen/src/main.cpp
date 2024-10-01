#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct tTrabajador{
	char idTrab[7];
	char idFact[5];
	int horas;
};

tTrabajador nuevoEstudiante();
void leerFichero(char nombref[30]);
void crearFichero(char nombref[30]);
int mostrarMenu();
void apartado1(char nombref[30],char idFact[5]);
void apartado2(char nombref[30],char idTrab[7],int horasExtra);

int main() {
	char idTrab[7];
	char idFact[5];
	char nombref[30];
	int m,horasExtra;

	cout << "Introduce el nombre del fichero" << endl;
	cin >> nombref;
	crearFichero(nombref);
	leerFichero(nombref);
	m=mostrarMenu();
	while(m!=3){
		switch(m){
			case 1:
				cout << "Introduce el id de la fabrica: "<<endl;
				cin >> idFact;
				apartado1(nombref,idFact);
				break;
			case 2:
				cout << "Introduce el idTrab"<< endl;
				cin >> idTrab;
				cout << "Introduce las horas extra" << endl;
				cin >> horasExtra;
				apartado2(nombref,idTrab,horasExtra);
				leerFichero(nombref);
				break;
			default:
				break;
		}
		m=mostrarMenu();
	}
}
void crearFichero(char nombref[30]){
	int n,i;
	ofstream f;
	tTrabajador t;

	cout << "Introduce el numero de trabajadores"<<endl;
	cin >> n;
	
	f.open(nombref,ios::out|ios::binary);

	if(f){
		for(i=0;i<n;i++){
			t=nuevoEstudiante();
			f.write((char *)&t,sizeof(t));
		}
	}
	f.close();
}
tTrabajador nuevoEstudiante(){
	tTrabajador t;
	cout << "Introduce el id de la fabrica donde trabaja" << endl;
	cin >> t.idFact;
	cout << "Introduce el id del trabajador" << endl;
	cin >> t.idTrab;
	cout << "Introduce el numero de horas" << endl;
	cin >> t.horas;
	
	return t;
}
void leerFichero(char nombref[30]){
	ifstream f;
	tTrabajador t;
	f.open(nombref,ios::in|ios::binary);
	f.read((char *)&t,sizeof(t));
	while(!f.eof()){
		cout << "------------------------" <<endl;
		cout << "Id de la fabrica: " << t.idFact<<endl;
		cout << "Id del trabajador: " << t.idTrab<<endl;
		cout << "Horas que trabaja: " << t.horas<<endl;
		cout << "------------------------" <<endl;
		f.read((char *)&t,sizeof(t));
	}

	f.close();
}
int mostrarMenu(){
	int m;
	
	cout << "Introduce un apartado ha hacer" << endl;
	cout << "1: Sumar horas"<<endl;
	cout << "2: Modificar" << endl; 
	cout << "3: Salir" << endl; 
	cin >> m;

	return m;
}
void apartado1(char nombref[30],char idFact[5]){
	ifstream f;
	tTrabajador t;
	int suma=0;
	f.open(nombref,ios::in|ios::binary);

	f.read((char *)&t,sizeof(t));
	while(!f.eof()){
		suma=suma+t.horas;
		f.read((char *)&t,sizeof(t));
	}
	cout << "El numero de horas es: "<<suma<< endl;
	f.close();
}
void apartado2(char nombref[30],char idTrab[7],int horasExtra){
	int horas=0;
	tTrabajador t;
	ifstream f1;
	ofstream f2;
	bool encontrado;

	f1.open(nombref,ios::in|ios::binary);
	f2.open("aux.dat",ios::out|ios::binary);

	if(f1 && f2){
		f1.read((char *)&t,sizeof(t));
		while(!f1.eof() && encontrado==false){
			if(strcmp(t.idTrab,idTrab)==0){
				encontrado=true;
			}else{
				f2.write((char *)&t,sizeof(t));
				f1.read((char *)&t,sizeof(t));
			}
		}
		horas=horasExtra+t.horas;
		t.horas=horas;
		f2.write((char *)&t,sizeof(t));
		f1.read((char *)&t,sizeof(t));
		while(!f1.eof()){
			f2.write((char *)&t,sizeof(t));
			f1.read((char *)&t,sizeof(t));
		}
	}
	remove(nombref);
	rename("aux.dat",nombref);
	f1.close();
	f2.close();
}