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
	bool isEmpty() const;
	void push(int);
	int pop();
    void printStack() const;
    Stack(const Stack& stack);
    Stack& operator=(const Stack& stack);
	Stack();
    void newStack(size_t newsize);
	~Stack();
};
