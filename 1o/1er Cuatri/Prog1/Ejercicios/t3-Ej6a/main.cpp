#include <iostream>

using namespace std;

int main()
{
    char l;
    int numPalabrasQu;
    numPalabrasQu=0;
    cin.unsetf(ios::skipws);

    cout<<"Escribe una frase" << endl;
    cin>>l;

    while(l==' ')
    {
        cin>>l;
    }
    while(l!='.'){
        while((l!=' ')&&(l!='.')){
            if(l=='q'){
                cin>>l;
                if(l=='u'){
                    numPalabrasQu++;
                    cin>>l;
                }
            }else{
                cin>>l;
            }
        }
        while(l==' '){
            cin>>l;
        }
    }
    cout<<"El numero de palabras que empiezan por QU es: "<<numPalabrasQu;
    return 0;
}
