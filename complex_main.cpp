#include <iostream>
#include <cmath>
#include <string>
#include "complex.h"
using namespace std;

void arata_complex()
{
	double a, b;
	cout << "1.  FORMA GENERALA A UNUI NUMAR COMPLEX" << endl;
	cout << "Introduceti partea intreaga: ";
	cin >> a;
	cout << "Introduceti partea imaginara: ";
	cin >> b;
	Complex x(a, b);

	Complex r = x.show_compl();

	cout << "Numarul complex introdus este: ";
	if (b < 0)
		cout << r.show_real() << r.show_imaginar() << "i" << endl;
	else
		cout << r.show_real() << "+" << r.show_imaginar() << "i" << endl;

}

void adunare()
{
	double a, b, c, d;
	cout << "2.  ADUNAREA A 2 NUMERE COMPLEXE" << endl;
	cout << "Introduceti partea intreaga a primului nr: ";
	cin >> a;
	cout << "Introduceti partea imaginara a primului nr: ";
	cin >> b;
	cout << "Introduceti partea intreaga a celui de al doilea nr: ";
	cin >> c;
	cout << "Introduceti partea imaginara a celui de al doilea nr: ";
	cin >> d;

	Complex x(a, b); //primul numar complex
	Complex y(c, d); //al doilea numar complex

	Complex r = x.operator+(y);

	cout << "Rezultatul adunarii: ";
	if (b + d < 0)
		cout << r.show_real() << r.show_imaginar() << "i" << endl;
	else
		cout << r.show_real() << "+" << r.show_imaginar() << "i" << endl;

}
void inmultire()
{
	double a, b, c, d;
	cout << "3.  INMULTIREA A 2 NUMERE COMPLEXE" << endl;
	cout << "Introduceti partea intreaga a primului nr: ";
	cin >> a;
	cout << "Introduceti partea imaginara a primului nr: ";
	cin >> b;
	cout << "Introduceti partea intreaga a celui de al doilea nr: ";
	cin >> c;
	cout << "Introduceti partea imaginara a celui de al doilea nr: ";
	cin >> d;

	Complex x(a, b); //primul nr
	Complex y(c, d); //al doilea nr

	Complex r = x.operator*(y);

	cout << "Rezultatul inmultirii: ";
	if (a * d + b * c < 0)
		cout << r.show_real() << r.show_imaginar() << "i" << endl;
	else
		cout << r.show_real() << "+" << r.show_imaginar() << "i" << endl;

}

void impartire()
{
	double a, b, c, d;
	cout << "4.  IMPARTIREA A 2 NUMERE COMPLEXE" << endl;
	cout << "Introduceti partea intreaga a primului nr: ";
	cin >> a;
	cout << "Introduceti partea imaginara a primului nr: ";
	cin >> b;
	cout << "Introduceti partea intreaga a celui de al doilea nr: ";
	cin >> c;
	cout << "Introduceti partea imaginara a celui de al doilea nr: ";
	cin >> d;

	Complex x(a, b); //primul nr
	Complex y(c, d); //al doilea nr

	Complex r = x.operator/(y);

	cout << "Rezultatul impartirii: ";
	if (a * (-1) * d + c * b < 0)
		cout << r.show_real() << r.show_imaginar() << "i" << endl;
	else
		cout << r.show_real() << "+" << r.show_imaginar() << "i" << endl;

}

void modul()
{
	double a, b;
	cout << "5.  MODULUL UNUI NUMAR COMPLEX" << endl;
	cout << "Introduceti partea intreaga: ";
	cin >> a;
	cout << "Introduceti partea imaginara: ";
	cin >> b;

	Complex x(a, b);

	double r = x.abs();

	cout << "Modulul numarului complex este: ";
	cout << "sqrt" << (a * a + b * b) << " = " << r << "." << endl;
}

void polar()
{
	double a, b;
	cout << "6.  FORMA POLARA" << endl;
	cout << "Introduceti partea intreaga: ";
	cin >> a;
	cout << "Introduceti partea imaginara: ";
	cin >> b;
	Complex x(a, b);
	double r = x.abs();
	float u = x.unghi();
	//char grad = 167; //codul ascii pentru semnul "grad"

	cout << "Forma polara este:  " << r << "*(cos(" << u << "^" << ")+sin(" << u << "^" << ")*i)" << endl;

}

void exponential()
{
	double a, b;
	cout << "7.  FORMA EXPONENTIALA A UNUI NUMAR COMPLEX" << endl;
	cout << "Introduceti partea intreaga: ";
	cin >> a;
	cout << "Introduceti partea imaginara: ";
	cin >> b;
	Complex x(a, b);
	double r = x.abs();
	float u = x.unghi();

	cout << "Forma exponentiala este:  " << r << "*e^(" << u << '*' << "*i)" << endl;
}

void creaza()
{
	int n, i, j;
	double lista_modul[20], parte_imaginara, parte_reala;
	Complex c1, sir[30];
	cout << "8.  SORTARE, SUMA SERIEI" << endl;
	cout << "Cate numere complexe doriti sa introduceti?" << endl;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "Introduceti partea reala: ";
		cin >> parte_reala;
		cout << "Introduceti partea imaginara: ";
		cin >> parte_imaginara;
		c1.setReal(parte_reala);
		c1.setImag(parte_imaginara);
		sir[i] = c1;
	}
	cout << "Numerele complexe sunt: " << endl;
	for (i = 0; i <= n - 1; i++)
		if (sir[i].show_imaginar() > 0)
			cout << sir[i].show_real() << "+" << sir[i].show_imaginar() << "i" << endl;
		else
			cout << sir[i].show_real() << sir[i].show_imaginar() << "i" << endl; //le afisez
	for (i = 0; i <= n - 1; i++) //calculez modulul fiecarui numar complex si il pun intr-un vector numit lista_modul
		lista_modul[i] = sir[i].abs();
	for (i = 0; i < n - 1; i++) //sortez crescator modulele numerelor
		for (j = i + 1; j < n; j++)
			if (lista_modul[i] > lista_modul[j])
			{
				double auxiliar;
				auxiliar = lista_modul[i];
				lista_modul[i] = lista_modul[j];
				lista_modul[j] = auxiliar;
			}
	cout << "Modulele numerelor sortate crescator sunt: "; //afisez modulele sortate crescator pe ecran
	for (i = 0; i < n; i++)
		cout << lista_modul[i] << " " << endl;
	cout << "Numerele complexe sortate crescator in functie de modulul lor sunt:  ";
	for (i = 0; i < n; i++) //afisez numerele complexe sortate crescator in functie de modulul lor
		for (j = 0; j < n; j++)
			if (lista_modul[i] == sir[j].abs())
				if (sir[j].show_imaginar() < 0)
					cout << sir[j].show_real() << sir[j].show_imaginar() << "i  " << endl;
				else
					cout << sir[j].show_real() << "+" << sir[j].show_imaginar() << "i  " << endl;
	cout << "Suma seriei este: ";
	double suma_real = 0, suma_imaginar = 0;
	for (i = 0; i < n; i++) //calculez suma tuturor numerelor complexe citite anterior de la tastatura
		suma_real = suma_real + sir[i].show_real();
	for (i = 0; i < n; i++)
		suma_real = suma_real + sir[i].show_imaginar();
	if (suma_imaginar > 0)
		cout << suma_real << "+" << suma_imaginar << "i" << endl; //afisez suma pe ecran 
	else
		cout << suma_real << suma_imaginar << "i" << endl;
}

void test_adunare()
//Se testeaza metoda de adunare a 2 numere complexe.
{
	Complex nr1 = Complex(-1, -2);
	Complex nr2 = Complex(1, 2);
	Complex rez = nr1.operator+(nr2);
	if (rez.show_real() == 0 && rez.show_imaginar() == 0)
		cout << "Test ok!";
	Complex nr3 = Complex(-1, -2);
	Complex nr4 = Complex(7, 2);
	Complex rez2 = nr1.operator+(nr2);
	if (rez2.show_real() == 6 && rez2.show_imaginar() == 0)
		cout << "Test ok!";
}

void test_inmultire()
//Se testeaza metoda de inmultire a 2 numere complexe.
{
	Complex nr1 = Complex(-1, -2);
	Complex nr2 = Complex(1, 2);
	Complex rez = nr1.operator*(nr2);
	if (rez.show_real() == 3 && rez.show_imaginar() == -4)
		cout << "Test ok!";
	Complex nr3 = Complex(-1, -2);
	Complex nr4 = Complex(7, 2);
	Complex rez2 = nr3.operator*(nr4);
	if (rez2.show_real() == -3 && rez2.show_imaginar() == -16)
		cout << "Test ok!";
}

void test_impartire()
//Se testeaza metoda de impartire a 2 numere complexe.
{
	Complex nr1 = Complex(1, 2);
	Complex nr2 = Complex(3, 3);
	Complex rez = nr1.operator/(nr2);
	if (rez.show_real() == 0.5 && rez.show_imaginar() == 0.166667)
		cout << "Test ok!";
	Complex nr3 = Complex(5, 2);
	Complex nr4 = Complex(5, 2);
	Complex rez2 = nr3.operator/(nr4);
	if (rez2.show_real() == 1 && rez2.show_imaginar() == 0)
		cout << "Test ok!";
}
void test_abs()
//Se testeaza metoda de determinare a modulului a unui nr complex.
{
	Complex nr1 = Complex(0, 0);
	Complex nr2 = Complex(3, 4);
	double rez1 = nr1.abs();
	double rez2 = nr2.abs();
	if (rez1 == 0 && rez2 == 5)
		cout << "Test ok!";
}

void test_polar()
//Se testeaza metoda de determinare a formei polare a unui nr complex.
{
	Complex nr1 = Complex(1, 0);
	Complex nr2 = Complex(3, 4);
	float rez = nr1.unghi();
	float rez1 = nr2.unghi();
	if (rez == 0 && rez1 == 53)
		cout << "Test ok!";
}

int main()
{
	arata_complex();
	adunare();
	inmultire();
	impartire();
	modul();
	polar();
	exponential();
	creaza();
	cout << endl;
	cout << "TESTE: " << endl;
	test_adunare();
	test_abs();
	test_inmultire();
	test_polar();
	test_impartire();
	return 0;
}