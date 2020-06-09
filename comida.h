#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

#include <iostream>
using namespace std;

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

//CONSTRUCTOR DEFAULT
Comida::Comida(){
    sopa="";
    plato_fuerte="";
    bebida="";
    postre="";
    precio=0;
}

//CONSTRUCTOR CON ATRIBUTOS
Comida::Comida(string nuevo_sopa, string nuevo_plato_fuerte, string nuevo_bebida, string nuevo_postre, float nuevo_precio){
    sopa=nuevo_sopa;
    plato_fuerte=nuevo_plato_fuerte;
    bebida=nuevo_bebida;
    postre=nuevo_postre;
    precio=nuevo_precio;
}

//DESTRUCTOR
Comida::~Comida(){
}

//MÉTODO
//METODO QUE IMPRIME LO QUE CONTIENE ESA COMIDA
void Comida::consultar_menu(){
    cout<<sopa<<endl;
    cout<<plato_fuerte<<endl;
    cout<<bebida<<endl;
    cout<<postre<<endl;
    cout<<"Tiene un precio de: $"<<precio<<endl;
}


//GETTERS
string Comida::get_sopa(){
    return sopa;
}

float Comida::get_precio(){
    return precio;
}

string Comida::get_bebida(){
    return bebida;
}

string Comida::get_plato_fuerte(){
    return plato_fuerte;
}

string Comida::get_postre(){
    return postre;
}



#endif // COMIDA_H_INCLUDED
