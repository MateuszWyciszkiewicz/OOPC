class Complex {
  public:
	double real;
	double imag;

	Complex(double, double);
    Complex(double);
    Complex();
    Complex(const Complex&);
    Complex& operator=(const Complex&);
    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator/=(const Complex&);
};

bool operator==(const Complex, const Complex);
bool operator!=(const Complex, const Complex);
Complex operator+(Complex, Complex);
Complex operator-(Complex, Complex);
