#include <iostream>

using namespace std;
//Definimos la lista enlazada de nodos:
struct nodo{
	int dato;
	nodo *sig;
};

void crearLista(nodo* &lista_enlazada);
void add(nodo * &lista_enlazada,int n);
void mostrar(nodo * &lista);
void liberar(nodo * &lista);

//Ejercicio 1: Funcion esta que comprueba sin un entero en una lista enlazada de nodos de enteros
bool esta(nodo *lista_enlazada,int n);

//Ejercicio 2: Funcion que añade al final de una lista de enteros un nuevo entero

int main() {
	int a;
	bool b;
	nodo *lista_enlazada;

	cout << "Apartado que se quiere comprobar" << endl;
	cout << "1: Funcion esta esta comprueba si un entero esta en una lista enlazada de nodos de enteros" << endl;
	cout << "2: Funcion añadir al final que usa la funcion anterior para añadir o no un entero al final de una lista enlazada de nodos de enteros" << endl;
	cin >> a;
	crearLista(lista_enlazada);
	mostrar(lista_enlazada);
	switch(a){
		case 1:
			int n;
			cout << "Indica el numero que se quiere buscar" << endl;
			cin >> n;
			b=esta(lista_enlazada,n);
			if(b==true){
				cout << "El numero " << n << " esta en la lista de enteros." << endl;
			}else{
				cout << "El numero " << n << " no esta en la lista de enteros." << endl;
			}
			cout << b << endl;
			cout << "N vale: " << n << endl;
		case 2:

		default:
			break;
	}
	liberar(lista_enlazada);
}

//Funciones y acciones predeterminadas
void add(nodo * & lista_enlazada,int n){
	nodo *nuevo=new(nodo);

	(*nuevo).dato=n;
	(*nuevo).sig=lista_enlazada;
	lista_enlazada=nuevo;
}
void mostrar(nodo * & lista){
	cout << "El contenido de la lista es: " << endl;
	nodo *p;
	p=lista;
	while(p!=NULL){
		cout << (*p).dato <<endl;
		p=(*p).sig;
	}
}
void liberar(nodo * &lista){
	nodo *p;
	while(lista!=NULL){
		p=lista;
		lista=(*lista).sig;
		delete(p);
	}
}
void crearLista(nodo * &lista_enlazada){
	int n;
	lista_enlazada=NULL;
	cout << "Introduce un valor a añadir a la lista" << endl;
	cin >> n;
	while(n!=0){
		add(lista_enlazada,n);
		cout << "Introduce un valor a añadir a la lista" << endl;
		cin >> n;
	}
}

//Funciones y acciones de los distintos ejercicios
bool esta(nodo *lista_enlazada,int n){
	bool esta=false;
	nodo *aux;
	aux=lista_enlazada;

	while(aux!=NULL && esta==false){
		if((*aux).dato==n){
			esta=true;
		}else{
			aux=(*aux).sig;
		}
	}
	return esta;
}
void addEnd(nodo * &lista_enlazada,int n){
	nodo *aux;
	nodo *nuevo=new(nodo);
	//Estos son los datos del nuevo elemento, ya que va a estar al final de la lista enlazada el siguiente numero al que tiene que apuntar es NULL
	(*nuevo).dato=n;
	(*nuevo).sig=NULL;
	//Caso base: es una lista que ya esta vacia
	if(lista_enlazada==NULL){
		lista_enlazada=nuevo;
	}else{
		//Hacemos una copia de la lista de enteros
		aux=lista_enlazada;
		//Mientras que la lista
		while((*aux).sig!=NULL){
			aux=(*aux).sig;
		}
		(*aux).sig=nuevo;
	}
}