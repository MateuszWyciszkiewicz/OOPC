#include "poly.h"

Poly::Poly() {}

Poly::Poly(double coef)
{
	struct Poly::node newNode;
	newNode.coef = coef;
	polynomial.push_back(newNode);
}

vector<Poly::node> pushNode(vector<Poly::node> vect, double coef, int power)
{
	Poly::node newNode;
	newNode.power = power;
	newNode.coef = coef;
	vect.push_back(newNode);
	return vect;
}

double& Poly::operator[](int power)
{
	struct Poly::node newNode;
	newNode.power = power;
	bool inserted = false;
	int position = 0;
	for (node& currentNode : polynomial) {
		if (currentNode.power < power) {
			polynomial.insert(polynomial.begin() + position, newNode);
			inserted = true;
			break;
		}
		if (currentNode.power == power) {
			inserted = true;
			break;
		}
		position++;
	}
	if (!inserted) {
		polynomial.push_back(newNode);
	}
	return polynomial[position].coef;
}

Poly Poly::operator-() const
{
	Poly negated;
	for (const node& currentNode : this->polynomial) {
		negated.polynomial =
			pushNode(negated.polynomial, -currentNode.coef, currentNode.power);
	}

	return negated;
}

double Poly::operator()(double arg) const
{
	double result = 0;
	for (const node& currentNode : this->polynomial) {
		result += currentNode.coef * pow(arg, currentNode.power);
	}
	return result;
}

Poly operator+(const Poly& p1, const Poly& p2)
{
	Poly result;
	unsigned int iter1 = 0, iter2 = 0;
	while (iter2 < p2.polynomial.size() || iter1 < p1.polynomial.size()) {
		if (p1.polynomial[iter1].power > p2.polynomial[iter2].power) {
			result.polynomial.push_back(p1.polynomial[iter1]);
			iter1++;
		}
		else if (p1.polynomial[iter1].power < p2.polynomial[iter2].power) {
			result.polynomial.push_back(p2.polynomial[iter2]);
			iter2++;
		}
		else {
			result.polynomial = pushNode(result.polynomial,
						 p2.polynomial[iter2].coef + p1.polynomial[iter1].coef,
						 p2.polynomial[iter2].power);
			iter1++;
			iter2++;
		}
	}
	return result;
}

Poly operator-(const Poly& p1, const Poly& p2)
{
	Poly result;
	unsigned long iter1 = 0, iter2 = 0;
	while (iter2 < p2.polynomial.size() || iter1 < p1.polynomial.size()) {
		if (p1.polynomial[iter1].power > p2.polynomial[iter2].power) {
			result.polynomial.push_back(p1.polynomial[iter1]);
			iter1++;
		}
		else if (p1.polynomial[iter1].power < p2.polynomial[iter2].power) {
			result.polynomial =
				pushNode(result.polynomial, -p2.polynomial[iter2].coef,
						 p2.polynomial[iter2].power);
			iter2++;
		}
		else {
			result.polynomial = pushNode(result.polynomial,
						 p1.polynomial[iter1].coef - p2.polynomial[iter2].coef,
						 p1.polynomial[iter1].power);
			iter1++;
			iter2++;
		}
	}
	return result;
}

ostream& operator<<(ostream& out, const Poly& poly)
{
	bool empty = true;
	bool first = true;
	for (const Poly::node& currentNode : poly.polynomial) {
		if (currentNode.coef > 0 && !first) {
			out << " + ";
		}
		else if (currentNode.coef < 0) {
			out << " - ";
		}
		if (currentNode.coef != 0) {
			first = false;
            empty = false;
			if (currentNode.coef != 1 && currentNode.coef != -1) {
				out << fabs(currentNode.coef);
			}
			if (currentNode.power == 1) {
				out << "x";
			}
			else if (currentNode.power != 0) {
				out << "x^";
				out << currentNode.power;
			}
		}
	}
	if (empty) {
		out.clear();
		out << "0";
	}
	return out;
}

Poly operator*(const Poly& p1, const Poly& p2)
{
	Poly result;
	for (unsigned int i = 0; i < p1.polynomial.size(); i++) {
		for (unsigned int j = 0; j < p2.polynomial.size(); j++) {
				result[p2.polynomial[j].power + p1.polynomial[i].power] +=
					p2.polynomial[j].coef * p1.polynomial[i].coef;
		}
	}
	return result;
}
