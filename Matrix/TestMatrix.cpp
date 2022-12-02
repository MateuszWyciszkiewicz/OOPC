#include "Matrix.h"

void testEqualityAndInequality();
void copyConstructorTest();
void assignmentOperatorTest();
void testDisplay();

int main()
{
	Matrix m1(3, 3);
	m1(2, 2) = 5;
	double num = m1(2, 2);
	Matrix m2(m1);
	m2(1, 2) = 4;
	bool n = m1 == m2;
	cout << n << endl;
	cout << num << endl;
	cout << m1(2, 2) << endl;
    copyConstructorTest();
    assignmentOperatorTest();
	testEqualityAndInequality();
    testDisplay();
	return 0;
}

void copyConstructorTest()
{
	Matrix m1(2, 2);
	m1(1, 2) = 5;
	Matrix m2(m1);
	if (m1 == m2) {
		cout << "copy constructor test successful" << endl;
	}
	else {
		cout << "copy constructor test failed" << endl;
	}
}

void assignmentOperatorTest(){
    Matrix m1(2, 3);
    m1(1, 1) = 6;
    Matrix m2(1, 1);
    m2 = m1;
    if (m2 == m1){
        cout << "assignment operator test successful" << endl ;
        } else {
            cout << "assignment operator test failed" << endl ;
            }
    }
    
void testEqualityAndInequality()
{
	Matrix m1(2, 2);
	Matrix m2(m1);
	Matrix m3(2, 2);
	Matrix m4(1, 1);
	m3(1, 1) = 4;
	if (m2 == m1 && m3 != m1 && m4 != m1) {
		cout << "equality/inequality test successful" << endl;
	}
	else {
		cout << "equality/inequality test failed" << endl;
	}
}

void testDisplay(){
    Matrix m(5, 5);
    m(1, 1) = 4;
    m(1, 2) = 4;
    m(2, 5) = 5;
    cout << "display test:" << endl;
    cout << m << endl;
    }
