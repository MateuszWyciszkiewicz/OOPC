#include "Matrix.h"

int main() {
    Matrix m1(3, 3);
    m1(2, 2) = 5;
    double num = m1(2, 2);
    Matrix m2(m1);
    m2(1, 2) = 4;
    bool n = m1 == m2;
    cout <<  n << endl;
    cout << num << endl;
    cout << m1(2, 2) << endl;
    return 0;
    }
