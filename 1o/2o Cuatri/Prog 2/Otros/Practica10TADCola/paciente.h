
#ifndef PACIENTE_H
#define PACIENTE_H

struct Paciente{
    char nombre[30];
    char dni[10];
    int edad;
};

void creaPaciente(Paciente & p, char nombre[], char dni[], int edad);
int edadPaciente(Paciente p); //nos hará falta para buscar el paciente más joven en el main
void nombrePaciente(Paciente p, char nombre[]); //no lo usamos pero está bien definirlo por si hace falta en otro ejerc.
void dniPaciente(Paciente p, char dni[]); //no lo usamos pero está bien definirlo por si hace falta en otro ejerc.
//Estos tres podrían ir a un fichero UsaPaciente.cpp
void mostrarPaciente(Paciente p);
void leerPaciente(Paciente &p);
void copiarPaciente(Paciente p1,Paciente &p2);

#endif /* PACIENTE_H */

