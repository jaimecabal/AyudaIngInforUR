#include <iostream>
#include <fstream>
using namespace std;
void crearf (char nombref[]);
void abrirf (char nombref[]);
void juntarf(char nombref[],char nombref2[]);
int main()
{
 char nombref[30],nombref2[30];
 cout<<"introduce el nombre de tu fichero 1"<<endl;
 cin>>nombref;
 crearf(nombref);
  cout<<"introduce el nombre de tu fichero 2"<<endl;
 cin>>nombref2;
 crearf(nombref2);
 cout<<"pipo";
 abrirf(nombref);
 cout<<"pipo";
 juntarf(nombref,nombref2);
 cout<<"salio bien wey";
 abrirf(nombref);
 cout<<"texto de comprobacion";
    return 0;
}
void crearf (char nombref[])
{

ofstream f;
  int n;
  f.open(nombref,ios::out);
  if(f)
  {
      cout<<"introduce una serie de numeros y que el ultimo sea 0";
      cin>>n;
      while(n>0)
      {
          f<<n<<endl;
          cin>>n;
      }
      f.close();
  }else{
  cout<<"problemas wey";
  }
}
void abrirf (char nombref[]){
    ifstream f;
    int n;
    f.open(nombref,ios::in);
    if(f){
        f>>n;
         while(!f.eof()){
          cout<<n<<endl;
          f>>n;
        }
        f.close();
    }else{
        cout<<"problemas";
    }
}
void juntarf(char nombref[],char nombref2[]){
    ofstream f;
    ifstream g;
    int n;
    f.open(nombref,ios::app);
    g.open(nombref2,ios::in);
        if(g&&f){
            while(!g.eof()){
            g>>n;
            f<<n<<endl;
            }
            f.close();
            g.close();
        }else{
            cout<<"problemas";
        }
}