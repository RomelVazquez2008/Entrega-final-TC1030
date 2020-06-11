#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
using namespace std;

#include"comida.h"

/*
* Proyecto: Simulaciòn rappy
* Romel Aldair Vázquez Molina
* A01700519
* 11/06/2020
* versión : Final
*/

//Clase Menu
//Esta clase se encarga de almacenar los distintos objetos de comida
class Menu{
    private:
    //ATRIBUTOS
    Comida lista[10];
    int indice_lista;
    public:
    //CONSTRUCTOR
    Menu(Comida nuevo_lista[10]);
    //SETTERS
    void set_indice_lista(int nuevo_indice_lista);
    void set_elemento_lista(int nuevo_indice, Comida nuevo_elemento);
    //GETTERS
    int get_indice_lista();
    Comida get_elemento_lista(int nuevo_indice);
    //METODO
    void mostrar_lista(); //DESPLIEGA TODAS LAS COMIDAS DEL MENU
};

/**
 * Constructor con atributos predefinidos de la clase Menu.
 *
 * Crea un objeto de menu y por medio de un ciclo, introduce todas los objetos de comida
 * en el arreglo de esta clase.
 *
 * @param  Comida nuevo_lista [10]
 * @return
 */
Menu::Menu(Comida nuevo_lista[10]){
    for(int i=0; i<10; i++){
        if(nuevo_lista[i].get_precio()==0){
            break;
        }
        else {
            lista[i]=nuevo_lista[i];
            indice_lista=i;
        }
    }
}

/**
 * set_indice_lista declara un nuevo indice al atributo de esta clase
 *
 * Se declara un nuevo numero para la longitud del arreglo de lista de esta clase
 *
 * @param int nuevo_indice_lista
 * @return
 */
void Menu::set_indice_lista(int nuevo_indice_lista){
    indice_lista=nuevo_indice_lista;
}

/**
 * set_elemento_lista declara un objeto de comida en el arreglo de la clase
 *
 * Se declara un nuevo objeto de tipo comida en el arreglo de esta clase
 *
 * @param Comida nuevo_comid e int nuevo_indice
 * @return
 */
void Menu::set_elemento_lista(int nuevo_indice, Comida nuevo_elemento){
    lista[nuevo_indice]=nuevo_elemento;
}

/**
 * get_indice_lista retorna el indice de la lista
 *
 * Devuelve el valor del atributo de indice_lista
 *
 * @param
 * @return int indice_lista
 */
int Menu::get_indice_lista(){
    return indice_lista;
}

/**
 * get_elemento_lista retorna un objeto de la lista
 *
 * Devuelve un objeto de tipo Comida que está contenido en la lista de esta clase
 *
 * @param int nuevo_indice
 * @return Comida lista[nuevo_indice]
 */
Comida Menu::get_elemento_lista(int nuevo_indice){
    return lista[nuevo_indice];
}

/**
 * consultar_menu imprime los atributos del arreglo de comida
 *
 * En este método se hace una una impresión al usuario de los atributos
 * que contiene cada uno de los objetos en el arreglo de objetos tipo Comida
 *
 * @param
 * @return
 */
void Menu::mostrar_lista(){
    cout<<"Menu del dia de hoy"<<endl;
    cout<<endl;
    for (int i=0;i<10;i++){ //iteración en el ciclo de las comidas del menú
        if (lista[i].get_precio()==0){ //este break es para verificar existencia de objetos en el arreglo
            break;
        }
        else{
            cout<<"Comida: " <<i+1<<endl;
            cout<<"Incluye:"<<endl;
            lista[i].consultar_menu();
            cout<<endl;
        }
    }
}

#endif // MENU_H_INCLUDED
