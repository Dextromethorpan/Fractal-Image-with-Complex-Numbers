//Programa para definir la clase complejos

//Bibliotecas incluidas
#include<cmath>
#include <iostream>
#include "complejos_dec.h"

using namespace std;


//Definición de los Constructores y del Destructor

//Definición del Constructor por Defecto. Todos los componentes se inicializan

//por defecto en 0
complejos::complejos(): re(0),im(0){};

//Definición del Constructor por Pase de Argumentos
complejos::complejos(double r, double i):re(r),im(i){};

//Definición del Constructor por Copia
complejos::complejos(const complejos &c):re(c.re),im(c.im){};

//Definición del Destructor
complejos::~complejos(){}


//----------------------------------
//Definición de los Métodos

//Retorno de la parte real
double complejos::get_re() const
{
    return re;
};

//Retorno de la parte imaginaria
double complejos::get_im() const
{
    return im;
};


//Calculo del Módulo
double complejos::modulo() const
{
    return sqrt(re*re + im*im);
};


//Calculo del Módulo al Cuadrado
double complejos::m2() const 
{
    return re*re + im*im;
};

//----------------------------------

//Definición de Sobrecarga de Operadores
//Suma
complejos const operator+(complejos const &x, complejos const &y)
{
    complejos z(x.get_re()+y.get_re(),x.get_im()+y.get_im());
    return z;
};

//Multiplicación
complejos const operator*(complejos const &x,complejos const &y)
{
    complejos z(x.get_re()*y.get_re()-x.get_im()*y.get_im(),x.get_re()*y.get_im()+x.get_im()*y.get_re());
    return z;
};

//Igual
complejos const & complejos::operator=(complejos const &c)
{
    re=c.get_re();
    im=c.get_im();
    return *this;
};


//Igual para String
complejos const & complejos::operator=(string const &s) {
	int s_length = s.length();
	int pos = s.find(",");

	re= stod(s.substr(1, pos));
	im= stod(s.substr(pos + 2, s_length - 1));

	return *this;
};



//IStream
istream & operator>>(istream &is, complejos &c) {

	double re_ = 0;
	double im_ = 0;
	int okay = 0;
	char ch = 0;

	if (is >> ch
		&& ch == '(') {
		if (is >> re_
			&& is >> ch
			&& ch == ','
			&& is >> im_
			&& is >> ch
			&& ch == ')')
			okay = 1;
	}
	else {
		is.putback(ch);
		if (is >> re_)
			okay = 1;
	}

	if (okay)
		c.re = re_, c.im = im_;
	else
		is.clear(ios::badbit);

	return is;
};





//OStream
ostream & operator<<(ostream &os, const complejos &c) 
{
	return os << "("
		<< c.get_re()
		<< ", "
		<< c.get_im()
		<< ")";
};