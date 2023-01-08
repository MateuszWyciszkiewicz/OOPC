# pragma once
#include <iostream>

using namespace std;

class Employee {
    public:
        string name;
        string position;
        int age;
        
        Employee() = default;
        Employee(string name, string position, int age){
            this -> name = name;
            this -> position = position;
            this -> age = age;
            };
            
        friend ostream& operator <<(ostream& out, const Employee& e){
           out << e.name;
           out << " ";
           out << e.position;
           out << " ";
           out << e.age << endl;
           return out; 
            }
    };
