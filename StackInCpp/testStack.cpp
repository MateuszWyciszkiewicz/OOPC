#include "stack.h"

using namespace std;

void testIsEmpty(Stack* stack);
void testRegularPush(Stack* stack);
void testRegularPop(Stack* stack);

int main()
{
	Stack s1;
	// Stack s2;
	testIsEmpty(&s1);
	testRegularPush(&s1);
    testRegularPop(&s1);
	return 0;
}

void testIsEmpty(Stack* stack)
{
	cout << "Testing method isEmpty" << endl;
	if (stack->isEmpty()) {
		cout << "stack empty. Test successfull\n" << endl;
	}
	else {
		cout << "Stack not empty, test failed\n" << endl;
	}
}

void testRegularPush(Stack* stack)
{
	cout << "Testing method push" << endl;
	int num = 5;
	stack->push(num);
	cout << "Push function test successful\n" << endl;
}

void testRegularPop(Stack* stack)
{
	cout << "Testing method pop" << endl;
	int num = 5;
	int result = stack->pop();
	if (result == num) {
		cout << "Pop function test successful\n" << endl;
	}
	else {
		cout << "Pop function test failed\n" << endl;
	}
}

