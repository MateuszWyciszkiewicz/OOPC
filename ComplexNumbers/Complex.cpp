#include "Complex.h"
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
	this->real *= source.real;
	this->imag *= source.imag;
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
