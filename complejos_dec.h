//Programa para declarar la clase complejos

//Bibliotecas incluidas
//Bibliotecas para flujo de entrada/salida de datos
#include <iostream>

using namespace std;
#pragma once




class complejos
{
    //Declaración de los atributos privados
    //Se declaran los atributos para la parte real e imaginaria de los 
    //complejos
    private:
    double re;
    double im;
    


    public:
    //Declaración de los Constructores.Son 3
    
    //Constructor por Defecto
    complejos();

    //Constructor por Pase de Argumentos
    complejos(double, double);

    //Constructor por Copia 
    complejos(const complejos &);

   
   //Declaración del Destructor
    ~complejos();


    //------------------------------------

    //Declaración de los Métodos
    
    //Retorno de la componente Real
    double get_re() const;
    
    
    //Retorno de la componente Imaginaria
    double get_im() const;

    //Calculo del Modulo
    double modulo() const;

    //Calculo del Modulo al Cuadrado
    double m2() const;

    
    //-----------------------------------
    
    
    //Sobrecarga de Operadores

    //Operador Suma
    friend complejos const operator+(complejos const &, complejos const &);

    //Operador Multiplicación
    friend complejos const operator*(complejos const &, complejos const &);

    //Operador Igual
    complejos const &operator=(complejos const&);

    //Operador Igual para String
    complejos const &operator=(string const &);

    //Operador OStream
    friend std::ostream &operator<<(std::ostream &,const complejos &);
    

    //Operador IStream
    friend std::istream &operator>>(std::istream &,complejos &);

};

