#include <iostream>

using namespace std;

int max(int n1, int n2);
int maxVector(int v[100], int n);

int main(int argc, char *argv[]) {
	int n,i;
	int v[100];
	cout << "Introduce el numero de elementos del vector" << endl;
	cin >> n;
	for(i=0;i++;i<n){
		/*Acabar introduccion del vector*/
	}
}
int max(int n1,int n2){
	if(n1>n2){
		return n1;
	}else{
		return n2;
	}
}
int maxVector(int v[100], int n){
	/*
	 *Pre: n es el tamaño de v, 0<n<=100
	 *Post:dev el maximo del tamaño v
	 */
	if(n==1){
		return v[0];
	}else{
		return (max(v[n-1],maxVector(v,n-1)));
	}
}