#include <iostream>
#define INITIAL_SIZE 5

class Stack {

  private:
	size_t top;
	size_t size;
	int* array;
	void resize();

  public:
    size_t getSize();
    size_t getTop();
	bool isFull();
	bool isEmpty();
	void push(int);
	int pop();
    Stack(const Stack& stack);
	Stack();
	~Stack();
};
