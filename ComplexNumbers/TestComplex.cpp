#include "Complex.h"

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
void regularMultiplicationTest();
void regularDivisionTest();
void testOutStream();
void testAmplitude();
void testPhase();
void specialCasesTest();

int main()
{
	copyConstructorTest();
	assignmentOperatorTest();
	compoundOperatorTests();
	comparisonsOperatorsTests();
	regularAdditionTest();
	regularSubstractionTest();
	regularMultiplicationTest();
	regularDivisionTest();
	testAmplitude();
	testPhase();
    specialCasesTest();
	testOutStream();
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
    Complex c4(3, 2);
	c1 += c2;
    c2 += 1;
	if (c1 == c3 && c4 == c2) {
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
	Complex c3(1, 1);
    Complex c4(0, 1);
	c2 -= c1;
    c1 -= 1;
    	if (c2 == c3 && c1 == c4) {
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
    Complex c4(4, 4);
	c1 *= c2;
    c2 *= 2;
	if (c1 == c3 && c4 == c2) {
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
    Complex c4(1, 1);
	c1 /= c2;
    c2 /= 2;
	if (c1 == c3 && c2 == c4) {
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

void regularMultiplicationTest()
{
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3(0, 4);
	Complex c4, c5;
    double num = 2;
	c4 = c1 * c2;
    c5 = c1 * num;
	if (c4 == c3 && c5 == c2) {
		cout << "regular multiplication test successful" << endl;
	}
	else {
		cout << "regular multiplication test failed" << endl;
	}
}

void regularDivisionTest()
{
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3(0.5, 0);
	Complex c4, c5;
	c4 = c1 / c2;
    c5 = c2 / 2;
	if (c4 == c3 && c5 == c1) {
		cout << "regular division test successful" << endl;
	}
	else {
		cout << "regular division test failed" << endl;
	}
}

void testOutStream()
{
    cout << "outstream test:" << endl;
	Complex c1;
	Complex c2(1, 0);
	Complex c3(0, 1);
	Complex c4(2, -2);
	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
}

void testAmplitude()
{
	Complex c1(3, 4);
    Complex c2(3, 4);
	if (c1.amplitude() == 5 && c2.amplitude() == 5) {
		cout << "amplitude test successful" << endl;
	}
	else {
		cout << "amplitude test failed" << endl;
	}
}

void testPhase()
{
	Complex c1(3, 4);
    Complex c2(-3, 0);
    Complex c3(-3, -4);
    Complex c4(-3, 4);
	double num1 = 3;
	double num2 = 4;
	if (c1.phase() == (2 * atan(num2 / (5.0 + num1))) && c2.phase() == M_PI && c3.phase() == (2 * atan(-4 / (5.0 + -3)))) {
		cout << "phase test successful" << endl;
	}
	else {
		cout << "phase test failed" << endl;
	}
}
void specialCasesTest()
{
	Complex a(1, 1);
	Complex b(2, 2);
	Complex c(3, 3);
	a += b += c; 
	(a += b) += c; 
	a *= b *= c; 
	a *= b *= c;
	a + 7; 
	7 + a;
	b * 5;
	5 * b;
	c == 3.5; 
	3.5 == c; 
    cout << "special cases test successful" << endl;
}

