#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
using namespace std;

#include"comida.h"

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

//CONSTRUCTOR
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

//SETTERS
void Menu::set_indice_lista(int nuevo_indice_lista){
    indice_lista=nuevo_indice_lista;
}

void Menu::set_elemento_lista(int nuevo_indice, Comida nuevo_elemento){
    lista[nuevo_indice]=nuevo_elemento;
}

//GETTERS
int Menu::get_indice_lista(){
    return indice_lista;
}

Comida Menu::get_elemento_lista(int nuevo_indice){
    return lista[nuevo_indice];
}

//METODO
//ESTE MÉTODO DESPLIEGA TODAS LAS COMIDAS
void Menu::mostrar_lista(){
    cout<<"Menu del dia de hoy"<<endl;
    cout<<endl;
    for (int i=0;i<10;i++){
        if (lista[i].get_precio()==0){
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
