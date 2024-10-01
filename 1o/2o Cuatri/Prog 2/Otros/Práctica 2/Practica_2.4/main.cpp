#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void copiarResto(ifstream & F,ofstream & FS);

int main() {
  
    char nombreA[20];
    char nombreB[20];
    char nombreS[20];//S make reference at the output file.
    int n,m;
      ifstream canalEA ;
    ifstream canalEB ;
    ofstream canalS ;
    cout<<"introduce el nombre del archivo A:"<<endl;
    cin>>nombreA;
    cout<<"introduce el nombre del archivo B:"<<endl;
    cin>>nombreB;
    cout<<"introduce el nombre del archivo de salida:"<<endl;
    cin>>nombreS;
    
    canalEA.open(nombreA,ios::in);
    canalEB.open(nombreB,ios::in);
    canalS.open(nombreS,ios::out);

    if(canalEA && canalEB && canalS){
        canalEA>>n;
        canalEB>>m;
        while(!canalEA.eof() && !canalEB.eof()){
            if(n>m){
            canalS<<n<<endl;
            canalEA>>n;}
            else{
            canalS<<m<<endl;
            canalEB>>m;
            }
           
        }
        if(!canalEA.eof()){
            copiarResto(canalEB,canalS);
            
        }
        if(!canalEB.eof()){
            copiarResto(canalEA,canalS);
        }
         canalEA.close();
    canalEB.close();
    canalS.close();
        
    }
   
     else
    {
        cout<<"Problemas a la hora de abrir alguno de los ficheros"<<endl;
    }
    system("Pause");
    return 0;

    
    return 0;
}

void copiarResto(ifstream & F, ofstream & FS){
    int n;
    F>>n;
    while(!F.eof()){
        FS<<n<<endl;
        F>>n;
    }
}