#include <iostream>

using namespace std;

int mostrarMenu();
int sumaDigitos(int n);
int normalizacion(int n);
int indiceNormalizacion(int n);
void normalicacionConIndice(int n, int &ind, int &norm);

int main() {
	int n,suma=0,m,norm=0,contador=1,ind,nor;
	
	cout << "Introduce un numero para hacer pruebas." << endl;
	cin>>n;

	m=mostrarMenu();
	while(m!=0){
		switch(m){
			case 1:
				suma=sumaDigitos(n);
				cout << "La suma total de los digitos de " << n << " es :" << suma << endl;
				break;
			case 2:
				suma=sumaDigitos(n);
				cout << "La suma total de los digitos de " << n << " es :" << suma << endl;
				norm=normalizacion(n);
				cout << "La normalizacion de " << n << " es :" << norm << endl;
				break;
			case 3:
				contador=indiceNormalizacion(n);
				cout << "El indice de normalizacion de " << n << " es :" << contador << endl;
				break;
			case 4:
				normalicacionConIndice(n,ind,nor);
				cout << "El indice de normalizacion de " << n << " es :" << ind <<" y su normalizacion es: "<< nor << endl;
				break;
			default:
				break;
		}
		m=mostrarMenu();
	}
}
int mostrarMenu(){
	int m;
	cout << "Los apartados del ejercicio son los siguientes:" << endl;
	cout << "0: Salir" << endl;
	cout << "1: Suma digitos" << endl;
	cout << "2: Normalizacion" << endl;
	cout << "3: Indice de normalizacion" << endl;
	cout << "4: Normalizacion e indice de normalizacion a la vez" <<endl;
	cin >> m;
	return m;
}
/*Apartado A*/
int sumaDigitos(int n){
	/*Caso trivial: Si el numero que se introduce es menor que 10,
	la suma es el propio numero*/
	if(n<10){
		return n;
	}
	/*Caso general: cuando el numero es mayor que diez*/
	else{
		n=(n%10 + sumaDigitos(n/10));
		return n;
	}
}
/*Apartado B*/
int normalizacion(int norm){
	/*Caso trivial: Cuando la normalizacion ya tiene un numero menor de 10*/
	if(norm<10){
		return norm;
	}
	/*Caso general: cuando el numero es mayor que diez*/
	/*Se va aplicando la funcion sumaDigitos*/
	else{
		norm=normalizacion(sumaDigitos(norm));
		return norm;
	}
}
/*Apartado C*/
int indiceNormalizacion(int n){
	/*Caso trivial: Cuando el numero del que se quiere calcular
	 *el indice de normalizacion ya es menor que 10
	 */
	if(n<10){
		return 1;
	}
	/*Caso general: Cuando el numero del que se quiere calcular
	 *el indice de normalizacion todavia no es menor que 10
	 */
	else{
		return (1 + indiceNormalizacion(sumaDigitos(n)));
	}
}
/*Apartado D*/
void normalicacionConIndice(int n, int &ind, int &norm){
	if(n<10){
		ind=1;
		norm=n;
	}else{
		normalicacionConIndice(sumaDigitos(n),ind,norm);
		ind=1+ind;
	}
}