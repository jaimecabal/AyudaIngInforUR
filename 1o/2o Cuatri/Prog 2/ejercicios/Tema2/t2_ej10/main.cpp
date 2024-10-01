#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

void empleadosJornadaCompleta(char nombref[30]);
void consultaEmpleado(char dniEmpl[10]);
void insertarEmpl();
void insertarPosicion(tEmpleado empl,int posicion);
/*void crearFichero(char nombref[30]);*/ /*No esta en el enunciado pero facilita trabajo*/
struct tEmpleado{
        char dni[10]; /*9 caracteres para el DNI y uno de mas*/
        char nombre[20];
        int horasTrabajadas;
        int precioHora;
};

int main(){
    char nombref[30];
    char dniEmpl[10];
    int n;

    cout << "Introduce el ejercicio que quieres enseñar" <<endl;
    cout << "0: Creamos el fichero con los datos de los empleados"<<endl;
    cout << "1: Empleados que trabajen mas de 40 horas semanales" <<endl;
    cout << "2: Seleccion del empleado con DNI" <<endl;
    cout << "3: Insertar nuevos empleados" <<endl;
    cout << "4: Insertar empleados en una posicion concreta" <<endl;
    cin >> n;

    if(n==1){
        cout << "Introduce el nombre del fichero que contiene los empleados" << endl;
        cin >> nombref;

        empleadosJornadaCompleta(nombref);
    }else if(n==2){
        cout << "Introduce el empleado del que se quiere consultar" << endl;
        cin >> dniEmpl;

        consultaEmpleado(dniEmpl);
    }else if(n==3){
        insertarEmpl();
    }else if (n==4) {
        tEmpleado empl;
        int posicion;
        
        cout << "Introduce la posicion en la que se quiere insertar el empleado" << endl;
        cin >> posicion;

        empl=nuevoEmpl();

        insertarPosicion(empl,posicion);
    }/*else if(n==0){
        crearFichero(nombref);
    }*/else{
        cout << "Inutil"<<endl;
    }
    return 0;
}

void empleadosJornadaCompleta(char nombref[30]){
    ifstream f;
    tEmpleado empl;

    f.open(nombref,ios::in);

    if(f){
        f>>empl.dni;
        while(!f.eof()){
            f>>empl.nombre>>empl.horasTrabajadas>>empl.precioHora;
            if(empl.horasTrabajadas>=40){
                cout << "Nombre: "<<empl.nombre <<endl;
                cout << "Sueldo: "<<empl.precioHora*empl.horasTrabajadas <<endl;
            }
            
            f>>empl.dni;
        }
    }else{
        cout << "Inutil"<<endl;
    }

    f.close();
}

void consultaEmpleado(char dniEmpl[9]){
    ifstream f;
    tEmpleado empl;
    bool encontrado;
    encontrado=false;
    f.open("empleados.dat",ios::in);
    if(f){
        f>>empl.dni;
        while(!f.eof() && encontrado==false){
            if(!strcmp(empl.dni,dniEmpl)){
                encontrado=true;
                f>>empl.nombre;
                break; /*Se deberia poder hacer sin break*/
            }
            f>>empl.nombre;
            f>>empl.horasTrabajadas;
            f>>empl.precioHora;
            f>>empl.dni;
        }
        if(encontrado==true){
            cout << "DNI: " << empl.dni << endl;
            cout << "Nombre: " << empl.nombre << endl;
        }else{
            cout << "Este empleado no existe" <<endl;
        }
    }else{
        cout << "Inutil" <<endl;
    }
    f.close();
}
void insertarEmpl(){
    tEmpleado empl;
    ofstream f;

    f.open("empleados.dat",ios::out|ios::app);
    
    empl=nuevoEmpl();

    if(f){
        f << empl.dni << " " << empl.nombre << " " << empl.horasTrabajadas << " " << empl.precioHora << endl;
    }else{
        cout << "Sa matao" <<endl;
    }

    f.close();
}
void insertarPosicion(tEmpleado empl,int posicion){
    ofstream f;
    ifstream o;
    int i=1;
    f.open("empleados.dat",ios::out|ios::app);
    o.open("auxiliar.dat",ios::in);
    if(f && o){
        o >> empl.dni;
        while(!o.eof() && i<posicion){
            o>>empl.nombre>>empl.horasTrabajadas>>empl.precioHora;
            f<<empl.dni<<" "<<empl.nombre << " " <<empl.horasTrabajadas << " " <<empl.precioHora;
            i++;
            o >> empl.dni;
        }
        f<<empl.dni<<" "<<empl.nombre << " " <<empl.horasTrabajadas << " " <<empl.precioHora;
        /*Revisar while*/
        while(!o.eof()){
            o>>empl.nombre>>empl.horasTrabajadas>>empl.precioHora;
            f<<empl.dni<<" "<<empl.nombre << " " <<empl.horasTrabajadas << " " <<empl.precioHora;
            o>>empl.dni;
        }
    }else{
        cout << "Inutil" <<endl;
    }
    o.close();
    f.close();
    /*Falta renombrar el auxiliar y eliminar el fichero antiguo*/
}
tEmpleado nuevoEmpl(){
    tEmpleado empl;

    cout << "Inserte el DNI del nuevo empleado" << endl;
    cin>>empl.dni;
    cout << "Inserte el nombre del nuevo empleado" << endl;
    cin>>empl.nombre;
    cout << "Inserte las horas semanales que trabaja el empleado" << endl;
    cin>>empl.horasTrabajadas;
    cout << "Inserte el sueldo por horas del nuevo empleado" << endl;
    cin>>empl.precioHora;
    
    return empl;
}
void eliminarEmpleado(char nombref[],char dni[]){
    ifstream f;
    ofstream o;
    tEmpleado empl;
    bool encontrado=false;

    f.open(nombref,ios::in);
    o.open("auxiliar.dat",ios::out);

    if(f && o){
        while(!f.eof && encontrado==false){
            o<<empl.dni<<" "<<empl.nombre << " " <<empl.horasTrabajadas << " " <<empl.precioHora;
            f>>empl.dni;
        }
        f>>empl.nombre>>empl.horasTrabajadas>>empl.precioHora;
        while(!f.eof()){
            o<<empl.dni<<" "<<empl.nombre << " " <<empl.horasTrabajadas << " " <<empl.precioHora;
            f>>empl.dni;
        }
    }
}
void buscarEmpleadoOrdenadamente(char nombref[],char dni[]){
    ifstream f;
    tEmpleado empl;

    bool encontrado=false;
    f.open(nombref,ios::in);
    if(f){
        f >> empl.dni;
        while(!f.eof() && strcmp(empl.dni,dni)<0){
            f>>empl.nombre>>empl.horasTrabajadas>>empl.precioHora;
            f>>empl.dni;
        }
        if(!strcmp(empl.dni,dni)){
            f>>empl.nombre>>empl.horasTrabajadas>>empl.precioHora;
            escribirEmpleado(empl);/*Otra funcion que no tienes hecha genio*/
        }
    }
}
/*void crearFichero(char nombref[30]){
    ofstream f;
    int n,i;
    tEmpleado empl;
    f.open(nombref,ios::out);
    cout << "¿Cuantos empleados vas a insertar en el fichero?"<<endl;
    cin >> n;
    for(i=0;i++;i<n){

    }
}*/