#include "stack.h"

#include <stdlib.h>

using namespace std;

Stack::Stack()
{
    this->top = 0;
    this -> newStack((size_t) INITIAL_SIZE);
}

void Stack::newStack(size_t newSize)
{
    this->size = newSize;
    this->array = (int*)malloc(this->size * sizeof(int));
    if (this->array == NULL) {
        cout << "Error during stack allocation" << endl;
        abort();
    }
}

Stack::~Stack()
{
    free(this->array);
}

Stack::Stack(const Stack& stack)
{
    this->size = stack.size;
    this -> newStack(stack.size);
    copy(stack.array, stack.array + stack.size, this->array);
    this->top = stack.top;
}

Stack& Stack::operator=(const Stack& stack)
{
    if (this == &stack) {
        return *this;
    }
    if (this->size < stack.top) {
        free(this->array);
        this -> newStack(stack.size);
    }
    copy(stack.array, stack.array + stack.top, this->array);
    this->top = stack.top;
    return *this;
}

bool Stack::isFull()
{
    return (this->top == this->size - 1);
}

bool Stack::isEmpty() const
{
    return (this->top == 0);
}

void Stack::printStack() const
{
    if (isEmpty()) {
        cout << "Stack empty" << endl;
    }
    else {
        for (int i = this->top - 1; i >= 0; i--) {
            cout << this->array[i] << "  ";
        }
        cout << endl;
    }
}
void Stack::resize()
{
    size_t newSize = (this->size) * 2;
    int* newArray = (int*)realloc(this->array, newSize * sizeof(int));
    if (newArray) {
        this->array = newArray;
        this->size = newSize;
    }
    else {
        cout << "error during stack reallocation" << endl;
        abort();
    }
}

void Stack::push(int number)
{
    if (isFull()) {
        resize();
    }
    this->array[this->top] = number;
    this->top++;
}

int Stack::pop()
{
    if (isEmpty()) {
        cout << "poping from empty stack" << endl;
        abort();
    }
    else {
        this->top--;
        return this->array[this->top];
    }
}
