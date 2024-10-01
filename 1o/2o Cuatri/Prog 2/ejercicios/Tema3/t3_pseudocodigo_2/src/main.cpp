#include <iostream>

using namespace std;
int numMasFrecuente(int v[],int n,int k);
int moda(int v[],int n);
int main() {
	int v[8]={4,4,4,5,4,6,8,3};
	int n=8;
	cout<<"La moda es: "<<moda(v,n)<<endl;
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
}
int moda(int v[],int n){
	if(n==1){
		return v[n];
	}else{
		if(numMasFrecuente(v,n,v[n-1])>numMasFrecuente(v,n-1,moda(v,n-1))){
			return v[n-1];
		}else{
			moda(v,n-1);
		}
	}
}