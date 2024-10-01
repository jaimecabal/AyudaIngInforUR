#include <iostream>

using namespace std;

int potencia(int n, int a);

int main(int argc, char *argv[]) {
	int n, a,potenciaN;
	cout << "Introduce base de la potencia" << endl;
	cin >>a;

	cout << "Introduce al numero al que elevarlo" << endl;
	cin >> n;
	
	potenciaN=potencia(n,a);

	cout << "Introduce la respuesta: " << potenciaN <<endl;
}

int potencia(int n,int a){
	if(n==0){
		return 1;
	}else{
		return(a*potencia(n-1,a));
	}
}