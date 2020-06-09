#ifndef MESERO_H_INCLUDED
#define MESERO_H_INCLUDED

#include<iostream>
using namespace std;
#include "orden.h"
#include "comida.h"
#include "chef.h"
//ESTA CLASE HEREDA DE LA CLASE EMPLEADO
class Mesero: public Empleado{
    private:
        //ATRIBUTOS
        Orden orde[20];
        int indice_orden;
        Chef copia_chef; //METIMOS ESTE OBJETO AQUÍ PARA QUE GUARDE LAS ORDENES DEL MESERO, Y LUEGO PASEN AL CHEF ORIGINAL
    public:
        //CONSTRUCTORES
        Mesero ();
        Mesero (string nuevo_nombre);
        //DESTRUCTOR
        ~Mesero();
        //SETTER
        void set_orden(int nuevo_numero_orden);
        //GETTERS
        int get_numero();
        Chef get_copia_chef();
        Orden get_orden(int indice);
        int get_indice_orden();
        //METODOS
        void descripcion(); //METODO POLIMORFICO, QUE HACE QUE EL MESERO SE PRESENTE
        void agregar_comida_en_orden(int indice, Comida nuevo_comida[100]); //CON ESTE METODO ANOTA LA COMIDA QUE PIDE EL CLIENTE
        void copiar_datos_chef(Chef* nuevo_chef); //ESTE MÉTODO ES PARA QUE EL OBJETO CHEF QUE TIENE ESTA CLASE, LO PASE A OTRO CHEF DEL MAIN
        void atender_orden(int indice); //METODO POLIMORFICO QUE TRASPASA LAS ORDENES ENTRE CHEF Y CLIENTE
        void incrementar_indice_orden(); //METODO PARA AÑADIR AL CONTADOR DE INCREMENTAR ORDEN

};
//CONSTRUCTOR DEFAULT
Mesero::Mesero():Empleado(){
    indice_orden=0;
}
//CONSTRUCTOR CON ATRIBUTOS
Mesero::Mesero(string nuevo_nombre):Empleado(nuevo_nombre){
    indice_orden=0;
}

//DESTRUCTOR
Mesero::~Mesero(){
}

//SETTER
void Mesero::set_orden(int nuevo_numero_orden){
    Orden nuevo_orden(nuevo_numero_orden);
    orde[indice_orden]=nuevo_orden;
    Mesero::incrementar_indice_orden();
}

//GETTERS
Chef Mesero::get_copia_chef(){
    return copia_chef;
}

int Mesero::get_numero(){
    return copia_chef.get_indice_comid();
}

int Mesero::get_indice_orden(){
    return indice_orden;
}

Orden Mesero::get_orden(int indice){
    return orde[indice];
}

//MÉTODOS
//METODO DE SOBREESCRITURA, QUE IMPRIME HACE QUE EL MESERO SE PRESENTE
void Mesero::descripcion(){
    cout<<"Me llamo: "<<Empleado::get_nombre()<<endl;
    cout<<"Y hoy le estare a sus ordenes"<<endl;
}

//METODO QUE AYUDA AL ATRIBUTO ORDEN, A AGREGAR COMIDA EN LA ORDEN
void Mesero::agregar_comida_en_orden(int indice, Comida nuevo_comida[100]){
    orde[indice].agregar_comida(nuevo_comida);
    orde[indice].calcular_total();
}

//METODO QUE INVOLUCRA POLIMORFISMO, PARA QUE EL MESERO SEPA DISTRIBUIR LOS PEDIDOS ENTRE CLIENTE Y CHEF
void Mesero::atender_orden(int indice){
    if (orde[indice].get_estado()==0){
        for (int j=0;j<100;j++){
            if(orde[indice].get_comida(j).get_precio()==0){
                break;
            }
            else{
                copia_chef.copiar_comida(orde[indice].get_comida(j));
            }
        }
        cout<<Mesero::nombre<<": Entregada orden a chef"<<endl;
        orde[indice].completar_orden();
    }
    else{
        cout<<Mesero::nombre<<": Entregando orden a cliente"<<endl;
    }
}

//METODO DONDE EL CHEF DE ESTA CLASE, PUEDE COPIARSE A UN CHEF EXTERNO
void Mesero::copiar_datos_chef(Chef* nuevo_chef){
    for (int j=0;j<100;j++){
            if(copia_chef.get_comid(j).get_precio()==0){
                break;
            }
            else{
                nuevo_chef->set_comid(copia_chef.get_comid(j),j);
            }
    }
    nuevo_chef->set_indice_comid(copia_chef.get_indice_comid());
}

//ESTE METODO AGREGA NUMEROS AL ARREGLO DE ORDENES
void Mesero::incrementar_indice_orden(){
    indice_orden++;
}

#endif // MESERO_H_INCLUDED
