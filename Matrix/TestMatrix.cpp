#include "Matrix.h"

void testEqualityAndInequality();
void copyConstructorTest();
void assignmentOperatorTest();
void testDisplay();
void testCompoundAddition();
void testCompoundSubstraction();
void testRegularAddition();
void testRegularSubstraction();
void testInvlidIndexException();
void testInvalidFileNameException();
void testInvalidFileException();
void testInvalidMatrixSizeException();
void testRegularMultiplication();
void testMultiplyByConst();
void testCompoundMultiplication();
void testCompoundMultiplicationByConst();
void testRefCount();
void readWriteTest();
void testReadingFromFile();

int main()
{
    copyConstructorTest();
    assignmentOperatorTest();
    testEqualityAndInequality();
    testCompoundAddition();
    testCompoundSubstraction();
    testRegularAddition();
    testRegularSubstraction();
    testInvlidIndexException();
    testInvalidFileNameException();
    testInvalidFileException();
    testInvalidMatrixSizeException();
    testRegularMultiplication();
    testMultiplyByConst();
    testCompoundMultiplication();
    testCompoundMultiplicationByConst();
    testRefCount();
    readWriteTest();
    testReadingFromFile();
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

void assignmentOperatorTest()
{
    Matrix m1(2, 3);
    m1(1, 1) = 6;
    Matrix m2(1, 1);
    m2 = m1;
    if (m2 == m1) {
        cout << "assignment operator test successful" << endl;
    }
    else {
        cout << "assignment operator test failed" << endl;
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

void testDisplay()
{
    Matrix m(5, 5);
    m(1, 1) = 4;
    m(1, 2) = 4;
    m(2, 5) = 5;
    cout << "display test:" << endl;
    cout << m << endl;
}

void testCompoundAddition()
{
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    Matrix m3(2, 2);
    m1(1, 1) = 1;
    m1(1, 2) = 2;
    m1(2, 1) = 3;
    m1(2, 2) = 4;
    
    m2(1, 1) = 2;
    m2(1, 2) = 3;
    m2(2, 1) = 4;
    m2(2, 2) = 1;
    
    m3(1, 1) = 3;
    m3(1, 2) = 5;
    m3(2, 1) = 7;
    m3(2, 2) = 5;
    m1 += m2;
    /*Matrix m4(m1);
    cout << m4 << endl;
    cout << m1.getRefCount() << endl;
    cout << m2.getRefCount() << endl;
    cout << m4.getRefCount() << endl;
    m1 += m2;
    cout << m4 << endl;
    cout << m1.getRefCount() << endl;
    cout << m2.getRefCount() << endl;
    cout << m4.getRefCount() << endl;*/
    if (m1 == m3) {
        cout << "compound addition test successful" << endl;
    }
    else {
        cout << "compound addition test failed" << endl;
    }
}

void testCompoundSubstraction()
{
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    Matrix m3(2, 2);
    m1(1, 1) = 5;
    m1(1, 2) = 2;
    m1(2, 1) = 3;
    m1(2, 2) = 1;
    
    m2(1, 1) = 3;
    m2(1, 2) = 2;
    m2(2, 1) = 1;
    m2(2, 2) = 6;
    
    m3(1, 1) = 2;
    m3(1, 2) = 0;
    m3(2, 1) = 2;
    m3(2, 2) = -5;
    m1 -= m2;
    if (m1 == m3) {
        cout << "compound substraction test successful" << endl;
    }
    else {
        cout << "compound substraction test failed" << endl;
    }
}

void testRegularAddition()
{
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    Matrix m3(2, 2);
    m1(1, 1) = 5;
    m1(1, 2) = 3;
    m1(2, 1) = 3;
    m1(2, 2) = 6;
    
    m2(1, 1) = 2;
    m2(1, 2) = 3;
    m2(2, 1) = 4;
    m2(2, 2) = 1;
    
    m3(1, 1) = 7;
    m3(1, 2) = 6;
    m3(2, 1) = 7;
    m3(2, 2) = 7;
    Matrix m4 = m1 + m2;
    if (m4 == m3) {
        cout << "regular addition test successful" << endl;
    }
    else {
        cout << "regular addition test failed" << endl;
    }
}

void testRegularSubstraction()
{
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    Matrix m3(2, 2);
    m1(1, 1) = 7;
    m1(1, 2) = 2;
    m1(2, 1) = 3;
    m1(2, 2) = 6;
    
    m2(1, 1) = 2;
    m2(1, 2) = 3;
    m2(2, 1) = 4;
    m2(2, 2) = 1;
    
    m3(1, 1) = 5;
    m3(1, 2) = -1;
    m3(2, 1) = -1;
    m3(2, 2) = 5;
    Matrix m4 = m1 - m2;
    if (m4 == m3) {
        cout << "regular substraction test successful" << endl;
    }
    else {
        cout << "regular substraction test failed" << endl;
    }
}

void testInvlidIndexException()
{
    Matrix m(2, 2);
    try {
        m(3, 3);
    }
    catch (InvalidIndexException e) {
        cout << "InvalidIndexException test successful" << endl;
        return;
    }
    cout << "InvalidIndexException test failed" << endl;
}

void testInvalidFileNameException()
{
    try {
        Matrix m("wrongFile.txt");
    }
    catch (InvalidFileNameException e) {
        cout << "InvalidFileNameException test successful" << endl;
        return;
    }
    cout << "InvalidFileNameException test failed" << endl;
}

void testInvalidFileException()
{
    try {
        Matrix m("wrongMatrix.txt");
    }
    catch (InvalidFileException e) {
        cout << "InvalidFileException test successful" << endl;
        return;
    }
    cout << "InvalidFileException test failed" << endl;
}

void testInvalidMatrixSizeException()
{
    Matrix m1(2, 3);
    Matrix m2(1, 1);
    try {
        m1 + m2;
    }
    catch (InvalidMatrixSizeException e) {
        cout << "InvalidMatrixSizeException test successful" << endl;
        return;
    }
    cout << "InvalidMatrixSizeException test failed" << endl;
}

void testRegularMultiplication()
{
    Matrix m1(2, 3);
    Matrix m2(3, 2);
    Matrix m3(2, 2);
    m1(1, 1) = 1;
    m1(1, 2) = 2;
    m1(1, 3) = 3;
    m1(2, 1) = 1;
    m1(2, 2) = 2;
    m1(2, 3) = 3;
    
    m2(1, 1) = 1;
    m2(1, 2) = 1;
    m2(2, 1) = 2;
    m2(2, 2) = 2;
    m2(3, 1) = 3;
    m2(3, 2) = 3;
    
    m3(1, 1) = 14;
    m3(1, 2) = 14;
    m3(2, 1) = 14;
    m3(2, 2) = 14;
    Matrix m4 = m1 * m2;
    if (m4 == m3) {
        cout << "regular multiplication test successful" << endl;
    }
    else {
        cout << "regular multiplication test failed" << endl;
    }
}

void testMultiplyByConst()
{
    Matrix m1(2, 2);
    m1(1, 1) = 1;
    m1(1, 2) = 2;
    m1(2, 1) = 5;
    m1(2, 2) = 3;
    Matrix m2(2, 2);
    m2(1, 1) = 2;
    m2(1, 2) = 4;
    m2(2, 1) = 10;
    m2(2, 2) = 6;
    Matrix m3 = 2 * m1;
    Matrix m4 = m1 * 2;
    if (m3 == m2 && m4 == m2) {
        cout << "multiplying by constant test successful" << endl;
    }
    else {
        cout << "multiplying by constant test failed" << endl;
    }
}

void testCompoundMultiplication()
{
    Matrix m1(2, 3);
    Matrix m2(3, 2);
    Matrix m3(2, 2);
    m1(1, 1) = 1;
    m1(1, 2) = 2;
    m1(1, 3) = 3;
    m1(2, 1) = 1;
    m1(2, 2) = 2;
    m1(2, 3) = 3;
    
    m2(1, 1) = 1;
    m2(1, 2) = 1;
    m2(2, 1) = 2;
    m2(2, 2) = 2;
    m2(3, 1) = 3;
    m2(3, 2) = 3;
    
    m3(1, 1) = 14;
    m3(1, 2) = 14;
    m3(2, 1) = 14;
    m3(2, 2) = 14;
    m1 *= m2;
    if (m1 == m3) {
        cout << "compound multiplication test successful" << endl;
    }
    else {
        cout << "compound multiplication test failed" << endl;
    }
}

void testCompoundMultiplicationByConst()
{
    Matrix m1(2, 2);
    m1(1, 1) = 3;
    m1(1, 2) = 7;
    m1(2, 1) = 7;
    m1(2, 2) = 4;
    Matrix m2(2, 2);
    m2(1, 1) = 6;
    m2(1, 2) = 14;
    m2(2, 1) = 14;
    m2(2, 2) = 8    ;
    m1 *= 2;
    if (m1 == m2) {
        cout << "compound multiplying by constant test successful" << endl;
    }
    else {
        cout << "compound multiplying by constant test failed" << endl;
    }
}

void testRefCount()
{
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    m1(1, 2) = 5;
    m1(1, 1) = 6;
    m2 = m1;
    Matrix m3(m1);
    if (!(m1.getRefCount() == 3)) {
        cout << "reference counting test failed" << endl;
        return;
    }
    m1 += m2;
    if (!(m1.getRefCount() == 1 && m2.getRefCount() == 2 && m3.getRefCount() == 2)) {
        cout << "reference counting test failed" << endl;
        return;
    }
    m3(2, 1) = 5;
    m2 -= m1;
    if (!(m1.getRefCount() == 1 && m2.getRefCount() == 1 && m3.getRefCount() == 1)) {
        cout << "reference counting test failed" << endl;
        return;
    }
    Matrix m4(3,3);
    Matrix m5(m4);
    m4(3,3) = 6;
    if (!(m4.getRefCount() == 1 && m5.getRefCount() == 1)) {
        cout << "reference counting test failed" << endl;
        return;
    }
    cout << "reference counting test passed" << endl;
    
}

void readWriteTest()
{
    Matrix m1(2, 2);
    double num = 5;
    m1(1, 2) = num;
    if (m1(1, 2) == num) {
        cout << "read/write test successful" << endl;
    }
    else {
        cout << "read/write test failed" << endl;
    }
}

void testReadingFromFile()
{
    Matrix m1("matrix.txt");
    Matrix m2("matrix1.txt");
    if (m1 == m2) {
        cout << "reading from file test successful" << endl;
    }
    else {
        cout << "reading from file test faied" << endl;
    }
}
