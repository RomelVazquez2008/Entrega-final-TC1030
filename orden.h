#ifndef ORDEN_H_INCLUDED
#define ORDEN_H_INCLUDED

#include <iostream>
using namespace std;
/*
* Proyecto: Simulaciòn rappy
* Romel Aldair Vázquez Molina
* A01700519
* 11/06/2020
* versión : Final
*/
#include"comida.h"
//Clase Orden
//Esta clase contiene objetos comida, de los clientes
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
/**
 * Constructor con atributos predefinidos de la clase Orden.
 *
 * Crea un objeto con los parámetros que manda el usuario (nuevo_numero_orden),
 *
 * @param  int nuevo_numero_orden
 * @return
 */
Orden::Orden(int nuevo_numero_orden){
    total=0;
    estado=0;
    numero_orden=nuevo_numero_orden;
    comid[100];
    indice_comid=0;
}

/**
 * Constructor default de la clase Orden que permite crear un objeto vacío.
 *
 * Crea un objeto vacío en parametros, para después ser llenado con setters.
 *
 * @param
 * @return
 */
Orden::Orden(){
    total=0;
    estado=0;
    numero_orden=0;
    comid[100];
    indice_comid=0;
}

/**
 * Destructor de la clase Orden
 *
 * Permite destruir el objeto existente, para ahorrar recursos de memoria
 *
 * @param
 * @return
 */
Orden::~Orden(){
}

/**
 * completar_orden define el estado de la orden como completado
 *
 * Este mètodo se hace un cambio al atributo de orden, para definer que la
 * orden está lista para ser entregada
 *
 * @param
 * @return
 */
void Orden::completar_orden(){
    estado=1;
}

/**
 * calcular_total define el total del costo de esta orden
 *
 * Este mètodo se encarga de hacer los calculos de los precios de cada comida
 * para definir su atributo de total
 *
 * @param
 * @return
 */
void Orden::calcular_total(){
    int indice;
    for(indice=0;indice<indice_comid;indice++){
        total=total+comid[indice].get_precio();
    }
}

/**
 * agregar_comida añade los objetos de comida en el arreglo de esta clase
 *
 * Este método se usa, para que por medio de los parámetros, se copie el arreglo
 * al atributo de esta clase
 *
 * @param Comida nuevo_comid[100]
 * @return
 */
void Orden::agregar_comida(Comida nuevo_comid[100]){
    for(indice_comid;indice_comid<100;indice_comid++){
        if (nuevo_comid[indice_comid].get_precio()==0){ //se hace una validación de que haya comida en el arreglo
            break;
        }
        else{
        comid[indice_comid]=nuevo_comid[indice_comid]; //se añaden los objetos al atributo de esta clase
        }
    }
}

/**
 * get_total retorna el valor del total de esta clase
 *
 * Devuelve el valor actual del atributo de total de la clase Orden
 *
 * @param
 * @return float total
 */
float Orden::get_total(){
    return total;
}

/**
 * get_estado retorna el valor del estado de esta clase
 *
 * Devuelve el valor actual del atributo de estado de la clase Orden
 *
 * @param
 * @return bool estado
 */
bool Orden::get_estado(){
    return estado;
}

/**
 * get_Comida retorna uno de los objetos de comida en el arreglo de esta clase
 *
 * Devuelve un objeto del arreglo de comid, de acuerdo al parámetro recibido
 *
 * @param int i
 * @return Comida comid[i]
 */
Comida Orden::get_comida(int i){
    return comid[i];
}

#endif // ORDEN_H_INCLUDED
