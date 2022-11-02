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

int main()
{
	copyConstructorTest();
	assignmentOperatorTest();
	compoundOperatorTests();
    comparisonsOperatorsTests();
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

void inequalityOperatorTest(){
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
