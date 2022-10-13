#include "stack.h"

using namespace std;

void testIsEmpty(Stack& stack);
void testRegularPush(Stack& stack);
void testRegularPop(Stack& stack);
void testIsFull(Stack& stack);
void testPushOverlimit(Stack& stack);
void testOverlimitPush(Stack& stack);

int main()
{
	Stack s1;
	Stack s2;
	testIsEmpty(s1);
	testIsEmpty(s2);
	testRegularPush(s1);
	testRegularPush(s2);
	testRegularPop(s1);
	testRegularPop(s2);
	testOverlimitPush(s1);
	testOverlimitPush(s2);
	testIsFull(s1);
	testIsFull(s2);
	// testPushOverlimit(s1);
	return 0;
}

void testIsEmpty(Stack& stack)
{
	cout << "Testing method isEmpty" << endl;
	if (stack.isEmpty()) {
		cout << "stack empty. Test successfull\n" << endl;
	}
	else {
		cout << "Stack not empty, test failed\n" << endl;
	}
}

void testRegularPush(Stack& stack)
{
	cout << "Testing method push" << endl;
	int num = 5;
	stack.push(num);
	cout << "Push function test successful\n\n" << endl;
}

void testRegularPop(Stack& stack)
{
	cout << "Testing method pop" << endl;
	int num = 5;
	int result = stack.pop();
	if (result == num) {
		cout << "Pop function test successful\n\n" << endl;
	}
	else {
		cout << "Pop function test failed\n\n" << endl;
	}
}

void testIsFull(Stack& stack)
{
	cout << "Testing isFull function" << endl;
	for (int i = 0; stack.getTop() < stack.getSize()-1; i++) {
		stack.push(i);
	}
	if (stack.isFull()) {
		cout << "Stack full, test successful\n\n";
	}
	else {
		cout << "Stack not full, test failed\n\n";
	}
}

void testOverlimitPush(Stack& stack)
{
	cout << "Testing push function over stack limit" << endl;
	for (int i = 0; i < INITIAL_SIZE * 2.; i++) {
		stack.push(i);
	}
	cout << "Overlimit push test successful, init size:" << INITIAL_SIZE<<" current size: "<<stack.getSize() <<"\n\n";
}

void testPushOverlimit(Stack& stack)
{
	cout << "Testing overlimit push. Program should receive error after this "
			"function is invoked:"
		 << endl;
	for (int i = 0; i < INITIAL_SIZE * 2; i++) {
		stack.pop();
	}
}
