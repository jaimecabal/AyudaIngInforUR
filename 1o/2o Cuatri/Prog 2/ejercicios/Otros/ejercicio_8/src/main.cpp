#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
	char nombreF1[30];
	char nombreF2[30];
	char nombreF3[30];
	int n1,n2;

	ifstream f1,f2;
	ofstream f3;
	
	strcpy(nombreF1,"UNO.DAT");
	strcpy(nombreF2,"DOS.DAT");
	
	cout << "Introduce el nombre del 3er fichero" << endl;
	cin >> nombreF3;

	f1.open(nombreF1,ios::in);
	f2.open(nombreF2,ios::in);
	f3.open(nombreF3,ios::out);

	if(f1 && f2 && f3){
		f1>>n1;
		f2>>n2;
		while(!f1.eof() && !f2.eof()){
			f3<<n1<<endl<<n2<<endl;
			f1>>n1;
			f2>>n2;
		}
		while(!f1.eof()){
			f3<<n1<<endl;
			f1>>n1;
		}
		while(!f2.eof()){
			f3<<n2<<endl;
			f2>>n2;
		}

	}else{
		cout << "Sa matao";
	}

	f1.close();
	f2.close();
	f3.close();
}