#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <iostream>
using namespace std;
#include "mesero.h"
#include "menu.h"
#include<time.h>

void delay_cliente(unsigned int mseconds) //función para retardar el programa
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//CLASE TODAVÌA NO IMPLEMENTADA
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

//CONSTRUCTOR DEFAULT
Cliente::Cliente(){
    nombre="";
}

//CONSTRUCTOR CON PARÀMETROS
Cliente::Cliente(string nuevo_nombre){
    nombre=nuevo_nombre;
}

//DESTRUCTOR
Cliente::~Cliente(){
}

//SETTER
void Cliente::set_nombre(string nuevo_nombre){
    nombre=nuevo_nombre;
}

//MÈTODOS
//ESTE MÉTODO PIDE AL USUARIO DECIR CUANTOS PLATILLOS VA A QUERER, PARA DESPUÉS SER AGREGADOS EN LA ORDEN DEL MESERO
void Cliente::ordenar_comida(Mesero *nuevo_mesero,Menu nuevo_menu){
    int opcion;
    Comida pedido[100];
    int j=0;
    int total=0;
    for (int i=0;i<=nuevo_menu.get_indice_lista();i++){
        cout<<"Cuantas comidas "<<i+1<<" Desea ordenar?"<<endl;
        cin>>opcion;
        total=total+opcion;
        for (j;j<total;j++){
            pedido[j]=nuevo_menu.get_elemento_lista(i);
        }
    }
    int indice=dynamic_cast<Mesero*>(nuevo_mesero)->get_indice_orden();
    dynamic_cast<Mesero*>(nuevo_mesero)->set_orden(indice);
    dynamic_cast<Mesero*>(nuevo_mesero)->agregar_comida_en_orden(indice,pedido);
}

//ESTE MÉTODO ES PARA QUE CUANDO EL CLIENTE RECIBE SUS ALIMENTOS, SE LE IMPRIME MENSAJES DEL TOTAL Y CUANTO DEBE DE PAGAR
void Cliente::pagar(Mesero *nuevo_mesero){
    float pago;
    int indice=dynamic_cast<Mesero*>(nuevo_mesero)->get_indice_orden()-1;
    dynamic_cast<Mesero*>(nuevo_mesero)->get_orden(indice).calcular_total();
    float total=dynamic_cast<Mesero*>(nuevo_mesero)->get_orden(indice).get_total();
    cout<<Cliente::nombre<<" paga: $"<<total<<endl;
    cout<<"Ingrese la cantidad a pagar: $";
    cin>>pago;
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

