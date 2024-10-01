#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct tJugador{
	char nombre[30];
	int edad;
	char nombreEquipo[30];
	int dineroOfrecido;
};
void crearFichero(char nombref[30]);
tJugador crearJugador();
void mostrarFichero(char nombref[30]);
void borra_duplicados(char nombref[30],char nombreJ[30]);

int main() {
	char nombref[30];
	char nombreJ[30];

	cout << "Introduce el nombre del fichero" << endl;
	cin >> nombref;
	crearFichero(nombref);
	mostrarFichero(nombref);
	cout << "Introduce el nombre del fichero" << endl;
	cin >> nombref;
	cout << "Introduce el nombre del jugador" << endl;
	cin >> nombreJ;
	borra_duplicados(nombref,nombreJ);
	mostrarFichero(nombref);
}
void crearFichero(char nombref[30]){
	int n,i;
	ofstream f;
	tJugador p;

	cout << "Introduce el numero de jugadores a insertar al fichero"<< endl;
	cin >> n;
	
	f.open(nombref,ios::out|ios::binary);
	for (i=0;i<n;i++){
		p=crearJugador();
		f.write((char *)&p,sizeof(p));
	}
	f.close();
}
tJugador crearJugador(){
	tJugador j;

	cout<<"Introduce el nombre del jugador"<<endl;
	cin >> j.nombre;
	cout<<"Introduce la edad del jugador"<<endl;
	cin >> j.edad;
	cout<<"Introduce el nombre del equipo"<<endl;
	cin >> j.nombreEquipo;
	cout<<"Introduce el dinero ofrecido por el"<<endl;
	cin >> j.dineroOfrecido;

	return j;
}
void mostrarFichero(char nombref[30]){
	ifstream f;
	tJugador p;

	f.open(nombref,ios::in|ios::binary);
	f.read((char *)&p,sizeof(p));
	while(!f.eof()){
		
		cout << "Nombre del jugador :" 	<< p.nombre << endl;
		cout << "Edad del jugador :" 	<< p.edad << endl;
		cout << "Nombre del equipo :" 	<< p.nombreEquipo << endl;
		cout << "Dinero ofrecido :" 	<< p.dineroOfrecido << endl;

		f.read((char *)&p,sizeof(p));
	}
	f.close();
}
void borra_duplicados(char nombref[30],char nombreJ[30]){
	ifstream f;
	ofstream f1;
	tJugador j;
	bool encontrado=false;
	int comparaPrecio;

	f.open(nombref,ios::in|ios::binary);
	f1.open("FICHAJES.DAT",ios::out|ios::binary);
	if(f&&f1){
		f.read((char *)&j,sizeof(j));
		while(!f.eof()){
			if(strcmp(nombreJ,j.nombre)==0 && encontrado==false){
				f1.write((char *)&j,sizeof(j));
				f.read((char *)&j,sizeof(j));
				encontrado=true;
			}else if (strcmp(nombreJ,j.nombre)==0 && encontrado==true){
				f.read((char *)&j,sizeof(j));
			}else{
				f1.write((char *)&j,sizeof(j));
				f.read((char *)&j,sizeof(j));
			}
		}
	}else{
		cout << "Sa matao" << endl;
	}
	f1.close();
	f.close();
	remove(nombref);
	rename("FICHAJES.DAT",nombref);
}