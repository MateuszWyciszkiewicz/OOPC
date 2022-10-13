#include "stack.h"

#include <stdlib.h>

using namespace std;

Stack::Stack()
{
    cout << "called constructor for stack\n" <<endl;
	this->top = 0;
	this->size = INITIAL_SIZE;
	this->array = (int*)malloc(this->size * sizeof(int));
}

Stack::~Stack()
{
	cout << "called destructor for stack\n" << endl;
	free(this->array);
}

bool Stack::isFull()
{
	return (this->top == this->size - 1);
}

bool Stack::isEmpty()
{
	return (this->top == 0);
}

void Stack::resize()
{
	size_t newSize = (this->size) * 2;
	int* newArray = (int*)realloc(this->array, newSize*sizeof(int));
	if (newArray) {
		this->array = newArray;
        this -> size = newSize;
	}
	else {
		cout << "error during stack reallocation" << endl;
		abort();
	}
}

void Stack::push(int number){
	if(isFull()){
		resize();
		}
	this -> array[this -> top] = number;
	this -> top++;	
	}
	
int Stack::pop(){
	if(isEmpty()){
		cout<<"poping from empty stack"<<endl;
		abort();
		} else {
			this -> top--;
			return this -> array[this -> top];
			}
	}

size_t Stack::getSize(){
    return this -> size;
    }

size_t Stack::getTop(){
    return this -> top;
    }
