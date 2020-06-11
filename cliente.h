#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <iostream>
using namespace std;
#include "mesero.h"
#include "menu.h"
#include<time.h>

/*
* Proyecto: Simulaciòn rappy
* Romel Aldair Vázquez Molina
* A01700519
* 11/06/2020
* versión : Final
*/

/**
 * delay función para retardar el programa
 *
 * Permite al programa ser retrasado una cierta cantidad de segundos
 * para que la ejecución del programa sea más fluida, y no salgan
 * los mensajes de instantaneamente.
 *
 * @param int msceonds
 * @return
 */
void delay_cliente(unsigned int mseconds) //función para retardar el programa
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//CLASE CLIENTE
//Esta clase permite ordenar diferentes objetos del menu y pagar el total
class Cliente{
  private:
    //ATRIBUTO
    string nombre;
  public:
    //CONSTRUCTORES
    Cliente();
    Cliente(string nuevo_nombre);
    //DESTRUCTORES
    ~Cliente();
    //METODOS
    void ordenar_comida(Mesero *nuevo_mesero, Menu nuevo_menu); //CON ESTE METODO PIDE ALIMENTOS
    void pagar(Mesero *nuevo_mesero); //EN ESTE METODO PAGA LOS ALIMENTOS
    //SETTER
    void set_nombre(string nuevo_nombre);
};

/**
 * Constructor defalut de la clase Cliente que permite crear un objeto vacío.
 *
 * Crea un objeto vacío en parametros, para después ser llenado con setters.
 *
 * @param
 * @return
 */
Cliente::Cliente(){
    nombre="";
}

/**
 * Constructor con atributos predefinidos de la clase Cliente.
 *
 * Crea un objeto con los parámetros que manda el usuario (nombre),
 *
 * @param  string nuevo nombre del cliente
 * @return
 */
Cliente::Cliente(string nuevo_nombre){
    nombre=nuevo_nombre;
}


/**
 * Destructor de la clase Cliente
 *
 * Permite destruir el objeto existente, para ahorrar recursos de memoria
 *
 * @param
 * @return
 */
Cliente::~Cliente(){
}

/**
 * set_nombre declara un nuevo string al atributo de nombre
 *
 * Se declara un nuevo nombre al atributo de nombre de la clase Cliente
 *
 * @param string nuevo_nombre
 * @return
 */
void Cliente::set_nombre(string nuevo_nombre){
    nombre=nuevo_nombre;
}

/**
 * ordenar_comida se le pide al usuario los platillos a ordenar, para agregarlos en una orden
 *
 * En este método se le hace un pedido del menú al usuario, al cual por medio del parametro de nuevo_mesero
 * este lo guarda en su lista de ordenes, añadiendo el pedido del cliente e incrementando su arreglo
 * de objetos tipo ordenes.
 *
 * @param Mesero (apuntador) nuevo_mesero y Menu nuevo_menu
 * @return
 */
void Cliente::ordenar_comida(Mesero *nuevo_mesero,Menu nuevo_menu){
    int opcion;
    Comida pedido[100];
    int j=0;
    int total=0;
    for (int i=0;i<=nuevo_menu.get_indice_lista();i++){ //En este ciclo se hace la iteracción de las comidas a ordenar
        cout<<"Cuantas comidas "<<i+1<<" Desea ordenar?"<<endl;
        cin>>opcion;
        total=total+opcion;
        for (j;j<total;j++){
            pedido[j]=nuevo_menu.get_elemento_lista(i);
        }
    }
    //Una vez teniendo el pedido, el objeto mesero se encarga de añadirlo a sus arreglo de objetos de ordenes.
    int indice=dynamic_cast<Mesero*>(nuevo_mesero)->get_indice_orden();
    dynamic_cast<Mesero*>(nuevo_mesero)->set_orden(indice);
    dynamic_cast<Mesero*>(nuevo_mesero)->agregar_comida_en_orden(indice,pedido);
}

/**
 * pagar se obtiene el total de la orden y el cliente se le pide insertar la cantidad a pagar
 *
 * Haciendo un llamado a la clase del mesero que atendió al cliente previamente, se le pide al objeto mesero
 * usar uno de sus métodos para calcular el total de la orden, posteriormente se le pide un input al usuario
 * para que se digite el dinero a pagar y de esta manera confirmar el pago con su respectivo cambio.
 *
 * @param Mesero (apuntador) nuevo_mesero
 * @return
 */
void Cliente::pagar(Mesero *nuevo_mesero){
    float pago;
    int indice=dynamic_cast<Mesero*>(nuevo_mesero)->get_indice_orden()-1;
    dynamic_cast<Mesero*>(nuevo_mesero)->get_orden(indice).calcular_total();
    float total=dynamic_cast<Mesero*>(nuevo_mesero)->get_orden(indice).get_total(); //aquí se le pide al objeto mesero, el total de la orden
    cout<<Cliente::nombre<<" paga: $"<<total<<endl;
    cout<<"Ingrese la cantidad a pagar: $";
    cin>>pago;
    //En esta parte se hace un ciclo para verificar si el cliente pagó la orden
    while(pago<total){
        delay_cliente(500);
        cout<<"Error, pago por debajo del total"<<endl;
        cout<<"Ingrese la cantidad a pagar: $";
        cin>>pago;
    }
    delay_cliente(1000);
    cout<<"pago exitoso, su cambio: $"<<pago-total<<endl;
}


#endif // CLIENTE_H_INCLUDED

