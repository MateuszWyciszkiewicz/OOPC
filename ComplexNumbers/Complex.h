#include <iostream>
#include <cmath>
using namespace std;

class Complex {
  public:
	double real;
	double imag;

	Complex(double real, double imag);
	Complex(double real);
	Complex();
	Complex(const Complex& c);
	Complex& operator=(const Complex& c);
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);
	double amplitude() const;
	double phase() const;
};

bool operator==(const Complex& c1, const Complex& c2);
bool operator!=(const Complex& c1, const Complex& c2);
Complex operator+(Complex c1, Complex c2);
Complex operator-(Complex c1, Complex c2);
Complex operator*(Complex c1, Complex c2);
Complex operator/(Complex c1, Complex c2);
ostream& operator<<(ostream&, const Complex& c);
