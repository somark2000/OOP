#include <iostream>
#include "complex.h"
#include <cmath>
#include <string>
using namespace std;

Complex::Complex()
{
	real = 0;
	imaginar = 0;
}

//Constructor
Complex::Complex(double a, double b)
{
	this->real = a;
	this->imaginar = b;
}

//Destructor
Complex::~Complex()
{

}

//Returnarea partii imaginare
double Complex::show_imaginar() const
{
	return imaginar;
}

//Returnarea partii reale
double Complex::show_real() const
{
	return real;
}

//setter real
void Complex::setReal(double real) {
	this->real = real;
}

//setter imaginar
void Complex::setImag(double imaginar) {
	this->imaginar = imaginar;
}

//Functie care returneaza modulul
double Complex::abs() const
{
	return sqrt(imaginar * imaginar + real * real);
}

//Functie care calculeaza suma
Complex Complex::operator+(Complex z)
{
	Complex rez;
	rez.setReal(this->show_real() + z.show_real());
	rez.setImag(this->show_imaginar() + z.show_imaginar());
	return rez;
}

//Functie care calculeaza produsul
Complex Complex::operator*(Complex z)
{
	Complex rez;
	if (this->show_imaginar() > 0.0 || z.show_real() > 0.0)
	{
		rez.setReal(this->show_real() * z.show_real() - this->show_imaginar() * z.show_imaginar());
		rez.setImag(this->show_real() * z.show_imaginar() + this->show_imaginar() * z.show_real());
	}
	else
	{
		rez.setReal(this->show_real() * z.show_real() + this->show_imaginar() * z.show_imaginar());
		rez.setImag(this->show_real() * z.show_imaginar() - this->show_imaginar() * z.show_real());
	}
	return rez;
}

//Functie care calculeaza impartirea
Complex Complex::operator/(Complex z)
{
	Complex rez;
	if (this->show_real() > 0.0 || z.show_imaginar() > 0.0)
	{
		rez.setReal((this->show_real() * z.show_real() + this->show_imaginar() * z.show_imaginar()) / (z.show_real() * z.show_real() + z.show_imaginar() * z.show_imaginar()));
		rez.setImag((z.show_real() * this->show_imaginar() - this->show_real() * z.show_imaginar()) / (z.show_real() * z.show_real() + z.show_imaginar() * z.show_imaginar()));
	}
	else
	{
		rez.setReal((this->show_real() * z.show_real() + this->show_imaginar() * z.show_imaginar()) / (z.show_real() * z.show_real() + z.show_imaginar() * z.show_imaginar()));
		rez.setImag((z.show_real() * this->show_imaginar() + this->show_real() * z.show_imaginar()) / (z.show_real() * z.show_real() + z.show_imaginar() * z.show_imaginar()));
	}
	return rez;
}

//Functie care calculeaza un unghi
float Complex::unghi()
{
	float unghi;
	unghi = (atan2(this->show_imaginar(), this->show_real()) * 180) / 3, 14;
	return unghi;
}

//Functie care returneaza forma polara
string Complex::compute_polar()
{
	double x, y, z;
	z = atan2(this->show_imaginar(), this->show_real());
	x = cos(z);
	y = sin(z);
	string str = to_string(this->abs() * (x + y)) + "*i";
	return str;
}

//Functie care returneaza forma exponentiala
string Complex::show_exp()
{
	double x;
	x = atan2(this->show_imaginar(), this->show_imaginar());
	string expo = to_string(this->abs()) + "*e^" + to_string(x) + "*i";
	return expo;

}

//Functie care returneaza un numar complex
Complex Complex::show_compl()
{
	Complex c;
	c.setReal(show_real());
	c.setImag(show_imaginar());
	return c;
}