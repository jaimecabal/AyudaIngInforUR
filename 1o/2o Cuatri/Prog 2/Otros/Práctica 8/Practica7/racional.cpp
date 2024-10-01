#include "racional.h"
struct racional{
    int numerador;
    int denominador;
};

void crear(int a,int b,racional & r);
int numerador(racional r);
int denominador(racional r);
void irreducible(racional r, racional &rr);
int mcd(int a,int b);

int main(int argc, char** argv) {

    return 0;
}

void crear(int a,int b, racional & r){

    a=r.numerador;
    b=r.denominador;
}
int numerador(racional r){
    return(r.numerador);
}
int denominador(racional r){
    return(r.denominador);
}
void irreducible(racional r,racional & rr){
    int m=mcd(r.numerador,r.denominador);
    crear(r.numerador/m,r.denominador/m,rr);
}
int mcd(int a, int b){
    if(b==0){return a;
}else{
        return(mcd(b,(a%b)));
}
}
