#include <iostream>
#include "Complex.h"

using namespace std;

int main(){
    Complex c1(5, 6);
    Complex c2(3, 4);
    //c1 = c2;
    Complex c3(c1);
    c1/=c2;
    cout << c1.real <<" "<< c1.imag << endl;
    if(c1 != c3){
        cout << "true" << endl;
        }
    return 0;
    }
