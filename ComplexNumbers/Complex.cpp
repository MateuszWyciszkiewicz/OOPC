#include "Complex.h"
#include <cmath>

Complex::Complex() : real(0), imag(0) {}

Complex::Complex(double real, double imag)
{
	this->real = real;
	this->imag = imag;
}

Complex::Complex(double real)
{
	this->real = real;
	this->imag = 0;
}

Complex::Complex(const Complex& source)
{
	this->real = source.real;
	this->imag = source.imag;
}

Complex& Complex::operator=(const Complex& source)
{
	if (this == &source) {
		return *this;
	}
	this->real = source.real;
	this->imag = source.imag;
	return *this;
}

Complex& Complex::operator+=(const Complex& source)
{
	this->real += source.real;
	this->imag += source.imag;
	return *this;
}

Complex& Complex::operator-=(const Complex& source)
{
	this->real -= source.real;
	this->imag -= source.imag;
	return *this;
}

Complex& Complex::operator*=(const Complex& source)
{
	double a = this->real;
	double b = this->imag;
	double c = source.real;
	double d = source.imag;
	this->real = a * c - b * d;
	this->imag = a * d + b * c;
	return *this;
}

Complex& Complex::operator/=(const Complex& source)
{
	double a = this->real;
	double b = this->imag;
	double c = source.real;
	double d = source.imag;
	this->real = (a * c + b * d) / (pow(c, 2) + pow(d, 2));
	this->imag = (b * c - a * d) / (pow(c, 2) + pow(d, 2));
	return *this;
}

bool operator==(const Complex c1, const Complex c2)
{
	if (c1.real == c2.real && c1.imag == c2.imag) {
		return true;
	}
	return false;
}

bool operator!=(const Complex c1, const Complex c2)
{
	if (c1.real != c2.real && c1.imag != c2.imag) {
		return true;
	}
	return false;
}

Complex operator+(Complex c1, Complex c2)
{
	c1.real += c2.real;
	c1.imag += c2.imag;
	return c1;
}

Complex operator-(Complex c1, Complex c2)
{
	c1.real -= c2.real;
	c1.imag -= c2.imag;
	return c1;
}

ostream& operator<<(ostream& out, const Complex c1)
{   if(c1.real != 0){
	out << c1.real;
    }
    if(c1.imag ==0 ){
        return out;
        }
	else if (c1.imag < 0) {
		out << "-";
	}
	else if(c1.real != 0){
		out << "+";
	}
    out<<fabs(c1.imag);
    out<<"i";
    return out;
}
