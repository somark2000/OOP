#pragma once
using namespace std;

class Complex
{
private:
	double real, imaginar;
public:
	//constructor
	Complex(double a, double b);

	//return imaginar
	double show_imaginar() const;

	//return real
	double show_real() const;

	//add
	Complex operator+ (Complex z);

	//mul
	Complex operator*  (Complex z);

	//quot
	Complex operator/ (Complex z);

	//abs
	double abs() const;

	//polar form
	void compute_polar() const;

	//destructor
	~Complex();
};