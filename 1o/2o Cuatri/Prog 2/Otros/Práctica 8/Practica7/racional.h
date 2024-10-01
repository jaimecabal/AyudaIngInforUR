#include<iostream>
#include<cstdlib>
using namespace std;

struct racional{
    int numerador;
    int denominador;
};

void crear(int a,int b,racional & r);
int numerador(racional r);
int denominador(racional r);
void irreducible(racional r, racional &rr);
