#include <iostream>

using namespace std;

int fibonacciR(int n);
int fibonacci(int n);

int main(int argc, char *argv[]) {
	int n,r;
	cout << "introduce un numero para calcular la sucesion de fibonacci" << endl;
	cin >> n;
	cout << "1: Recursiva" << endl <<"2: Iterativa"<<endl;
	cin >> r;
	if(r==1){
		cout << "La sucesion de Fibonacci es: " <<fibonacciR(n)<<endl;;
	}else if(r==2){
		cout << "La sucesion de Fibonacci es: " <<fibonacci(n)<<endl;
	}else{
		cout<<"Inutil"<<endl;
	}
}
int fibonacciR(int n){
	/*Complejidad o((1+sqrt(5)/2)^2)
	* Nummero Aureo ^2
	*/
	if(n<2){
		return n;
	}else{
		return(fibonacciR(n-1)+fibonacciR(n-2));
	}
}
int fibonacci(int n){
	/*Complejidad o(n)*/
	int fn1,fn2,fn,i;
	if(n<2){
		return n;
	}else{
		fn2=0;
		fn1=1;
		for(i=0;i++;i<n){
			fn=fn1+fn2;
			fn2=fn1;
			fn1=fn;
		}
		return fn;
	}
}