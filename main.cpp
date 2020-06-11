#include<iostream>
#include<time.h>
using namespace std;
#include "orden.h"
#include "comida.h"
#include "empleado.h"
#include "mesero.h"
#include "chef.h"
#include "menu.h"
#include "cliente.h"

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

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

/*
* Proyecto: Simulaciòn rappy
* Romel Aldair Vázquez Molina
* A01700519
* 11/06/2020
* versión : Final
*/

//En esta entrega final ya está implementado la el menu interactivo para que el usuario selecione alimentos

//Objetivo: este programa tiene como propósito simular una aplicación tipo rappy, para las fondas.
//Donde un cliente pide platillos, y este espera que los encargados del lugar, le traigan los alimentos.

//NOTA: para responder a las preguntas solo usar numeros enteros, no negativos.
int main(){
//Creación de las clases base y variables de instancia
Comida platillo1("Sopa de estrellas", "Enchilada","Agua de Jamaica", "Helado", 70.89);
Comida platillo2("Sopa azteca", "Carne asada","Agua de horchata","Pastel imposible", 150.65);
Comida platillo3("Espaguetti", "Milanesa", "Agua de limon", "Conejo Turin", 90.50);
Comida listado[10]={platillo1,platillo2,platillo3};
Menu dia(listado);
Empleado *mesero_luis=new Mesero("Luis Edgar");
Empleado *chef_pancho=new Chef("Francisco Rojas");
Cliente lista_clientes[10];
int indice_lista_clientes=0;
int indice_numero_de_orden=0;
int indice_cliente=0;
string nombre="";

//creacion de todo el menu main
cout<<"Bienvenido a Deleite"<<endl;
while (indice_cliente!=3){
    cout<<"Por favor introduzca una opcion"<<endl;
    cout<<"1. ver el menu"<<endl;
    cout<<"2. ordenar comida"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>indice_cliente;
    if (indice_cliente==1){ //opción que despliega todo el menú de la fonda
        dia.mostrar_lista();
    }
    else if (indice_cliente==2){ //opción que hace que el cliente pida alimentos
        dynamic_cast<Mesero*>(mesero_luis)->descripcion();
        delay(500);
        cout<<"Por favor introduzca su nombre: "<<endl;
        getline (cin, nombre);
        getline (cin, nombre); //este segundo get line, es para anular el enter
        lista_clientes[indice_lista_clientes].set_nombre(nombre);
        lista_clientes[indice_lista_clientes].ordenar_comida(dynamic_cast<Mesero*>(mesero_luis),dia); //en este método se pide la comida
        mesero_luis->atender_orden(indice_numero_de_orden); //con este método traspasa la orden al chef
        dynamic_cast<Mesero*>(mesero_luis)->copiar_datos_chef(dynamic_cast<Chef*>(chef_pancho)); //este metodo transcribe la orden al chef
        chef_pancho->atender_orden(indice_numero_de_orden); //el chef crea los alimentos
        mesero_luis->atender_orden(indice_numero_de_orden); //el mesero pasa la comida del chef al cliente
        lista_clientes[indice_lista_clientes].pagar(dynamic_cast<Mesero*>(mesero_luis)); //paga por el servicio
        indice_lista_clientes++;
        indice_numero_de_orden++;
    }
}
cout<<"Gracias por venir a Deleite, vuelva pronto"<<endl;
delete mesero_luis,chef_pancho; //se borran las variables de tipo apuntador

}
