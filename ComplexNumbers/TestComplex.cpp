#include <iostream>
#include "Complex.h"

using namespace std;

int main(){
    Complex c1(5, 6);
    Complex c2(3, 4);
    //c1 = c2;
    Complex c3(c1);
    cout << c3.real <<"dupa"<< c3.imag << endl;
    if(c1 != c3){
        cout << "dupa22222" << endl;
        }
    return 0;
    }
