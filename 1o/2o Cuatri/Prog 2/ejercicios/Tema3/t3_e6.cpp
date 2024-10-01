#include <iostream>

using namespace std;
void convertirBinario(int n);
int binario(int n);
void convertirBinarioFinal(int n);
int binarioFinal(int n);

int main(){
    int n;
	cout << "Introduce el numero a pasar a binario" << endl;
    cin >> n;
    convertirBinarioFinal(n);
    convertirBinario(n);
}
void convertirBinarioFinal(int n){
    if(n<=1){
        cout << n << endl;
    }else{
        cout << binarioFinal(n) << endl;
    }
}
void convertirBinario(int n){
    if(n==0){
       cout << 0 << endl;
    }else{
       cout << binario(n) << endl;
    }
}

int binarioFinal(int n){
    if(n==0){
        return n;
    }else{
        return n%2+(10*binarioFinal(n/2));
    }
}
int binario(int n){
    if(n!=0){
        return n%2+(10*binario(n/2));
    }else{
        return n;
    }
}