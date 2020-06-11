#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

#include <iostream>
using namespace std;

/*
* Proyecto: Simulaciòn rappy
* Romel Aldair Vázquez Molina
* A01700519
* 11/06/2020
* versión : Final
*/

//Clase comida
//Sirve para alojar los distintos platillos de la fonda
class Comida{
  private:
    //ATRIBUTOS
    string sopa;
    string plato_fuerte;
    string bebida;
    string postre;
    float precio;
  public:
    //CONSTRUCTORES
    Comida();
    Comida(string nuevo_sopa, string nuevo_plato_fuerte, string nuevo_bebida, string nuevo_postre, float nuevo_precio);
    //DESTRUCTOR
    ~Comida();
    //METODOS
    void consultar_menu(); //DESPLIEGA LO QUE CONTIENE LA COMIDA
    //GETTERS
    string get_sopa();
    string get_plato_fuerte();
    string get_bebida();
    string get_postre();
    float get_precio();
};

/**
 * Constructor defalut de la clase Comida que permite crear un objeto vacío.
 *
 * Crea un objeto vacío en parametros, para después ser llenado con setters.
 *
 * @param
 * @return
 */
Comida::Comida(){
    sopa="";
    plato_fuerte="";
    bebida="";
    postre="";
    precio=0;
}

/**
 * Constructor con atributos predefinidos de la clase Comida.
 *
 * Crea un objeto con los parámetros que manda el usuario (sopa, plato_fuerte, bebida, postre, precio),
 *
 * @param  string nuevo_sopa, string nuevo_plato_fuerte, string nuevo_bebida, string nuevo_postre y float nuevo_precio
 * @return
 */
Comida::Comida(string nuevo_sopa, string nuevo_plato_fuerte, string nuevo_bebida, string nuevo_postre, float nuevo_precio){
    sopa=nuevo_sopa;
    plato_fuerte=nuevo_plato_fuerte;
    bebida=nuevo_bebida;
    postre=nuevo_postre;
    precio=nuevo_precio;
}

/**
 * Destructor de la clase Comida
 *
 * Permite destruir el objeto existente, para ahorrar recursos de memoria
 *
 * @param
 * @return
 */
Comida::~Comida(){
}

/**
 * consultar_menu imprime los atributos de esta clase
 *
 * En este método se hace una una impresión al usuario de los atributos
 * que contiene la clase Comida.
 *
 * @param
 * @return
 */
void Comida::consultar_menu(){
    cout<<sopa<<endl;
    cout<<plato_fuerte<<endl;
    cout<<bebida<<endl;
    cout<<postre<<endl;
    cout<<"Tiene un precio de: $"<<precio<<endl;
}


/**
 * get_sopa retorna el valor del atributo sopa
 *
 * Devuelve el valor actual del string en el atributo de sopa
 *
 * @param
 * @return string sopa
 */
string Comida::get_sopa(){
    return sopa;
}

/**
 * get_precio retorna el valor del atributo precio
 *
 * Devuelve el valor actual del número en el atributo de precio
 *
 * @param
 * @return float precio
 */
float Comida::get_precio(){
    return precio;
}

/**
 * get_bebida retorna el valor del atributo bebida
 *
 * Devuelve el valor actual del string en el atributo de bebida
 *
 * @param
 * @return string bebida
 */
string Comida::get_bebida(){
    return bebida;
}

/**
 * get_plato_fuerte retorna el valor del atributo plato_fuerte
 *
 * Devuelve el valor actual del string en el atributo de plato_fuerte
 *
 * @param
 * @return string plato_fuerte
 */
string Comida::get_plato_fuerte(){
    return plato_fuerte;
}

/**
 * get_postre retorna el valor del atributo postre
 *
 * Devuelve el valor actual del string en el atributo de postre
 *
 * @param
 * @return string postre
 */
string Comida::get_postre(){
    return postre;
}



#endif // COMIDA_H_INCLUDED
