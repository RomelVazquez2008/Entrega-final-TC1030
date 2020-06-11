#ifndef CHEF_H_INCLUDED
#define CHEF_H_INCLUDED

#include<iostream>

using namespace std;
#include "orden.h"
#include "mesero.h"
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

void delay_chef(unsigned int mseconds) //función para retardar el programa
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//CLASE QUE HEREDA DE LA CLASE EMPLEADO
//La cual crea la comida que viene en las ordenes
class Chef: public Empleado{
    private:
        //ATRIBUTOS
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

/**
 * Constructor defalut de la clase Chef que permite crear un objeto vacío.
 *
 * Crea un objeto vacío en parametros, para después ser llenado con setters.
 *
 * @param
 * @return
 */
Chef::Chef():Empleado(){
    indice_comid=0;
    contador=0;
}

/**
 * Constructor con atributos predefinidos de la clase Chef.
 *
 * Crea un objeto con los parámetros que manda el usuario (nombre),
 *
 * @param  string nuevo nombre del chef
 * @return
 */
Chef::Chef(string nuevo_nombre):Empleado(nuevo_nombre){
    indice_comid=0;
    contador=0;
}
/**
 * Destructor de la clase chef
 *
 * Permite destruir el objeto existente, para ahorrar recursos de memoria
 *
 * @param
 * @return
 */
Chef::~Chef(){
}

/**
 * descripcion hace una descripción del rol de esta clase
 *
 * Este mètodo de sobreescritura polimorfico imprime el atributo de nombre
 * y posteriormente hace una presentación formal hacia el usuario
 *
 * @param
 * @return
 */
void Chef::descripcion(){
    cout<<"Me llamo: "<<Empleado::get_nombre()<<endl;
     cout<<"Y hoy le prepararo sus alimentos"<<endl;
}

/**
 * atender_orden imprime mensajes sobre los menús que se preparan
 *
 * otro método de sobreescritura polimorfico el cual por medio de una
 * iteración de ciclos y del indice de la orden, el usuario puede ver que
 * la simulación de los platillos que prepara el chef
 *
 * @param int indice
 * @return
 */
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

/**
 * copiar_comida recibe una comida externa, para pasarla al array de comidas de esta clase
 *
 * Este método axuliar permite a la clase chef, añadir a la lista de comida de esta
 * clase, poder añadir menús externo (por medio de un método que manda a llamar la
 * clase mesero)
 *
 * @param Comida nuevo_comid
 * @return
 */
void Chef::copiar_comida(Comida nuevo_comid){
    comid[indice_comid]=nuevo_comid;
    indice_comid++;
}

/**
 * get_indice_comid retorna el valor de indice de esta clase
 *
 * Devuelve el valor actual del indice del arreglo de comida, de esta clase
 *
 * @param
 * @return int indice_comid
 */
int Chef::get_indice_comid(){
    return indice_comid;
}

/**
 * get_comid retorna un objeto tipo comida
 *
 * Devuelve el valor de uno de los objetos contenidos en el arreglo de comida
 *
 * @param int nuevo_indice
 * @return Comida comid
 */
Comida Chef::get_comid(int nuevo_indice){
    return comid[nuevo_indice];
}

/**
 * set_indice_comid declara el indice del arreglo de comida
 *
 * Se declara la longitud del arreglo que contiene a los objetos tipo comida
 *
 * @param int nuevo_indice
 * @return
 */
void Chef::set_indice_comid(int nuevo_indice){
    indice_comid=nuevo_indice;
}

/**
 * set_comid declara un objeto de comida en el arreglo de la clase
 *
 * Se declara un nuevo objeto de tipo comida en el arreglo de esta clase
 *
 * @param Comida nuevo_comid e int nuevo_indice
 * @return
 */
void Chef::set_comid(Comida nuevo_comid, int nuevo_indice){
    comid[nuevo_indice]=nuevo_comid;
}


#endif // CHEF_H_INCLUDED
