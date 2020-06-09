#ifndef ORDEN_H_INCLUDED
#define ORDEN_H_INCLUDED

#include <iostream>
using namespace std;

#include"comida.h"

class Orden{
  private:
    //ATRIBUTOS
    float total;
    bool estado;
    int numero_orden;
    Comida comid[100];
    int indice_comid;
  public:
    //CONSTRUCTORES
    Orden();
    Orden(int nuevo_numero_orden);
    //DESTRUCTOR
    ~Orden();
    //METODOS
    void completar_orden(); //METODO AUXILIAR QUE DEFINE EL ESTADO DE UNA ORDEN
    void calcular_total(); //METODO PARA CALCULAR EL TOTAL DEL PEDIDO
    void agregar_comida(Comida nuevo_comid[100]); //METODO AUXILIAR PARA AÑADIR LOS ALIMENTOS
    //GETTERS
    float get_total();
    bool get_estado();
    Comida get_comida(int i);
};
//CONSTRUCTOR CON ATRIBUTOS
Orden::Orden(int nuevo_numero_orden){
    total=0;
    estado=0;
    numero_orden=nuevo_numero_orden;
    comid[100];
    indice_comid=0;
}

//CONSTRUCTOR DEFAULT
Orden::Orden(){
    total=0;
    estado=0;
    numero_orden=0;
    comid[100];
    indice_comid=0;
}

//DESTRUCTOR
Orden::~Orden(){
}

//MÉTODOS
//METODO QUE DEFINE SI UNA ORDEN YA ESTÁ LISTA, ESTO LO UTILIZA MAS LA CLASE CHEF
void Orden::completar_orden(){
    estado=1;
}

//METODO QUE OBTIENE EL TOTAL DE LA ORDEN
void Orden::calcular_total(){
    int indice;
    for(indice=0;indice<indice_comid;indice++){
        total=total+comid[indice].get_precio();
    }
}

//METODO QUE AGREGA ALIMENTOS A LA ORDEN
void Orden::agregar_comida(Comida nuevo_comid[100]){
    for(indice_comid;indice_comid<100;indice_comid++){
        if (nuevo_comid[indice_comid].get_precio()==0){
            break;
        }
        else{
        comid[indice_comid]=nuevo_comid[indice_comid];
        }
    }
}

//GETTERS
float Orden::get_total(){
    return total;
}

bool Orden::get_estado(){
    return estado;
}

Comida Orden::get_comida(int i){
    return comid[i];
}

#endif // ORDEN_H_INCLUDED
