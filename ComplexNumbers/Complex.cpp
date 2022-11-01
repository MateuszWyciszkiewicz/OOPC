#include "Complex.h"
#include <cmath>
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
    double b = this -> imag;
    double c = source.real;
    double d = source.imag;
    this -> real = a*c - b*d;
    this -> imag = a*d + b*c;
    return *this;
}

Complex& Complex::operator /=(const Complex& source){
    double a = this->real;
    double b = this -> imag;
    double c = source.real;
    double d = source.imag;
    this -> real = (a*c + b*d)/(pow(c, 2) + pow(d, 2));
    this -> imag = (b*c - a*d)/(pow(c, 2) + pow(d, 2));
    return *this;
    }

bool operator==(Complex c1, Complex c2)
{
	if (c1.real == c2.real && c1.imag == c2.imag) {
		return true;
	}
	return false;
}

bool operator!=(Complex c1, Complex c2)
{
	if (c1.real != c2.real && c1.imag != c2.imag) {
		return true;
	}
	return false;
}
