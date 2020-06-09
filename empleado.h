#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include <iostream>
using namespace std;

//CLASE PADRE Y ABSTRACTA, QUE HEREDAN CHEF Y MESERO
class Empleado{
  protected:
    //ATRIBUTOS
    string nombre;
  public:
    //CONSTRUCTORES
    Empleado();
    Empleado(string nuevo_nombre);
    //DESTRUCTOR
    ~Empleado();
    //METODOS
    virtual void atender_orden(int indice)=0;   //Definición de clase abstracta
    virtual void descripcion()=0; //Definición de clase abstracta
    //GETTER
    string get_nombre();
};
//CONSTRUCTOR DEFAULT
Empleado::Empleado(){
  nombre="";
}
//CONSTRUCTOR CON ATRIBUTOS
Empleado::Empleado(string nuevo_nombre){
  nombre=nuevo_nombre;
}

//DESTRUCTOR
Empleado::~Empleado(){
}

//GETTERS
string Empleado::get_nombre(){
    return nombre;
}

#endif
