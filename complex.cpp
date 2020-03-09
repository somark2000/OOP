#include <iostream>
#include "complex.h"
#include <cmath>
using namespace std;

Complex::Complex(double a, double b)
{
	real = a;
	imaginar = b;
}

double Complex::show_imaginar() const
{
	return imaginar;
}

double Complex::show_real() const
{
	return real;
}

double Complex::abs() const
{
	return sqrt(imaginar * imaginar + real * real);
}

void Complex::compute_polar() const
{
	return;
}

Complex::operator+(Complex z)
{
	Complex rez;
	rez.real = this->real + z.real;
	rez.imaginar = this->imaginar + z.imaginar;
	return rez;
}

Complex::operator*(Complex z)
{
	Complex rez;
	rez.real = this->real * z.real + this->imaginar * z.imaginar;
	rez.imaginar = this->real * z.imaginar + this->imaginar * z.real;
	return rez;
}

Complex::operator/(Complex z)
{
	Complex rez;
	rez.real = (this->real * z.real - this->imaginar * z.imaginar)/(z.imaginar*z.imaginar+z.real*z.real);
	rez.imaginar = (this->imaginar * z.real- this->real * z.imaginar)/ (z.imaginar * z.imaginar + z.real * z.real);
	return rez;
}