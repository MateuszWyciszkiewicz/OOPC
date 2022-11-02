#include "Complex.h"
#include <iostream>

using namespace std;

void copyConstructorTest();
void assignmentOperatorTest();
void compoundOperatorTests();
void compoundAdditionTest();
void compoundSubstractionTest();
void compoundMultiplicationTest();
void compoundDivisionTest();
void comparisonsOperatorsTests();
void equalityOperatorTest();
void inequalityOperatorTest();
void regularAdditionTest();
void regularSubstractionTest();

int main()
{
	copyConstructorTest();
	assignmentOperatorTest();
	compoundOperatorTests();
	comparisonsOperatorsTests();
	regularAdditionTest();
	regularSubstractionTest();
	return 0;
}

void compoundOperatorTests()
{
	compoundAdditionTest();
	compoundSubstractionTest();
	compoundMultiplicationTest();
	compoundDivisionTest();
}

void compoundAdditionTest()
{
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3(3, 3);
	c1 += c2;
	if (c1 == c3) {
		cout << "compound addition test successful" << endl;
	}
	else {
		cout << "compound addition test failed" << endl;
	}
}

void compoundSubstractionTest()
{
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3(0, 4);
	c1 *= c2;
	if (c1 == c3) {
		cout << "compound substraction test successful" << endl;
	}
	else {
		cout << "compound substraction test failed" << endl;
	}
}

void compoundMultiplicationTest()
{
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3(0, 4);
	c1 *= c2;
	if (c1 == c3) {
		cout << "compound multiplication test successful" << endl;
	}
	else {
		cout << "compound multiplication test failed" << endl;
	}
}
void compoundDivisionTest()
{
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3(0.5, 0);
	c1 /= c2;
	if (c1 == c3) {
		cout << "compound division test successful" << endl;
	}
	else {
		cout << "compound division test failed" << endl;
	}
}

void comparisonsOperatorsTests()
{
	equalityOperatorTest();
	inequalityOperatorTest();
}

void equalityOperatorTest()
{
	Complex c1(1, 1);
	Complex c2(1, 1);

	if (c1 == c2) {
		cout << "equality operator test successful" << endl;
	}
	else {
		cout << "equality operator test failed" << endl;
	}
}

void inequalityOperatorTest()
{
	Complex c1(1, 1);
	Complex c2(2, 2);

	if (c1 != c2) {
		cout << "inequality operator test successful" << endl;
	}
	else {
		cout << "inequality operator test failed" << endl;
	}
}
void copyConstructorTest()
{
	Complex c1(1, 1);
	Complex c3(c1);
	if (c1 == c3) {
		cout << "copy constructor test successful" << endl;
	}
	else {
		cout << "copy constructor test failed" << endl;
	}
}

void assignmentOperatorTest()
{
	Complex c1(1, 1);
	Complex c3;
	c3 = c1;
	if (c1 == c3) {
		cout << "assignment operator test successful" << endl;
	}
	else {
		cout << "assignment operator test failed" << endl;
	}
}

void regularAdditionTest()
{
	Complex c1(1, 1);
	Complex c2(0, 1);
	Complex c3(2, 2);
	double num = 2;
	Complex result1(3, 3);
	Complex result2(1, 2);
	Complex result3(3, 1);
	Complex try1 = c1 + c3;
	Complex try2 = c1 + c2;
	Complex try3 = num + c1;
	Complex try4 = c1 + num;
	if (try1 == result1 && try2 == result2 && try3 == result3 &&
		try4 == result3) {
		cout << "regular addition test successful" << endl;
	}
	else {
		cout << "regular addition test successful" << endl;
	}
}

void regularSubstractionTest()
{
	Complex c1(1, 1);
	Complex c2(0, 1);
	Complex c3(2, 2);
	double num = 2;
	Complex result1(-1, -1);
	Complex result2(1, 0);
    Complex result3(1, -1);
	Complex result4(-1, 1);
	Complex try1 = c1 - c3;
	Complex try2 = c1 - c2;
	Complex try3 = num - c1;
	Complex try4 = c1 - num;
	if (try1 == result1 && try2 == result2 && try3 == result3 &&
		try4 == result4) {
		cout << "regular substraction test successful" << endl;
	}
	else {
		cout << "regular substraction test successful" << endl;
	}
}
