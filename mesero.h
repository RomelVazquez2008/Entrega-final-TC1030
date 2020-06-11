#ifndef MESERO_H_INCLUDED
#define MESERO_H_INCLUDED

#include<iostream>
using namespace std;
#include "orden.h"
#include "comida.h"
#include "chef.h"
/*
* Proyecto: Simulaciòn rappy
* Romel Aldair Vázquez Molina
* A01700519
* 11/06/2020
* versión : Final
*/

//Clase Mesero
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
/**
 * Constructor defalut de la clase Mesero que permite crear un objeto vacío.
 *
 * Crea un objeto vacío en parametros, para después ser llenado con setters.
 *
 * @param
 * @return
 */
Mesero::Mesero():Empleado(){
    indice_orden=0;
}

/**
 * Constructor con atributos predefinidos de la clase Mesero.
 *
 * Crea un objeto con los parámetros que manda el usuario (nombre),
 *
 * @param  string nuevo_nombre del mesero
 * @return
 */
Mesero::Mesero(string nuevo_nombre):Empleado(nuevo_nombre){
    indice_orden=0;
}

/**
 * Destructor de la clase Empleado
 *
 * Permite destruir el objeto existente, para ahorrar recursos de memoria
 *
 * @param
 * @return
 */
Mesero::~Mesero(){
}

/**
 * set_orden declara un objeto de orden en el arreglo de la clase
 *
 * Se declara un nuevo objeto de tipo orden en el arreglo de esta clase, así
 * como incremetar la longitud del arreglo de ordenes.
 *
 * @param int nuevo_numero_orden
 * @return
 */
void Mesero::set_orden(int nuevo_numero_orden){
    Orden nuevo_orden(nuevo_numero_orden);
    orde[indice_orden]=nuevo_orden;
    Mesero::incrementar_indice_orden();
}

/**
 * get_copia_chef retorna el atributo de objeto chef
 *
 * Devuelve un objeto de tipo Chef que está contenido en esta clase
 *
 * @param
 * @return Chef copia_chef
 */
Chef Mesero::get_copia_chef(){
    return copia_chef;
}

/**
 * get_numero retorna el indice de comida en el Chef
 *
 * Devuelve un número de la longitud del arreglo de tipo Comida, que contiene
 * el objeto tipo copia_chef, que está contenido en esta clase
 *
 * @param
 * @return int indice_comid
 */
int Mesero::get_numero(){
    return copia_chef.get_indice_comid();
}

/**
 * get_indice_orden retorna el indice del arreglo ordenes
 *
 * Devuelve un número de la longitud del arreglo de objetos tipo
 * ordenes que están como atributo en esta clase
 *
 * @param
 * @return int indice_orden
 */
int Mesero::get_indice_orden(){
    return indice_orden;
}

/**
 * get_orden retorna un objeto de orden
 *
 * Devuelve un objeto de tipo orden del arreglo, que está como atributo en esta
 * clase
 *
 * @param int indice
 * @return Orden orde[indice]
 */
Orden Mesero::get_orden(int indice){
    return orde[indice];
}

/**
 * descripcion hace una descripción del rol de esta clase tipo Mesero
 *
 * Este mètodo de sobreescritura polimorfico imprime el atributo de nombre
 * y posteriormente hace una presentación formal hacia el usuario de lo que se
 * encarga de hacer esta clase
 *
 * @param
 * @return
 */
void Mesero::descripcion(){
    cout<<"Me llamo: "<<Empleado::get_nombre()<<endl;
    cout<<"Y hoy le estare a sus ordenes"<<endl;
}

/**
 * agregar_comida_en_orden agrega un objeto al arreglo de esta clase
 *
 * En este método, por medio de los parametros que se le pasan, se agregan las
 * distintas comidas al arreglo de orden, el cual es un atributo de esta clase.
 *
 * @param int indice, Comida nuevo_comida
 * @return
 */
void Mesero::agregar_comida_en_orden(int indice, Comida nuevo_comida[100]){
    orde[indice].agregar_comida(nuevo_comida); //se mandan a llamar métodos de la clase Orden
    orde[indice].calcular_total(); //se manda a llamar otro métodos de la clase Orden
}

/**
 * atender_orden distribuye las ordenes entre el Chef y el Cliente
 *
 * En este método polimórfico, se pasa primero la orden al objeto de chef, para que pueda
 * hacer una simulación de la creación de esa comida y una vez que esté terminada, se pasa
 * al cliente su orden preparada.
 *
 * @param int indice
 * @return
 */
void Mesero::atender_orden(int indice){
    if (orde[indice].get_estado()==0){ //primero se pasa la orden al chef
        for (int j=0;j<100;j++){ //en este ciclo se pasa una por una la comida en la orden, al chef
            if(orde[indice].get_comida(j).get_precio()==0){
                break;
            }
            else{
                copia_chef.copiar_comida(orde[indice].get_comida(j));
            }
        }
        cout<<Mesero::nombre<<": Entregada orden a chef"<<endl;
        orde[indice].completar_orden(); //aqui se manda a llamar otro método para confirmar el paso al chef
    }
    else{ //se pasa la comida al cliente
        cout<<Mesero::nombre<<": Entregando orden a cliente"<<endl;
    }
}

/**
 * copiar_datos_chef al atributo de chef de esta clase, se pasa a un chef externo
 *
 * Lo que hace este método es realizar el intercambio de las comidad que tiene el atributo de
 * copia_chef y traspasarlas a un chef del main, para que ese se encargue de prepararlas.
 *
 * @param Chef (apuntador)nuevo_chef
 * @return
 */
void Mesero::copiar_datos_chef(Chef* nuevo_chef){
    for (int j=0;j<100;j++){ //este ciclo for es para iterar en la cantidad de comidas de la orden
            if(copia_chef.get_comid(j).get_precio()==0){
                break;
            }
            else{
                nuevo_chef->set_comid(copia_chef.get_comid(j),j); //se pasa uno por uno los objetos de comida
            }
    }
    nuevo_chef->set_indice_comid(copia_chef.get_indice_comid()); // se define la longitud del arreglo
}

/**
 * incrementar_indice_orden añade en uno al atributo de indice_orden
 *
 * Este método es simple, ya que es mandado a llamar por otros métodos, para incrementar la longitud,
 * del atributo de su arreglo de ordenes
 *
 * @param
 * @return
 */
void Mesero::incrementar_indice_orden(){
    indice_orden++;
}

#endif // MESERO_H_INCLUDED
