#include <iostream>

using namespace std;
int numMasFrecuente(int v[5],int n,int k);
int main() {
	int v[5]={1,2,3,2,5};
	int n=5,k=4;
	cout<<"El numero mas frecuente es: "<<numMasFrecuente(v,n,k)<<endl;
}
int numMasFrecuente(int v[5],int n,int k){
	if(n==0){
		return 0;
	}else{
		if(v[n-1]==k){
			return numMasFrecuente(v,n-1,k)+1;
		}else{
			return numMasFrecuente(v,n-1,k);
		}
	}
};