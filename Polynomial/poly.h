#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Poly {
    public:
	struct node {
		int power = 0;
		double coef = 0;
	};
	vector<node> polynomial; // public for test sake!!!!!
	Poly();
    Poly(double coef);
	double& operator[](int power);
    Poly operator-() const;
    double operator()(double arg) const;
    friend Poly operator+(const Poly& p1, const Poly& p2);
    friend Poly operator-(const Poly& p1, const Poly& p2);
    friend ostream& operator<<(ostream& out, const Poly& p);
    friend Poly operator*(const Poly& p1, const Poly& p2);
};
