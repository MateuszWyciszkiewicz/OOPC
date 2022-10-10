#include <iostream>
#define INITIAL_SIZE 5

class Stack {

  private:
	size_t top;
	size_t size;
	int* array;
	void resize();

  public:
	bool isFull();
	bool isEmpty();
	void push(int);
	int pop();
	Stack();
	~Stack();
};
