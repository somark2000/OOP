#pragma once
using namespace std;

class Complex
{
private:
	double real, imaginar;
public:
	//constructor
	Complex(double a, double b);
	Complex();
	//destructor
	~Complex();
	//return imaginar
	double show_imaginar() const;
	//return real
	double show_real() const;
	//setter real
	void setReal(double real);
	//setter imaginar
	void setImag(double imaginar);
	//complex nr
	Complex show_compl();
	//add
	Complex operator+(Complex z);
	//mul
	Complex operator*(Complex z);
	//quot
	Complex operator/(Complex z);
	//abs
	double abs() const;
	//polar form
	float unghi();
	string compute_polar();
	//exponential form
	string show_exp();
};