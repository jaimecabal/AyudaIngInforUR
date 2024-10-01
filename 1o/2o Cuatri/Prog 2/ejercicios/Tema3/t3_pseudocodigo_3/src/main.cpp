#include <iostream>

using namespace std;
int numPares(int v[],int n);
int numParesInm(int v[],int n,int max,int maxActual);

int main() {
	int v[9]={2,2,4,7,6,8,4,2,2};
	int n=9;
	cout<<"El numero de pares seguidos es: "<<numPares(v,n)<<endl;
}
int numPares(int v[],int n){
	return numParesInm(v,n,0,0);
}
int numParesInm(int v[],int n,int max,int maxActual){
	if(n==1){
		if(v[0]%2==0){
			maxActual++;
			if(max<maxActual){
				max=maxActual;
			}
			return max;
		}else{
			maxActual=0;
			return max;
		}
	}else{
		if(v[n-1]%2==0){
			maxActual++;
			if(max>=maxActual){
				return numParesInm(v,n-1,max,maxActual);
			}else{
				max=maxActual;
				return numParesInm(v,n-1,max,maxActual);
			}
		}else{
			maxActual=0;
			return numParesInm(v,n-1,max,maxActual);
		}
	}
}