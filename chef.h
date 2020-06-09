#ifndef CHEF_H_INCLUDED
#define CHEF_H_INCLUDED

#include<iostream>

using namespace std;
#include "orden.h"
#include "mesero.h"
#include<time.h>

void delay_chef(unsigned int mseconds) //función para retardar el programa
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//CLASE QUE HEREDA DE LA CLASE EMPLEADO
//La cual crea la comida que viene en las ordenes
class Chef: public Empleado{
    private:
        Comida comid[200];
        int indice_comid;
        int contador;
    public:
        //CONSTRUCTORES
        Chef ();
        Chef (string nuevo_nombre);
        //DESTRUCTOR
        ~Chef();
        //METODO
        void descripcion(); //Este método polimorfico hace que el chef se presente formalmente
        void atender_orden(int indice); //este metodo polimorfico hace que el chef cree comida de las ordenes
        void copiar_comida(Comida nuevo_comid); //este metodo copia la comida que está en las ordenes
        //SETTER
        void set_indice_comid(int nuevo_indice);
        void set_comid(Comida nuevo_comid, int nuevo_indice);
        //GETTER
        int get_indice_comid();
        Comida get_comid(int nuevo_indice);

};
//CONSTRUCTOR DEFAULT
Chef::Chef():Empleado(){
    indice_comid=0;
    contador=0;
}

//CONSTRUCTOR CON ATRIBUTOS
Chef::Chef(string nuevo_nombre):Empleado(nuevo_nombre){
    indice_comid=0;
    contador=0;
}

//DESTRUCTOR
Chef::~Chef(){
}

//MÉTODOS
//METODO DE SOBREESCRITURA POLIMORFICO, QUE HACE QUE EL CHEF SE PRESENTE FORMALMENTE
void Chef::descripcion(){
    cout<<"Me llamo: "<<Empleado::get_nombre()<<endl;
     cout<<"Y hoy le prepararo sus alimentos"<<endl;
}

//ESTE ES EL OTRO MÉTODO POLIMORFICO, EL CUAL A RAIZ DE LA COPIA DE COMIDA, EMPIEZA A CREAR LO QUE ESTÁ EN LA ORDEN
void Chef::atender_orden(int indice){
    Chef::descripcion();
    cout<<Chef::nombre<<": Preparando orden: "<<indice+1<<endl;
    for (int i=contador;i<indice_comid;i++){
        delay_chef(1000);
        cout<<"Cocinado: "<<comid[i].get_sopa()<<endl;
        cout<<"Cocinado: "<<comid[i].get_plato_fuerte()<<endl;
        cout<<"Sirviendo: "<<comid[i].get_bebida()<<endl;
        cout<<"Cocinado: "<<comid[i].get_postre()<<endl;
        contador=contador+1;
    }
    cout<<Chef::nombre<<": Lista orden: "<<indice+1<<endl;
}

//ESTE MÉTODO ES AUXILIAR, PARA QUE EL CHEF PUEDA TENER UNA LISTA DE LO QUE DEBE DE CREAR
void Chef::copiar_comida(Comida nuevo_comid){
    comid[indice_comid]=nuevo_comid;
    indice_comid++;
}

//GETTERS
int Chef::get_indice_comid(){
    return indice_comid;
}

Comida Chef::get_comid(int nuevo_indice){
    return comid[nuevo_indice];
}

//SETTERS
void Chef::set_indice_comid(int nuevo_indice){
    indice_comid=nuevo_indice;
}

void Chef::set_comid(Comida nuevo_comid, int nuevo_indice){
    comid[nuevo_indice]=nuevo_comid;
}


#endif // CHEF_H_INCLUDED
