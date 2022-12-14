#pragma once
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Poly {
  private:
    struct node {
        int power = 0;
        double coef = 0;
    };
    static vector<node>& pushNode(vector<node>& vect, double coef, int power);
    vector<node> polynomial;

  public:
    Poly() = default;
    Poly(double coef);
    double& operator[](int power);
    Poly operator-() const;
    double operator()(double arg) const;
    friend Poly operator+(const Poly& p1, const Poly& p2);
    friend Poly operator-(const Poly& p1, const Poly& p2);
    friend ostream& operator<<(ostream& out, const Poly& p);
    friend Poly operator*(const Poly& p1, const Poly& p2);
};
