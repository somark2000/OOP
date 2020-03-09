#pragma once
using namespace std;

class Complex
{
private:
	double real, imaginar;
public:
	//constructor
	Complex();

	//return imaginar
	double show_imaginar();

	//return real
	double show_real();

	//add
	Complex operator+ (Complex z);

	//mul
	Complex operator*  (Complex z);

	//quot
	Complex operator/ (Complex z);



	//destructor
	~Complex();
};