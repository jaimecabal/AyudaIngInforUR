#include <iostream>

using namespace std;

void mostrarInt(int v[100],int n);
void mostrarIntReves(int v[100],int n);

int main(int argc, char *argv[]) {
	int v[100];
	int n,i;
	cout << "Introduce el numero de elementos del vector" << endl;
	cin >> n;
	for(i=0;i++;i<n){
		cout << "Introduce el valor "<< i <<" del vector" << endl;
		cin >> v[i];
	}
}
void mostrar(int v[100],int n){
	if(n>0){
		mostrar(v,n-1);
		cout << v[n-1];
	}
}
void mostrarIntReves(int v[100],int n){
	if(n>0){
		cout << v[n-1];
		mostrarIntReves(v,n-1);
	}
}