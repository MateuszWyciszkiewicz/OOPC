#include "Matrix.h"

int main() {
    Matrix m1(3, 3);
    m1(2, 2) = 5;
    double num = m1(2, 2);
    cout << num << endl;
    cout << m1(2, 2) << endl;
    return 0;
    }
